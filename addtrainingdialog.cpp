#include "addtrainingdialog.h"
#include "ui_addtrainingdialog.h"

AddTrainingDialog::AddTrainingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTrainingDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Назначить тренировку");

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());
    query->exec("SELECT Groups.id, Group_types.name, Coaches.fullname, COUNT(Trainings.id), Group_types.hours, "
               "Groups.branch_id, Groups.hierarchy, Organizations.name "
               "FROM Groups "
               "JOIN Group_types ON Groups.group_type_id = Group_types.id "
               "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
               "LEFT JOIN Trainings ON Trainings.group_id = Groups.id "
               "LEFT JOIN Organizations ON Groups.id = Organizations.group_id "
               "GROUP BY Groups.id, Group_types.name, Coaches.fullname, Group_types.hours, Groups.branch_id, Groups.hierarchy, Organizations.name "
               "ORDER BY Groups.id");

    while (query->next()){
        QString text = "";
        if (query->value(1).toString() == "Внешние"){
            text += query->value(7).toString() + " ";
        } else {
            text += query->value(1).toString();
            text += " ";
            if (query->value(6).toInt() != 0)
                text += "(" + query->value(5).toString() + "/" + query->value(6).toString() + ") ";
        }

        if (query->value(1).toString() != "Внешние")
            text += query->value(2).toString() + " ";

        text += query->value(3).toString() + "/" + query->value(4).toString();
        ui->comboBox_Group->addItem(text, query->value(0).toInt());
    }

    query->exec("SELECT* FROM Coaches");

    ui->comboBox_SwapCoach->addItem("", 0);

    while (query->next()){
    ui->comboBox_SwapCoach->addItem(query->value(1).toString(),query->value(0));
    }
}

AddTrainingDialog::~AddTrainingDialog()
{
    delete ui;
}

void AddTrainingDialog::setMaxRows(int max){
    ui->spinBox_Rows->setMaximum(max);
}

int AddTrainingDialog::getGroup(){
    return ui->comboBox_Group->currentData().toInt();
}

int AddTrainingDialog::getRows(){
    return ui->spinBox_Rows->value();
}

void AddTrainingDialog::setRows(int rows){
    ui->spinBox_Rows->setValue(rows);
}

QString AddTrainingDialog::getCommentary(){
    return ui->lineEdit_Commentary->text();
}

void AddTrainingDialog::setGroup(int _id){
    ui->comboBox_Group->setCurrentIndex(ui->comboBox_Group->findData(_id));
}

void AddTrainingDialog::disableSpinBox(){
    ui->spinBox_Rows->setVisible(false);
}

int AddTrainingDialog::getSwapCoach(){
    return ui->comboBox_SwapCoach->currentData().toInt();
}
