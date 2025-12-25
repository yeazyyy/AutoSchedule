#include "addcurrentcompetitionsdialog.h"
#include "ui_addcurrentcompetitionsdialog.h"

AddCurrentCompetitionsDialog::AddCurrentCompetitionsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCurrentCompetitionsDialog)
{
    ui->setupUi(this);

    //setWindowTitle("Назначить событие");
}

AddCurrentCompetitionsDialog::~AddCurrentCompetitionsDialog()
{
    delete ui;
}

void AddCurrentCompetitionsDialog::setStarts(int _start_ofset, int _amount_of_starts){
    start_ofset = _start_ofset;
    amount_of_starts = _amount_of_starts;

    matrix = new bool*[amount_of_starts];
    for (int i = 0; i < amount_of_starts; ++i) {
        matrix[i] = new bool[7];
    }
    for (int i = 0; i < amount_of_starts; ++i) {
        for (int j = 0; j < 7; ++j) {
            matrix[i][j] = false;
        }
    }
    init();
}

bool** AddCurrentCompetitionsDialog::getMatrix(){
    return matrix;
}

QString AddCurrentCompetitionsDialog::getEvent(){
    return ui->comboBox->currentData().toString();
}

void AddCurrentCompetitionsDialog::init(){
    query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT* FROM Events");
    while(query->next()){
        ui->comboBox->addItem(query->value(1).toString(),query->value(0));
    }

    ui->scrollArea->setObjectName("myObject");
    ui->scrollArea->setStyleSheet("#myObject{ border: 2px solid grey; padding: 0px;}");
    QWidget * scrollWidget = new QWidget(ui->scrollArea);

    grid = new QGridLayout(scrollWidget);
    grid->setHorizontalSpacing(0);
    grid->setVerticalSpacing(0);
    grid->setContentsMargins(0,0,0,0);

    for (int i = 0; i < amount_of_starts+1; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid->setColumnMinimumWidth(j,30);
            QFrame * frame = new QFrame;
            if(j < 2)
                frame->setMaximumWidth(100);

            frame->setObjectName("myObject");
            frame->setStyleSheet("#myObject { border: 2px solid grey; padding: 0px;}");
            //QVBoxLayout * vL = new QVBoxLayout(frame);
            grid->addWidget(frame,i,j);
        }
    }

    grid->setColumnMinimumWidth(0,60);
    grid->setColumnMinimumWidth(1,60);
    grid->setRowMinimumHeight(0,20);

    QStringList names;
    names << tr("Пуск") << tr("Время") << tr("ПН") << tr("ВТ") << tr("СР") << tr("ЧТ") << tr("ПТ") << tr("СБ") << tr("ВС");
    for (int j = 0; j < columns; ++j) {
        QVBoxLayout * vL = new QVBoxLayout();
        vL->setAlignment(Qt::AlignCenter);
        vL->setContentsMargins(2,2,2,2);
        QLabel * label = new QLabel();
        label->setText(names.takeAt(0));
        labels.push_back(label);
        vL->addWidget(label);
        grid->itemAtPosition(0,j)->widget()->setLayout(vL);
    }

    scrollWidget->setLayout(grid);
    ui->scrollArea->setWidget(scrollWidget);

    query->exec("SELECT* FROM Start_time");

    for (int i = 0; i < start_ofset + 1; ++i) {
        query->next();
    }

    for (int i = 1; i < amount_of_starts+1; ++i) {
        QVBoxLayout * vL = new QVBoxLayout();
        vL->setAlignment(Qt::AlignCenter);
        vL->setContentsMargins(2,2,2,2);
        QLabel * label = new QLabel();

        QTime base_time= QTime::fromString(query->value(1).toString(), "H:mm"); //get time from db with ofset
        query->next();
        label->setText(base_time.addSecs(-15*60).toString("H:mm"));
        vL->addWidget(label);
        grid->itemAtPosition(i,0)->widget()->setLayout(vL);

        QVBoxLayout * vL1 = new QVBoxLayout();
        vL1->setAlignment(Qt::AlignCenter);
        vL1->setContentsMargins(2,2,2,2);
        QLabel * label1 = new QLabel();
        label1->setText(base_time.toString("H:mm")+"-"+base_time.addSecs(45*60).toString("H:mm"));
        vL1->addWidget(label1);
        grid->itemAtPosition(i,1)->widget()->setLayout(vL1);

        // QVBoxLayout * vL2 = new QVBoxLayout();
        // vL2->setAlignment(Qt::AlignCenter);
        // vL2->setContentsMargins(2,2,2,2);
        // QLabel * label2 = new QLabel();
        // label2->setText("САНИТАРНЫЙ ДЕНЬ" + QString::number(i));
        // vL2->addWidget(label2);
        // grid->itemAtPosition(i,columns-1)->widget()->setLayout(vL2);
    }

    for (int i = 1; i < amount_of_starts+1; ++i) {
        for (int j = 2; j < columns; ++j) {
            QVBoxLayout* vL = new QVBoxLayout;
            vL->setAlignment(Qt::AlignCenter);
            QCheckBox* checkbox = new QCheckBox;
            connect(checkbox,&QCheckBox::clicked,this,[=](bool checked){
                matrix[i-1][j-2] = checked;
            });
            vL->addWidget(checkbox);
            grid->itemAtPosition(i,j)->widget()->setLayout(vL);
        }
    }
}

