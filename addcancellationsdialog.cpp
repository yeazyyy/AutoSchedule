#include "addcancellationsdialog.h"
#include "ui_addcancellationsdialog.h"

AddCancellationsDialog::AddCancellationsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCancellationsDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Отменить тренировки");

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT id, fullname FROM Coaches ORDER BY id");
    while(query->next()){
        ui->comboBox_Coach->addItem(query->value(1).toString(),query->value(0));
    }

    fillFrom(7);
    fillTo(1);
    flag = 1;
}

AddCancellationsDialog::~AddCancellationsDialog()
{
    delete ui;
}

void AddCancellationsDialog::fillFrom(int to){
    flag = 0;
    if (ui->comboBox_From->count() != 0)
    ui->comboBox_From->clear();
    for (int i = 0; i < to; ++i) {
        ui->comboBox_From->addItem(days[i],i+1);
    }
    flag = 1;
}

void AddCancellationsDialog::fillTo(int from){
    flag = 0;
    if (ui->comboBox_To->count() != 0)
    ui->comboBox_To->clear();
    for (int i = from - 1; i < 7; ++i) {
        ui->comboBox_To->addItem(days[i],i+1);
    }
    flag = 1;
}

void AddCancellationsDialog::on_comboBox_From_currentTextChanged(const QString &arg1)
{
    if (flag == 1)
    fillTo(ui->comboBox_From->currentData().toInt());
}


void AddCancellationsDialog::on_comboBox_To_currentTextChanged(const QString &arg1)
{
    //if (flag == 1)
    //fillFrom(ui->comboBox_To->currentData().toInt());
}

int AddCancellationsDialog::getCoach(){
    return ui->comboBox_Coach->currentData().toInt();
}

int AddCancellationsDialog::getFrom(){
    return ui->comboBox_From->currentData().toInt();
}

int AddCancellationsDialog::getTo(){
    return ui->comboBox_To->currentData().toInt();
}

bool AddCancellationsDialog::getDelete(){
    return ui->checkBox_Delete->isChecked();
}

void AddCancellationsDialog::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}
