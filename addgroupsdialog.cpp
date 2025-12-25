#include "addgroupsdialog.h"
#include "ui_addgroupsdialog.h"

AddGroupsDialog::AddGroupsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGroupsDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить группу");

    ui->lineEdit_OrganizationName->setVisible(false);
    ui->dateEdit_Date->setDate(QDate::currentDate());

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

AddGroupsDialog::~AddGroupsDialog()
{
    delete ui;
}

int AddGroupsDialog::getName(){
    return ui->comboBox_Group_type->currentData().toInt();
}

int AddGroupsDialog::getBranch(){
    return ui->comboBox_Branch->currentData().toInt();
}

int AddGroupsDialog::getCoach(){
    return ui->comboBox_Coach->currentData().toInt();
}

QDate AddGroupsDialog::getDate(){
    return ui->dateEdit_Date->date();
}

int AddGroupsDialog::getHierarchy(){
    return ui->spinBox_Hierarchy->value();
}

QString AddGroupsDialog::getOrganizationName(){
    return ui->lineEdit_OrganizationName->text();
}

void AddGroupsDialog::on_comboBox_Group_type_currentTextChanged(const QString &arg1)
{
    if (arg1 == "УОР" || arg1 == "ПГ"){
        ui->lineEdit_OrganizationName->setVisible(false);
        ui->comboBox_Branch->setVisible(true);
        ui->comboBox_Coach->setVisible(true);
        ui->spinBox_Hierarchy->setVisible(false);
        ui->label_br->setVisible(true);
        ui->label_c->setVisible(true);
        ui->label_h->setVisible(false);
    } else if (arg1 == "Внешние"){
        ui->lineEdit_OrganizationName->setVisible(true);
        ui->comboBox_Branch->setVisible(false);
        ui->comboBox_Coach->setVisible(false);
        ui->spinBox_Hierarchy->setVisible(false);
        ui->label_br->setVisible(false);
        ui->label_c->setVisible(false);
        ui->label_h->setVisible(false);
    } else {
        ui->lineEdit_OrganizationName->setText("");
        ui->lineEdit_OrganizationName->setVisible(false);
        ui->comboBox_Branch->setVisible(true);
        ui->comboBox_Coach->setVisible(true);
        ui->spinBox_Hierarchy->setVisible(true);
        ui->label_br->setVisible(true);
        ui->label_c->setVisible(true);
        ui->label_h->setVisible(true);
    }
}


void AddGroupsDialog::on_comboBox_Branch_currentTextChanged(const QString &arg1)
{
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT MAX(hierarchy) FROM Groups "
                "WHERE branch_id = '"+ui->comboBox_Branch->currentData().toString()+"' "
                                                                  "GROUP BY branch_id");
    query->next();
    ui->spinBox_Hierarchy->setValue(query->value(0).toInt() + 1);
}

