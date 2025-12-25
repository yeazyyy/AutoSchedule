#include "addeventdialog.h"
#include "ui_addeventdialog.h"

AddEventDialog::AddEventDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEventDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить событие");

    ui->lineEdit->setFocus();
}

AddEventDialog::~AddEventDialog()
{
    delete ui;
}

QString AddEventDialog::getName(){
    return ui->lineEdit->text();
}
