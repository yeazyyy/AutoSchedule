#include "addcoachdialog.h"
#include "ui_addcoachdialog.h"

AddCoachDialog::AddCoachDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCoachDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Добавить тренера");

    ui->lineEditAddName->setFocus();
}

AddCoachDialog::~AddCoachDialog()
{
    delete ui;
}

QString AddCoachDialog::getName(){
    return ui->lineEditAddName->text();
}