void AddCurrentCompetitionsDialog::setPlace(QString _place){
    place = _place;
    on_comboBox_currentTextChanged("");
}

void AddCurrentCompetitionsDialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (place == "0")
        return;



    for (int i = 1; i < amount_of_starts + 1; ++i) {
        for (int j = 2; j < 9; ++j) {
            QCheckBox* checkbox = (QCheckBox*) grid->itemAtPosition(i,j)->widget()->layout()->itemAt(0)->widget();
            checkbox->setChecked(false);
            checkbox->setEnabled(true);
        }
    }

    QSqlQuery* query_1 = new QSqlQuery(QSqlDatabase::database());
    query_1->exec("SELECT* FROM Current_events "
                  "WHERE place_id = '"+place+"' "
                  "AND event_id = '"+ui->comboBox->currentData().toString()+"'");

    while (query_1->next()){
        QCheckBox* checkbox = (QCheckBox*) grid->itemAtPosition(query_1->value("time_id").toInt() - start_ofset, query_1->value("day").toInt() + 1)->widget()->layout()->itemAt(0)->widget();
    checkbox->setChecked(true);
    checkbox->setEnabled(false);
    }


    query_1->exec("SELECT* FROM Current_events "
                  "WHERE place_id = '"+place+"' "
                  "AND event_id != '"+ui->comboBox->currentData().toString()+"'");

    while (query_1->next()){
        QCheckBox* checkbox = (QCheckBox*) grid->itemAtPosition(query_1->value("time_id").toInt() - start_ofset, query_1->value("day").toInt() + 1)->widget()->layout()->itemAt(0)->widget();
        checkbox->setEnabled(false);
    }
}

// void AddCurrentCompetitionsDialog::showEvent(QShowEvent *event)
// {
//     QWidget::showEvent(event);
//     QStringList names;

//     if (QApplication::instance()->property("language").toString().contains("ru")){
//         names << "Пуск" << "Время" << "ПН" << "ВТ" << "СР" << "ЧТ" << "ПТ" << "СБ" << "ВС";
//     } else if (QApplication::instance()->property("language").toString().contains("en")) {
//         names << "Start" << "Time" << "Mon" << "Tue" << "Wed" << "Thu" << "Fri" << "Sat" << "Sun";
//     }

//     for (int i = 0; i < 9; ++i) {
//         labels.at(i)->setText(names.takeAt(0));
//     }
// }
