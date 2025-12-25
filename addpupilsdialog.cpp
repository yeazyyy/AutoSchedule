#include "addpupilsdialog.h"
#include "ui_addpupilsdialog.h"
#include <QSqlError>

AddPupilsDialog::AddPupilsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPupilsDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Зарегистрировать спортсмена");

    ui->lineEdit_AddName->setFocus();

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());
    query->exec("SELECT id, name FROM Ranks ORDER BY id");
    ui->comboBox_Rank->addItem("", 0);
    while(query->next()){
        ui->comboBox_Rank->addItem(query->value(1).toString(),query->value(0));
    }

    query->exec("SELECT Groups.id, Group_types.name "
                "FROM Groups "
                "INNER JOIN Group_types "
                "ON Groups.group_type_id = Group_types.id "
                "ORDER BY Groups.id");

    ui->comboBox_Group->addItem("", 0);
    while(query->next()){
        ui->comboBox_Group->addItem(query->value(1).toString(),query->value(0));
    }
}

AddPupilsDialog::~AddPupilsDialog()
{
    delete ui;
}

QString AddPupilsDialog::getName(){
    return ui->lineEdit_AddName->text();
}

int AddPupilsDialog::getRank(){
    return ui->comboBox_Rank->currentData().toInt();
}

int AddPupilsDialog::getGroup(){
    return ui->comboBox_Group->currentData().toInt();
}
