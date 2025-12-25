#include "editpupildialog.h"
#include "ui_editpupildialog.h"

EditPupilDialog::EditPupilDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPupilDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Изменить информацию о спортсмене");

    ui->lineEdit_EditPupil->setFocus();

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());
    query->exec("SELECT id, name FROM Ranks ORDER BY id");
    ui->comboBox_EditRank->addItem("", 0);
    while(query->next()){
        ui->comboBox_EditRank->addItem(query->value(1).toString(),query->value(0));
    }

    query->exec("SELECT Groups.id, Group_types.name "
                "FROM Groups "
                "INNER JOIN Group_types "
                "ON Groups.group_type_id = Group_types.id "
                "WHERE Groups.group_type_id != 21 "
                "ORDER BY Groups.id");

    ui->comboBox_EditGroup->addItem("", 0);
    while(query->next()){
        ui->comboBox_EditGroup->addItem(query->value(1).toString(),query->value(0));
    }

}

EditPupilDialog::~EditPupilDialog()
{
    delete ui;
}

QString EditPupilDialog::getName(){
    return ui->lineEdit_EditPupil->text();
}

int EditPupilDialog::getRank(){
    return ui->comboBox_EditRank->currentData().toInt();
}

int EditPupilDialog::getGroup(){
    return ui->comboBox_EditGroup->currentData().toInt();
}

void EditPupilDialog::setName(QString _name){
    ui->lineEdit_EditPupil->setText(_name);
}

void EditPupilDialog::setRank(int _rank){
    ui->comboBox_EditRank->setCurrentIndex(ui->comboBox_EditRank->findData(_rank));
}

void EditPupilDialog::setGroup(int _group){
    ui->comboBox_EditGroup->setCurrentIndex(ui->comboBox_EditGroup->findData(_group));
}
