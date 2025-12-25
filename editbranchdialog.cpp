#include "editbranchdialog.h"
#include "ui_editbranchdialog.h"

EditBranchDialog::EditBranchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditBranchDialog)
{
    ui->setupUi(this);
}

EditBranchDialog::~EditBranchDialog()
{
    delete ui;
}

void EditBranchDialog::setColor(QString color){
    ui->lineEdit_Color->setText(color);
}

QString EditBranchDialog::getColor(){
    return ui->lineEdit_Color->text();
}

void EditBranchDialog::setName(QString name){
    ui->lineEdit_AddName->setText(name);
}

QString EditBranchDialog::getName(){
    return ui->lineEdit_AddName->text();
}

void EditBranchDialog::on_pushButtonColor_clicked()
{
    QColorDialog* dialog = new QColorDialog (this);
    ui->lineEdit_Color->setText(dialog->getColor().name());
}

