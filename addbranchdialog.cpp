#include "addbranchdialog.h"
#include "ui_addbranchdialog.h"

AddBranchDialog::AddBranchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddBranchDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить вид спорта");

    ui->lineEdit_AddName->setFocus();
}

AddBranchDialog::~AddBranchDialog()
{
    delete ui;
}

QString AddBranchDialog::getName(){
    return ui->lineEdit_AddName->text();
}

QString AddBranchDialog::getColor(){
    return ui->lineEdit_Color->text();
}

void AddBranchDialog::on_pushButtonColor_clicked()
{
    QColorDialog* dialog = new QColorDialog (this);
    ui->lineEdit_Color->setText(dialog->getColor().name());
    // if(dialog->exec() == QDialog::Accepted){
    // }

}

