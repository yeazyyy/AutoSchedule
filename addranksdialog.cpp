#include "addranksdialog.h"
#include "ui_addranksdialog.h"

AddRanksDialog::AddRanksDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRanksDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить разряд для спортсменов");

    ui->lineEdit_AddName->setFocus();
}

AddRanksDialog::~AddRanksDialog()
{
    delete ui;
}

QString AddRanksDialog::getName(){
    return ui->lineEdit_AddName->text();
}
