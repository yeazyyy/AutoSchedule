#include "editorganizationsdialog.h"
#include "ui_editorganizationsdialog.h"

EditOrganizationsDialog::EditOrganizationsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditOrganizationsDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Изменить информацию о внешних организациях");

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT id, fullname FROM Coaches ORDER BY id");

    ui->comboBox_Coach->addItem("", "0");

    while(query->next()){
        ui->comboBox_Coach->addItem(query->value(1).toString(),query->value(0).toString());
    }

}

EditOrganizationsDialog::~EditOrganizationsDialog()
{
    delete ui;
}

QString EditOrganizationsDialog::getCoach(){
    return ui->comboBox_Coach->currentData().toString();
}

void EditOrganizationsDialog::setCoach(QString coach_id){
    ui->comboBox_Coach->setCurrentIndex(ui->comboBox_Coach->findData(coach_id));
}
