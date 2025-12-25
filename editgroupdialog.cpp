#include "editgroupdialog.h"
#include "ui_editgroupdialog.h"
#include <QSqlError>

EditGroupDialog::EditGroupDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditGroupDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Изменить информацию о группе");

    ui->tableWidget_Pupils->setColumnCount(3);
    QStringList pupils_table_names;
    pupils_table_names << "id" << tr("ФИО") << tr("Ранг");
    ui->tableWidget_Pupils->setHorizontalHeaderLabels(pupils_table_names);
    ui->tableWidget_Pupils->hideColumn(0);
    ui->tableWidget_Pupils->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_Pupils->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Pupils->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());
    query->exec("SELECT id, name FROM Group_types ORDER BY id");
    while(query->next()){
        ui->comboBox_Group_type->addItem(query->value(1).toString(),query->value(0));
    }

    query->exec("SELECT id, name FROM Branches ORDER BY id");
    while(query->next()){
        ui->comboBox_Branch->addItem(query->value(1).toString() + "(" + query->value(0).toString() + ")", query->value(0));
    }

    query->exec("SELECT id, fullname FROM Coaches ORDER BY id");
    while(query->next()){
        ui->comboBox_Coach->addItem(query->value(1).toString(),query->value(0));
    }


}

void EditGroupDialog::setId(int id){
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT Pupils.id, Pupils.fullname, Ranks.name "
                "FROM Pupils "
                "JOIN Ranks ON Pupils.rank_id = Ranks.id "
                "WHERE Pupils.group_id = '"+QString::number(id)+"' "
                "ORDER BY Pupils.id");

    while(query->next()){
        int size = ui->tableWidget_Pupils->rowCount();
        ui->tableWidget_Pupils->insertRow(size);
        ui->tableWidget_Pupils->setItem(size, 0, new QTableWidgetItem(query->value(0).toString()));
        ui->tableWidget_Pupils->setItem(size, 1, new QTableWidgetItem(query->value(1).toString()));
        ui->tableWidget_Pupils->setItem(size, 2, new QTableWidgetItem(query->value(2).toString()));
    }
}

int EditGroupDialog::getGroupType(){
    return ui->comboBox_Group_type->currentData().toInt();
}
void EditGroupDialog::setGroupType(int group_type_id){
    ui->comboBox_Group_type->setCurrentIndex(ui->comboBox_Group_type->findData(group_type_id));
}
QDate EditGroupDialog::getDate(){
    return ui->dateEdit_Date->date();
}
void EditGroupDialog::setDate(QDate date){
    ui->dateEdit_Date->setDate(date);
}
int EditGroupDialog::getCoach(){
    return ui->comboBox_Coach->currentData().toInt();
}
void EditGroupDialog::setCoach(int coach_id){
    ui->comboBox_Coach->setCurrentIndex(ui->comboBox_Coach->findData(coach_id));
}
int EditGroupDialog::getBranch(){
    return ui->comboBox_Branch->currentData().toInt();
}
void EditGroupDialog::setBranch(int branch_id){
    ui->comboBox_Branch->setCurrentIndex(ui->comboBox_Branch->findData(branch_id));
}
int EditGroupDialog::getHierarchy(){
    return ui->spinBox_Hierarchy->value();
}
void EditGroupDialog::setHierarchy(int hierarchy){
    ui->spinBox_Hierarchy->setValue(hierarchy);
}

EditGroupDialog::~EditGroupDialog()
{
    delete ui;
}

void EditGroupDialog::on_comboBox_Group_type_currentTextChanged(const QString &arg1)
{
    if (arg1 == "УОР"){
        ui->spinBox_Hierarchy->setVisible(false);
    } else {
        ui->spinBox_Hierarchy->setVisible(true);
    }
}

