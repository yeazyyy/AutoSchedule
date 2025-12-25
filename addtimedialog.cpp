#include "addtimedialog.h"
#include "ui_addtimedialog.h"

AddTimeDialog::AddTimeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTimeDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Назначить время тренировки");
}

AddTimeDialog::~AddTimeDialog()
{
    delete ui;
}

QString AddTimeDialog::getTime(){
    return ui->timeEdit_Time->text();
}
