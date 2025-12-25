#include "addgrouptypedialog.h"
#include "ui_addgrouptypedialog.h"

AddGroupTypeDialog::AddGroupTypeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGroupTypeDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить тип группы");

    ui->lineEditAddName->setFocus();
}

AddGroupTypeDialog::~AddGroupTypeDialog()
{
    delete ui;
}

QString AddGroupTypeDialog::getName(){
    return ui->lineEditAddName->text();
}

int AddGroupTypeDialog::getHours(){
    return ui->spinBox->value();
}
