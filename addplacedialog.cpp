#include "addplacedialog.h"
#include "ui_addplacedialog.h"

AddPlaceDialog::AddPlaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlaceDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить место для проведения тренировок");

    ui->lineEdit_AddName->setFocus();
}

AddPlaceDialog::~AddPlaceDialog()
{
    delete ui;
}

QString AddPlaceDialog::getName(){
    return ui->lineEdit_AddName->text();
}

QString AddPlaceDialog::getOfset(){
    return QString::number(ui->spinBox_Ofset->value());
}

QString AddPlaceDialog::getAmount(){
    return QString::number(ui->spinBox_Amount->value());
}

QString AddPlaceDialog::getRows(){
    return QString::number(ui->spinBox_Rows->value());
}

QString AddPlaceDialog::getHeader(){
    return ui->lineEdit_Header->text();
}
