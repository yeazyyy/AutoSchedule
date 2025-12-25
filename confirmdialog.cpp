#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Утвердить расписание");

    ui->dateEdit_From->setDate(QDate::currentDate());
    ui->dateEdit_To->setDate(QDate::currentDate().addDays(7));

    QVector <QTextEdit*> vector;
    vector.push_back(ui->textEdit_Confirm);
    vector.push_back(ui->textEdit_FullName);
    vector.push_back(ui->textEdit_Worker);
    vector.push_back(ui->textEdit_WorkerFullName);

    int tmp = 0;

    QFile file("headers.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in (&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        if (line == "( ﾉ ﾟｰﾟ)ﾉ"){
            tmp++;
            continue;
        }
        vector.at(tmp)->append(line);
    }
    file.close();



}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}


void ConfirmDialog::save(){
    QFile file("headers.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }

    QTextStream out (&file);
    out << ui->textEdit_Confirm->toPlainText() << "\n( ﾉ ﾟｰﾟ)ﾉ\n";
    out << ui->textEdit_FullName->toPlainText() << "\n( ﾉ ﾟｰﾟ)ﾉ\n";
    out << ui->textEdit_Worker->toPlainText() << "\n( ﾉ ﾟｰﾟ)ﾉ\n";
    out << ui->textEdit_WorkerFullName->toPlainText();
    file.close();

}

QString ConfirmDialog::getFrom(){
    return ui->dateEdit_From->date().toString("dd.MM.yyyy");
}


QString ConfirmDialog::getTo(){
    return ui->dateEdit_To->date().toString("dd.MM.yyyy");
}

int ConfirmDialog::getFontSize(){
    return ui->spinBox_FontSize->value();
}

int ConfirmDialog::getHeightList(){
    return ui->spinBox_HeightList->value();
}

void ConfirmDialog::setPlace(int place){
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());
    query->exec("SELECT schedule_header FROM Place "
                "WHERE id = '"+QString::number(place)+"' ");
    query->next();
    ui->label_header->setText(query->value(0).toString());
}
