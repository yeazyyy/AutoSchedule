#include "schedule.h"
#include "ui_schedule.h"
#include <QSqlError>

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);

    //setWindowTitle("Расписание");

    initDbData();
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

void Schedule::on_pushButton_Home_clicked()
{
    this->close();
    emit goHome();
}

void Schedule::closeEvent(QCloseEvent *event){ // x
    event->ignore();
    emit goHome();
    event->accept();
}

void Schedule::initScrollArea()
{
    ui->scrollArea->setObjectName("myObject");
    ui->scrollArea->setStyleSheet("#myObject{ border: 2px solid grey; padding: 0px;}");
    QWidget * scrollWidget = new QWidget(ui->scrollArea);

    grid = new QGridLayout(scrollWidget);
    grid->setHorizontalSpacing(0);
    grid->setVerticalSpacing(0);
    grid->setContentsMargins(0,0,0,0);

    for (int i = 0; i < amount_of_starts+1; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid->setColumnMinimumWidth(j,150);
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
    names << "Пуск" << "Время" << "Понедельник" << "Вторник" << "Среда" << "Четверг" << "Пятница" << "Суббота" << "Воскресенье";
    labels.clear();
    for (int j = 0; j < columns; ++j) {
        QVBoxLayout * vL = new QVBoxLayout();
        vL->setAlignment(Qt::AlignCenter);
        vL->setContentsMargins(2,2,2,2);
        QLabel * label = new QLabel();
        label->setText(names.takeAt(0));
        labels.push_back(label);
        vL->addWidget(label);
        grid->itemAtPosition(0, j)->widget()->setLayout(vL);
    }

    scrollWidget->setLayout(grid);
    ui->scrollArea->setWidget(scrollWidget);
}

void Schedule::fillSchedule()
{
    query->exec("SELECT* FROM Start_time");

    for (int i = 0; i < start_ofset + 1; ++i) {
        query->next();
    }

    for (int i = 1; i < amount_of_starts + 1; ++i) {
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

    //grid->itemAtPosition(1,1)->widget()->layout()->takeAt(0); //delete

    for (int i = 1; i < amount_of_starts + 1; ++i) {
        grid->setRowMinimumHeight(i,100);
        for (int j = 2; j < columns; ++j) {

            QVBoxLayout * vL = new QVBoxLayout();
            vL->setAlignment(Qt::AlignTop);
            vL->setSpacing(1);
            vL->setContentsMargins(2,2,2,2);

            QPushButton * btn_plus = new QPushButton();
            btn_plus->setText("+");
            btn_plus->setProperty("day",j - 1);
            btn_plus->setProperty("time",i);

            connect(btn_plus, &QPushButton::clicked, this, [=](){
                //qDebug() << btn_plus->property("day").toInt() << btn_plus;

                //dialog with choise of group and amount of rows (setAvailableRows())

                AddTrainingDialog dialog(this);
                //calculate max value
                dialog.setMaxRows(rows_matrix[btn_plus->property("time").toInt() - 1][btn_plus->property("day").toInt() - 1]);
                if (ui->comboBox->currentData().toInt() > 2){
                    dialog.setMaxRows(1);
                    dialog.disableSpinBox();
                }
                if (last_selected_group_id != 0)
                    dialog.setGroup(last_selected_group_id);

                if(last_selected_rows != 0){
                    dialog.setRows(last_selected_rows);
                }

                if (dialog.exec() == QDialog::Accepted){
                    //write data to db
                    QString commentary = dialog.getCommentary();
                    int group = last_selected_group_id = dialog.getGroup();
                    int rows = last_selected_rows = dialog.getRows();
                    int swapCoach = last_selected_swap_id = dialog.getSwapCoach();
                    bool swap = true;

                    query->exec("SELECT coach_id, group_type_id FROM Groups WHERE id = '"+QString::number(group)+"' ");
                    query->next();
                    swap = swapCoach != 0 && ((query->value(1).toInt() != 21) && !(swapCoach == query->value(0).toInt()));

                    query->exec("SELECT Place.name "
                                "FROM Trainings "
                                "JOIN Place ON Trainings.place_id = Place.id "
                                "WHERE Trainings.group_id = '"+QString::number(group)+"' "
                                                           "AND Trainings.time_id = '"+QString::number(btn_plus->property("time").toInt() + start_ofset)+"' "
                                                                                                      "AND Trainings.day = '"+QString::number(btn_plus->property("day").toInt())+"'");

                    if (query->next()){
                        query->previous();
                        QString message;
                        while (query->next()){
                            message += "\n" + query->value(0).toString();
                        }
                        QMessageBox msgBox;
                        msgBox.setText("Эта группа уже имеет занятия в это время:" + message);
                        msgBox.exec();
                    }

                    tmp = rows_matrix[btn_plus->property("time").toInt() - 1][btn_plus->property("day").toInt() - 1] -= rows;
                    if (tmp == 0)
                        btn_plus->setEnabled(false);

                    if (rows != 0){
                        query->exec("INSERT INTO Trainings(day, time_id, group_id, amount_of_tracks, place_id, commentary) VALUES "
                                    "('"+btn_plus->property("day").toString()+"', '"+QString::number(btn_plus->property("time").toInt() + start_ofset)+"',"
                                                                                                                                                          "'"+QString::number(group)+"', '"+QString::number(rows)+"', '"+ui->comboBox->currentData().toString()+"',"
                                                                                                                                                  "'"+commentary+"')");

                        if (swap){
                            query->exec("SELECT id FROM Trainings ORDER BY id DESC LIMIT 1");
                            query->next();
                            query->exec("INSERT INTO Replacements (training_id, coach_id) VALUES "
                                        "('"+query->value(0).toString()+"', '"+QString::number(swapCoach)+"')");
                        }

                        query->exec("SELECT Trainings.id, Group_types.name, Coaches.fullname, Trainings.amount_of_tracks, "
                                    "Groups.branch_id, Groups.hierarchy, Branches.color, Trainings.group_id, Trainings.commentary, Swaps.fullname "
                                    "FROM Trainings "
                                    "JOIN Groups ON Trainings.group_id = Groups.id "
                                    "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                                    "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                                    "LEFT JOIN Branches ON Groups.branch_id = Branches.id "
                                    "LEFT JOIN Replacements ON Trainings.id = Replacements.training_id "
                                    "LEFT JOIN Coaches Swaps ON Replacements.coach_id = Swaps.id "
                                    "ORDER BY Trainings.id DESC LIMIT 1");
                        query->next();


                        QPushButton * btn_training = new QPushButton();
                        btn_training->setProperty("id",query->value(0));
                        btn_training->setContextMenuPolicy(Qt::CustomContextMenu);

                        if (query->value(1).toString() == "Внешние"){
                            int tmp_rows = query->value(3).toInt();
                            QSqlQuery* query_1 = new QSqlQuery(QSqlDatabase::database()); // org
                            query_1->exec("SELECT Organizations.name, Coaches.fullname "
                                          "FROM Organizations "
                                          "JOIN Groups ON Organizations.group_id = Groups.id "
                                          "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                                          "WHERE Organizations.group_id = '"+query->value(7).toString()+"' ");
                            query_1->next();
                            btn_training->setText((query_1->value(1).isNull()?"":query_1->value(1).toString() + " ") + query_1->value(0).toString() + " " + QString::number(tmp_rows) + "д.");
                        } else {
                            if (query->value(5).toInt() == 0){
                                btn_training->setText((query->value(9).isNull()?query->value(2).toString():query->value(9).toString()) + " " + query->value(1).toString() + " " + query->value(3).toString() + "д.");
                            } else {
                                btn_training->setText((query->value(9).isNull()?query->value(2).toString():query->value(9).toString()) + " " + query->value(1).toString() + " ("
                                                      + query->value(4).toString() + "/" + query->value(5).toString() + ") " + query->value(3).toString() + "д.");
                            }
                        }

                        if (ui->comboBox->currentData().toInt() > 2){
                            QStringList list = btn_training->text().split(" ");
                            list.pop_back();
                            btn_training->setText(list.join(" "));
                        }

                        if (query->value(8).toString() != ""){
                            btn_training->setText(btn_training->text() + " " + query->value(8).toString());
                        }

                        {
                            QString color = query->value(6).toString();
                            if (query->value(1).toString() == "ПГ") {
                                color = "#FFFF8D";//FFFF00
                            } else if (query->value(1).toString() == "НП-1 ПГ"){
                                color = "#FFAC8D";//7A2100
                            } else if (query->value(1).toString() == "Внешние"){
                                color = "#FF8DFF";//FF00FF
                            } else if (query->value(1).toString() == "УОР") {
                                color = "#C6FF8D";//99FF33
                            }

                            //btn_training->setStyleSheet("border: 2px solid #CF1F5F");
                            btn_training->setStyleSheet("border: 2px solid #A78CAC; background-color: " + color);
                        }

                        connect(btn_training,&QPushButton::clicked, this, [=](){
                            //edit dialog
                        });

                        //create right click listener to delete line
                        connect(btn_training, &QPushButton::customContextMenuRequested, this, [=](){
                            //delete training from db
                            query->exec("SELECT* FROM Trainings "
                                        "WHERE id = '"+btn_training->property("id").toString()+"'");
                            query->next();
                            rows_matrix[query->value("time_id").toInt() - start_ofset - 1][query->value("day").toInt() - 1]
                                += query->value("amount_of_tracks").toInt();
                            btn_plus->setEnabled(true);

                            query->exec("PRAGMA foreign_keys = ON");
                            query->exec("DELETE FROM Trainings WHERE id = '"+btn_training->property("id").toString()+"'");
                            btn_training->close();
                            checkErrors();
                        });

                        grid->itemAtPosition(btn_plus->property("time").toInt(), btn_plus->property("day").toInt() + 1)->widget()->layout()->addWidget(btn_training);

                        checkErrors();
                    }
                }});
            vL->addWidget(btn_plus);
            grid->itemAtPosition(i,j)->widget()->setLayout(vL);
        }
    }
}

void Schedule::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (flag == 0){

        query->exec("SELECT* FROM Place WHERE id = '"+ui->comboBox->currentData().toString()+"'");
        query->next();

        start_ofset = query->value("start_ofset").toInt();
        amount_of_starts = query->value("amount_of_starts").toInt();
        amount_of_rows = query->value("amount_of_rows").toInt();


        ui->scrollArea->takeWidget();
        loadSchedule();
    }
}

void Schedule::loadSchedule()
{
    initScrollArea();

    fillSchedule();

    rows_matrix = new int*[amount_of_starts];
    for (int i = 0; i < amount_of_starts; ++i) {
        rows_matrix[i] = new int[7];
    }
    for (int i = 0; i < amount_of_starts; ++i) {
        for (int j = 0; j < 7; ++j) {
            rows_matrix[i][j] = amount_of_rows;
        }
    }

    //load data from db
    query->exec("SELECT Trainings.id, Group_types.name, Coaches.fullname, Trainings.amount_of_tracks, "
                "Groups.branch_id, Groups.hierarchy, Trainings.day, Trainings.time_id, Branches.color, "
                "Trainings.group_id, Trainings.commentary, Swaps.fullname, Cancellations.id "
                "FROM Trainings "
                "JOIN Groups ON Trainings.group_id = Groups.id "
                "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                "LEFT JOIN Branches ON Groups.branch_id = Branches.id "
                "LEFT JOIN Replacements ON Trainings.id = Replacements.training_id "
                "LEFT JOIN Coaches Swaps ON Replacements.coach_id = Swaps.id "
                "LEFT JOIN Cancellations ON Trainings.id = Cancellations.training_id "
                "WHERE Trainings.place_id = '"+ui->comboBox->currentData().toString()+"'"
                                                           "ORDER BY Trainings.id");

    while (query->next()){
        QPushButton* btn_plus = (QPushButton*)(grid->itemAtPosition(query->value(7).toInt() - start_ofset, query->value(6).toInt() + 1)->widget()->layout()->itemAt(0)->widget());

        QPushButton * btn_training = new QPushButton();
        btn_training->setProperty("id",query->value(0));
        btn_training->setContextMenuPolicy(Qt::CustomContextMenu);
        // if (!query->value(12).isNull()){
        //     btn_training->setStyleSheet("color: red;");
        // }

        if (query->value(1).toString() == "Внешние"){
            int tmp_rows = query->value(3).toInt();
            QSqlQuery* query_1 = new QSqlQuery(QSqlDatabase::database());
            query_1->exec("SELECT Organizations.name, Coaches.fullname "
                          "FROM Organizations "
                          "JOIN Groups ON Organizations.group_id = Groups.id "
                          "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                          "WHERE Organizations.group_id = '"+query->value(9).toString()+"' ");
            query_1->next();
            btn_training->setText((query_1->value(1).isNull()?"":query_1->value(1).toString() + " ") + query_1->value("name").toString() + " " + QString::number(tmp_rows) + "д.");

        } else
            if (query->value(5).toInt() == 0){
                btn_training->setText((query->value(11).isNull()?query->value(2).toString():query->value(11).toString()) + " " + query->value(1).toString() + " " + query->value(3).toString() + "д.");
            } else {
                btn_training->setText((query->value(11).isNull()?query->value(2).toString():query->value(11).toString()) + " " + query->value(1).toString() + " ("
                                      + query->value(4).toString() + "/" + query->value(5).toString() + ") " + query->value(3).toString() + "д.");
            }

            if (ui->comboBox->currentData().toInt() > 2){
                QStringList list = btn_training->text().split(" ");
                list.pop_back();
                btn_training->setText(list.join(" "));
            }

            if (query->value(10).toString() != ""){
                btn_training->setText(btn_training->text() + " " + query->value(10).toString());
            }

        {
            QString color = query->value(8).toString();
            if (query->value(1).toString() == "ПГ") {
                color = "#FFFF8D";//FFFF00
            } else if (query->value(1).toString() == "НП-1 ПГ"){
                color = "#FFAC8D";//7A2100
            } else if (query->value(1).toString() == "Внешние"){
                color = "#FF8DFF";//FF00FF
            } else if (query->value(1).toString() == "УОР") {
                color = "#C6FF8D";//99FF33
            }
            //btn_training->setStyleSheet("border: 2px solid " + color + ";" + (query->value(12).isNull()? "" : "color: red;"));
            btn_training->setStyleSheet("border: 2px solid #A78CAC; background-color: " + color + ";" + (query->value(12).isNull()? "" : "color: red;"));
            //btn_training->setStyleSheet("background-color: " + color + ";" + (query->value(12).isNull()? "" : "color: red;"));
        }

        tmp = rows_matrix[query->value(7).toInt() - start_ofset - 1][query->value(6).toInt() - 1] -= query->value(3).toInt();
        if (tmp == 0)
            btn_plus->setEnabled(false);

        connect(btn_training,&QPushButton::clicked, this, [=](){
            //edit dialog
        });

        //create right click listener to delete line
        connect(btn_training, &QPushButton::customContextMenuRequested, this, [=](){
            //delete training from db

            query->exec("SELECT* FROM Trainings "
                        "WHERE id = '"+btn_training->property("id").toString()+"'");
            query->next();
            rows_matrix[query->value("time_id").toInt() - start_ofset - 1][query->value("day").toInt() - 1]
                += query->value("amount_of_tracks").toInt();
            btn_plus->setEnabled(true);

            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Trainings WHERE id = '"+btn_training->property("id").toString()+"'");
            btn_training->close();
            checkErrors();
        });

        grid->itemAtPosition(query->value(7).toInt() - start_ofset, query->value(6).toInt() + 1)->widget()->layout()->addWidget(btn_training);
    }

    checkErrors();

    query->exec("SELECT Current_events.id, Events.name, Current_events.day, Current_events.time_id "
                "FROM Current_events "
                "JOIN Events ON Current_events.event_id = Events.id "
                "JOIN Place ON Current_events.place_id = Place.id "
                "AND Current_events.place_id = '"+ui->comboBox->currentData().toString()+"'");
    while (query->next()){
        QPushButton* btn_plus = (QPushButton*)(grid->itemAtPosition(query->value(3).toInt() - start_ofset, query->value(2).toInt() + 1)->widget()->layout()->itemAt(0)->widget());
        QPushButton* button_event = new QPushButton;
        button_event->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

        button_event->setProperty("id",query->value(0));
        button_event->setProperty("day",query->value(2));
        button_event->setProperty("time",query->value(3));
        button_event->setText(query->value(1).toString());
        button_event->setContextMenuPolicy(Qt::CustomContextMenu);

        connect(button_event, &QPushButton::customContextMenuRequested, this, [=](){
            //delete training from db
            rows_matrix[button_event->property("time").toInt() - start_ofset - 1][button_event->property("day").toInt() - 1] = amount_of_rows;
            btn_plus->setEnabled(true);

            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Current_events WHERE id = '"+button_event->property("id").toString()+"'");
            button_event->close();
        });

        grid->itemAtPosition(query->value(3).toInt() - start_ofset, query->value(2).toInt() + 1)->widget()->layout()->addWidget(button_event);
        rows_matrix[query->value(3).toInt() - start_ofset - 1][query->value(2).toInt() - 1] = 0;
        btn_plus->setEnabled(false);
    }
}

void Schedule::initDbData(){
    query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT* FROM Place");

    flag = 1;
    while (query->next()){
        ui->comboBox->addItem(query->value(1).toString(),query->value(0));
    }
    flag = 0;

    query->exec("SELECT* FROM Place ");
    query->next();
    start_ofset = query->value("start_ofset").toInt();
    amount_of_starts = query->value("amount_of_starts").toInt();
    amount_of_rows = query->value("amount_of_rows").toInt();
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(query->value("name").toString()));

    rows_matrix = new int*[amount_of_starts];
    for (int i = 0; i < amount_of_starts; ++i) {
        rows_matrix[i] = new int[7];
    }
    for (int i = 0; i < amount_of_starts; ++i) {
        for (int j = 0; j < 7; ++j) {
            rows_matrix[i][j] = amount_of_rows;
        }
    }
}


void Schedule::on_pushButton_AddEvent_clicked()
{
    AddCurrentCompetitionsDialog dialog(this);
    dialog.setStarts(start_ofset,amount_of_starts);

    dialog.setPlace(ui->comboBox->currentData().toString());

    if (dialog.exec() == QDialog::Accepted){
        bool** matrix = dialog.getMatrix();
        QString event = dialog.getEvent();
        for (int i = 0; i < amount_of_starts; ++i) {
            for (int j = 0; j < 7; ++j) {
                QPushButton* btn_plus = (QPushButton*)(grid->itemAtPosition(i + 1, j + 2)->widget()->layout()->itemAt(0)->widget());
                if (matrix[i][j]){
                    //write logs
                    query->exec("SELECT Trainings.id, Group_types.name, Coaches.fullname, Trainings.amount_of_tracks, "
                                "Groups.branch_id, Groups.hierarchy, Branches.color, Trainings.group_id, Start_time.time "
                                "FROM Trainings "
                                "JOIN Groups ON Trainings.group_id = Groups.id "
                                "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                                "JOIN Start_time ON Trainings.time_id = Start_time.id "
                                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                                "LEFT JOIN Branches ON Groups.branch_id = Branches.id "
                                "WHERE Trainings.day = '"+QString::number(j + 1)+"' "
                                                           "AND Trainings.time_id = '"+QString::number(i + start_ofset + 1)+"'"
                                                                         "AND Trainings.place_id = '"+ui->comboBox->currentData().toString()+"'");
                    QStringList text;
                    text << tr("Следующие тренировки были отменены:");
                    while (query->next()) {
                        if (query->value(1).toString() == "Внешние"){
                            int tmp_rows = query->value(3).toInt();
                            QSqlQuery* query_1 = new QSqlQuery(QSqlDatabase::database()); // query_1 выбирает название ор-ги
                            query_1->exec("SELECT* FROM Organizations "
                                          "WHERE group_id = '"+query->value(7).toString()+"' ");
                            query_1->next();
                            text << (query_1->value("name").toString() + " (" + QString::number(tmp_rows) + tr("д.)"));

                        } else
                            if (query->value(5).toInt() == 0){
                            text << (query->value(2).toString() + " " + query->value(1).toString() + " " + query->value(3).toString() + tr("д."));
                            } else {
                                text <<(query->value(2).toString() + " " + query->value(1).toString() + " ("
                                         + query->value(4).toString() + "/" + query->value(5).toString() + ") " + query->value(3).toString() + tr("д."));
                            }
                    }
                    if (query->previous()){
                        QCalendar* calendar = new QCalendar;
                        text << calendar->standaloneWeekDayName(QLocale::Russian,j + 1) + " " + query->value(8).toString();
                        QString current_text = ui->textBrowser_2->toPlainText(); // логи сверху
                        ui->textBrowser_2->clear();
                        ui->textBrowser_2->setText(text.join("\n") + "\n-----------------------------\n" + current_text);
                    }

                    //delete all trainings in the day and time
                    query->exec("PRAGMA foreign_keys = ON");
                    query->exec("DELETE FROM Trainings "
                                "WHERE Trainings.day = '"+QString::number(j + 1)+"' "
                                                           "AND Trainings.time_id = '"+QString::number(i + start_ofset + 1)+"' "
                                                                         "AND Trainings.place_id = '"+ui->comboBox->currentData().toString()+"'");
                    checkErrors();

                    //close buttons


                    //add current events
                    query->exec("INSERT INTO Current_events(day,time_id,event_id,place_id) VALUES "
                                "('"+QString::number(j + 1)+"', '"+QString::number(i + start_ofset + 1)+"', "
                                                                                                           "'"+event+"', '"+ui->comboBox->currentData().toString()+"' )");

                    //add button
                    query->exec("SELECT Current_events.id, Events.name "
                                "FROM Current_events "
                                "JOIN Events ON Current_events.event_id = Events.id "
                                "JOIN Place ON Current_events.place_id = Place.id "
                                "WHERE Current_events.day = '"+QString::number(j + 1)+"' "
                                                           "AND Current_events.time_id = '"+QString::number(i + start_ofset + 1)+"' "
                                                                         "AND Current_events.place_id = '"+ui->comboBox->currentData().toString()+"' "
                                                                           "ORDER BY Current_events.id DESC LIMIT 1");
                    query->next();
                    QPushButton* button_event = new QPushButton;
                    button_event->setProperty("id",query->value(0));
                    button_event->setText(query->value(1).toString());
                    button_event->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

                    button_event->setContextMenuPolicy(Qt::CustomContextMenu);
                    connect(button_event, &QPushButton::customContextMenuRequested, this, [=](){
                        //delete training from db
                        rows_matrix[i][j] = amount_of_rows;
                        btn_plus->setEnabled(true);

                        query->exec("PRAGMA foreign_keys = ON");
                        query->exec("DELETE FROM Current_events WHERE id = '"+button_event->property("id").toString()+"'");
                        button_event->close();
                    });
                    int size = grid->itemAtPosition(i + 1, j + 2)->widget()->layout()->count()-1;
                    for (int k = 0; k < size; ++k) {
                        grid->itemAtPosition(i + 1, j + 2)->widget()->layout()->itemAt(k + 1)->widget()->close();
                    }
                    grid->itemAtPosition(i + 1, j + 2)->widget()->layout()->addWidget(button_event);
                    rows_matrix[i][j] = 0;
                    btn_plus->setEnabled(false);
                }
            }
        }
    }
}

void Schedule::checkErrors(){
    query->exec("SELECT Group_types.name, Coaches.fullname, COUNT(Trainings.id), Group_types.hours, "
                "Groups.branch_id, Groups.hierarchy, Groups.group_type_id "
                "FROM Groups "
                "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                "LEFT JOIN Trainings ON Trainings.group_id = Groups.id "
                "GROUP BY Group_types.name, Coaches.fullname, Group_types.hours, Groups.branch_id, Groups.hierarchy, Groups.group_type_id "
                "ORDER BY Trainings.id");
    ui->textBrowser->clear();

    while (query->next()){
        if (query->value(6).toInt() != 21 && query->value(6).toInt() != 23){
            if (query->value(2).toInt() > query->value(3).toInt()){
                QString current_text = ui->textBrowser->toPlainText(); // логи сверху
                ui->textBrowser->clear();
                ui->textBrowser->setText(query->value(1).toString() + " " + query->value(0).toString()
                                         + " (" + query->value(4).toString() + "/" + query->value(5).toString() + tr("): превышена норма часов")
                                         + "\n-----------------------------\n" + current_text);
            }
        }
    }
}


void Schedule::on_pushButton_Confirm_clicked()
{
    ConfirmDialog dialog(this);
    dialog.setPlace(ui->comboBox->currentData().toInt());
    if (dialog.exec() == QDialog::Accepted){
        dialog.save();
        QString from = dialog.getFrom();
        QString to = dialog.getTo();
        int fontSize = dialog.getFontSize();
        int maxPageHeight = dialog.getHeightList();
        generatePDF("schedule.pdf", from, to, fontSize, maxPageHeight);
    }
}


void Schedule::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    loadSchedule();
    //ui->comboBox->clear();


    QStringList names;

    if (QApplication::instance()->property("language").toString().contains("ru")){
        names << "Пуск" << "Время" << "Понедельник" << "Вторник" << "Среда" << "Четверг" << "Пятница" << "Суббота" << "Воскресенье";
    } else if (QApplication::instance()->property("language").toString().contains("en")) {
        names << "Start" << "Time" << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    }

    for (int j = 0; j < 9; ++j) {
        auto name = names.takeAt(0);
        name += '\0';
        labels[j]->setText(name);
    }
}

void Schedule::generatePDF(QString file_name, QString from, QString to, int font_size, int maxPageHeight){

    //loadSchedule();

    QFile file("headers.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in (&file);
    QString line;

    int currentPageHeight = 0;
    // cont int maxPageHeight = 720;//755

    QString html =
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<style>"
            "p {"
            "font-family: Calibri, sans-serif;"
            "height: 18px;"
            "margin: 5px;"
            "padding: 0px;"
            "font-size: 11px"
            "}"

            "br {"
            "margin: 0px;"
            "}"

            "html, body {"
            "margin: 0;"
            "padding: 0;"
            "}"

            "td {"
            "font-family: Calibri, sans-serif;"
            "border: 1px solid grey;"
            "padding: 0px;"
            "margin: 0px;"
            "width: 138px;"
            "text-align: center;"
            "font-size: "+QString::number(font_size)+"px"
            "}"

            "tr {"
            "page-break-inside: avoid;"
            "padding: 0px;"
            "margin: 0px;"
            "}"

            "table {"
            "page-break-inside: avoid;"
            "table-layout: fixed;"
            "}"
        "</style>"
        "<meta charset=\"utf-8\">"
        "<title>PDF Title</title>"
        "</head>"
        "<body>";
    //
    //html+= "<div style = \"height: 145px; width: 100%; background-color: red;\"></div>";

    currentPageHeight -= 1;
    while (!in.atEnd()){
        line = in.readLine();
        if (line == "( ﾉ ﾟｰﾟ)ﾉ")
            break;
        (currentPageHeight +=(18 + 2));
        html += "<p style = \"margin: 0px; float: right; text-align: left; width: 300px; \">";
        html += line;
        html += "</p><br>";
    }
    line = in.readLine();
    (currentPageHeight += 20);
    html += "<p style = \"margin: 0px; float: right; text-align: left; width: 300px;\">";
    html += "________________" + line;
    html += "</p><br>";

    (currentPageHeight += 20);
    html += "<p style =\"margin: 0px; float: right; text-align: left; width: 300px; \">";
    html += "c " + from + " по " + to;
    html += "</p><br>";

    // confirmed 99px first area
    in.readLine();
    //html += "</div>";
    //(currentPageHeight +=20);
    html += "<div align=center style = \"margin: 0px; padding: 0px; margin-top: 0px; font-size: 18px; height: 24px; font-weight: bold;\">";

    query->exec("SELECT schedule_header FROM Place "
                "WHERE id = '"+ui->comboBox->currentData().toString()+"'");
    query->next();
    currentPageHeight +=(24+2); // 2px ?
    html += query->value(0).toString() + "\n";

    html +="</div>";
    // confirmed 123px second area

    //  table
    int* amounts = new int[amount_of_starts];

    for (int i = 0; i < amount_of_starts; ++i) {
        amounts[i] = 0;
    }

    query->exec("SELECT time_id, MAX(count) "
                "FROM ("
                "SELECT time_id, COUNT(id) AS count "
                "FROM Trainings "
                "WHERE place_id = '"+ui->comboBox->currentData().toString()+"' "
                                                           "GROUP BY time_id, day "
                                                           ") AS test "
                                                           "GROUP BY time_id ");

    while (query->next()){
        amounts[query->value(0).toInt() - 1 - start_ofset] = query->value(1).toInt();
    }

    for (int i = 0; i < amount_of_starts; ++i) {
        amounts[i] = std::min(amounts[i] + 1, amount_of_rows);
    }

    html += "<table align=center style = \"border-collapse: collapse; width: 100% !important; margin: 0px;\">"; // border: 2px solid grey;
    //124px confirmed
    html += "<thead>";
    (currentPageHeight += 20); //hz
    html += "<tr>";
    for (int k = 0; k < 9; ++k) {
        if(k == 0)
            html += "<td style = \"text-align: center; border: 3px solid grey; border-bottom: 2px solid grey; width: 35px; height: 18px; \">"; //
        else if (k == 1)
            html += "<td style = \"text-align: center; border: 3px solid grey; border-bottom: 2px solid grey; width: 70px; height: 18px\">"; // border: 2px solid grey;
            else
            html += "<td style = \"text-align: center; border: 3px solid grey; border-bottom: 2px solid grey; height: 18px\">"; // border: 2px solid grey;

        html += ((QLabel*)(grid->itemAtPosition(0, k)->widget()->layout()->itemAt(0)->widget()))->text();
        html += "</td>";
    }
    //145px confirmed
    //qDebug() <<1111<< currentPageHeight;
    html += "</tr>";
    html += "</thead>";
    html += "<tbody>";

    int tmp = 0;
    QFont font ("Calibri", font_size);
    QFontMetrics fm (font);

    for (int i = 0; i < amount_of_starts; ++i) {
        bool* extraSpace = new bool[amounts[i]];
        for (int k = 0; k < amounts[i]; ++k) {
            extraSpace[k] = false;
        }

        for (int j = 2; j < 9; ++j) {
            int size = grid->itemAtPosition(i + 1, j)->widget()->layout()->count();
            for (int k = 1; k < size; ++k) {
                if (fm.horizontalAdvance(((QPushButton*)(grid->itemAtPosition(i + 1, j)->widget()->layout()->itemAt(k)->widget()))->text()) > 180) {
                    extraSpace[k - 1] = true;
                }
            }
        }

        int size = amounts[i];
        for (int k = 0; k < size; ++k) {
            if (extraSpace[k]){
                amounts[i]++;
            }
        }


        qDebug() << (currentPageHeight);
        if((currentPageHeight += amounts[i]*20) > maxPageHeight) // 22 20
        {
            currentPageHeight = 0;
            html+= "</tbody>";
            html+= "</table>";
            html += "<div style=\"page-break-before: always; margin: 0; padding: 0; width: 100%; height: 0px; background-color: red;\"></div>";

            html += "<table align=center style = \"border-collapse: collapse; width: 100% !important; margin: 0px;\">"; // border: 2px solid grey;
            // for (int k = 0; k < 9; ++k) {
            //     if(k ==0)
            //         html += "<td style = \"border: 2px solid grey; text-align: center; width: 35px\">";
            //     else if (k ==1)
            //         html += "<td style = \"border: 2px solid grey; text-align: center; width: 70px\">";
            //     else
            //         html += "<td style = \"border: 2px solid grey; text-align: center\">";

            //     html += ((QLabel*)(grid->itemAtPosition(0, k)->widget()->layout()->itemAt(0)->widget()))->text();
            //     html += "</td>";
            // }
            html+= "<tbody>";
        }
        html += "<tr>";
        html += "<td style = \"border: 3px solid grey; border-bottom: 2px solid grey;"
                "width: 35px; text-align: center\">";
        html += ((QLabel*)(grid->itemAtPosition(i + 1, 0)->widget()->layout()->itemAt(0)->widget()))->text();
        html += "</td>";
        html += "<td style = \"border: 3px solid grey; border-right: 2px solid grey; border-bottom: 2px solid grey;"
                "width: 70px; text-align: center\">";
        html += ((QLabel*)(grid->itemAtPosition(i + 1, 1)->widget()->layout()->itemAt(0)->widget()))->text();
        html += "</td>";



        for (int j = 2; j < 9; ++j) {
            html += "<td>";
                html += "<table style = \"border: 0px; border-collapse: collapse; height: "+ QString::number(amounts[i]*20)+"px !important;\">"; //20 16


            int size = grid->itemAtPosition(i + 1, j)->widget()->layout()->count();

            if (size == 1 && rows_matrix[i][j - 2] == 0){
                html += "<tr>";
                html += "<td style = \"border-bottom: 1px;\">";
                html += ((QPushButton*)(grid->itemAtPosition(i + 1, j)->widget()->layout()->itemAt(1)->widget()))->text();
                html += "</td>";
                html += "</tr>";
            }

            int tmp = 0;
            for (int k = 1; k < size; ++k) {
                tmp += amounts[i] / size;
                html += "<tr >";
                html += "<td >";
                html += ((QPushButton*)(grid->itemAtPosition(i + 1, j)->widget()->layout()->itemAt(k)->widget()))->text();
                html += "</td>";
                html += "</tr>";
            }
            if (ui->comboBox->currentData().toInt() < 3 && rows_matrix[i][j - 2] > 0){
                html += "<tr >";
                html += "<td >";
                html += tr("Свободное плавание ") + QString::number(rows_matrix[i][j - 2]) + tr("д.");
                html += "</td>";
                html += "</tr>";
            }
            if (ui->comboBox->currentData().toInt() == 9 && rows_matrix[i][j - 2] == 1){
                html += "<tr >";
                html += "<td >";
                html += tr("Семейное плавание");
                html += "</td>";
                html += "</tr>";
            }
            html += "</table>";
            html += "</td>";
        }
        html += "</tr>";
    }
    html += "</tbody>";
    html += "</table>";




    html += "<p style = \"margin: 0px; margin-top: 10px; float: left; text-align: left; width: 400px; font-weight: bold;\">";
    html += in.readLine();
    in.readLine();
    html += "</p>";

    html += "<p style = \"margin: 0px; margin-top: 10px; float: right; font-weight: bold;\">";
    html += in.readLine();
    html += "</p>";


    html += "</body>";
    html += "</html>";
    file.close();
    //qDebug() << html;

    QProcess htmlToPdf;
    htmlToPdf.setProgram("wkhtmltopdf/bin/wkhtmltopdf");

    htmlToPdf.setArguments({
        "--load-error-handling", "ignore",
        "--disable-smart-shrinking",
        "--orientation", "Landscape",
        "--margin-top", "5mm",
        "--margin-right", "5mm",
        "--margin-bottom", "5mm",
        "--margin-left", "5mm",
        "-", file_name
    });

    htmlToPdf.start();
    htmlToPdf.write(html.toUtf8());
    htmlToPdf.closeWriteChannel();

    if (!htmlToPdf.waitForFinished()) { // set outputs to textbrowser
        qWarning() << "Failed:" <<htmlToPdf.errorString();
    } else if (htmlToPdf.exitCode() != 0) {
        qWarning() << "Error:" << htmlToPdf.readAllStandardError();
    } else {
        qDebug() << "Styled PDF generated!";
    }
    QDesktopServices::openUrl(QUrl::fromLocalFile(file_name));
}

void Schedule::test(){
    int* amounts = new int[amount_of_starts];

    for (int i = 0; i < amount_of_starts; ++i) {
        amounts[i] = 0;
    }

    query->exec("SELECT time_id, MAX(count) "
                "FROM ("
                "SELECT time_id, COUNT(id) AS count "
                "FROM Trainings "
                "WHERE place_id = '"+ui->comboBox->currentData().toString()+"' "
                "GROUP BY time_id, day "
                                                           ") AS test "
                                                           "GROUP BY time_id ");

    while (query->next()){
        amounts[query->value(0).toInt() - 1 - start_ofset] = query->value(1).toInt();
    }

    for (int i = 0; i < amount_of_starts; ++i) {
        qDebug() << amounts[i];
    }
}

void Schedule::on_pushButton_Cancellations_clicked()
{
    AddCancellationsDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted){
        int coach = dialog.getCoach();
        int from = dialog.getFrom();
        int to = dialog.getTo();
        bool delete_automaticaly = dialog.getDelete();
        if (delete_automaticaly) {
            query->exec("SELECT Trainings.id, Group_types.name, Coaches.fullname, Trainings.amount_of_tracks, "
                        "Groups.branch_id, Groups.hierarchy, Branches.color, Trainings.group_id, Start_time.time, Trainings.day, Place.name "
                        "FROM Trainings "
                        "JOIN Groups ON Trainings.group_id = Groups.id "
                        "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                        "JOIN Start_time ON Trainings.time_id = Start_time.id "
                        "JOIN Place ON Trainings.place_id = Place.id "
                        "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                        "LEFT JOIN Branches ON Groups.branch_id = Branches.id "
                        "LEFT JOIN Replacements ON Trainings.id = Replacements.training_id "
                        "WHERE (Trainings.day BETWEEN '"+QString::number(from)+"' AND '"+QString::number(to)+"') "
                        "AND ((Replacements.id IS NOT NULL AND Replacements.coach_id = '"+QString::number(coach)+"') "
                        "OR (Groups.coach_id = '"+QString::number(coach)+"' AND Replacements.id IS NULL))");

            QStringList text;
            QCalendar* calendar = new QCalendar;
            text << tr("Следующие тренировки были отменены:");
            while (query->next()) {
                if (query->value(1).toString() == "Внешние"){
                    int tmp_rows = query->value(3).toInt();
                    QSqlQuery* query_1 = new QSqlQuery(QSqlDatabase::database()); // query_1 выбирает название ор-ги
                    query_1->exec("SELECT* FROM Organizations "
                                  "WHERE group_id = '"+query->value(7).toString()+"' ");
                    query_1->next();
                    text << ("\n" + query_1->value("name").toString() + " (" + QString::number(tmp_rows) + tr("д.) ") + calendar->standaloneWeekDayName(QLocale::Russian,query->value(9).toInt()) + " " + query->value(8).toString() + " " + query->value(10).toString());

                } else
                    if (query->value(5).toInt() == 0){
                    text << ("\n" + query->value(2).toString() + " " + query->value(1).toString() + " " + query->value(3).toString() + tr("д. ") + calendar->standaloneWeekDayName(QLocale::Russian,query->value(9).toInt()) + " " + query->value(8).toString() + " " + query->value(10).toString());
                    } else {
                        text <<("\n" + query->value(2).toString() + " " + query->value(1).toString() + " ("
                                 + query->value(4).toString() + "/" + query->value(5).toString() + ") " + query->value(3).toString() + tr("д. ") + calendar->standaloneWeekDayName(QLocale::Russian,query->value(9).toInt()) + " " + query->value(8).toString() + " " + query->value(10).toString());
                    }
            }
            if (query->previous()){
                QString current_text = ui->textBrowser_2->toPlainText(); // логи сверху
                ui->textBrowser_2->clear();
                ui->textBrowser_2->setText(text.join("\n") + "\n-----------------------------\n" + current_text);
            }

            query->exec("DELETE FROM Trainings "
                        "WHERE id IN ( "
                        "SELECT Trainings.id "
                        "FROM Trainings "
                        "JOIN Groups ON Trainings.group_id = Groups.id "
                        "LEFT JOIN Replacements ON Trainings.id = Replacements.training_id "
                        "WHERE (Trainings.day BETWEEN '"+QString::number(from)+"' AND '"+QString::number(to)+"') "
                        "AND ((Replacements.id IS NOT NULL AND Replacements.coach_id = '"+QString::number(coach)+"') "
                        "OR (Groups.coach_id = '"+QString::number(coach)+"' AND Replacements.id IS NULL)) "
                        ") ");

        } else {
            query->exec("INSERT OR IGNORE INTO Cancellations (training_id) "
                    "SELECT Trainings.id "
                    "FROM Trainings "
                    "JOIN Groups ON Trainings.group_id = Groups.id "
                    "LEFT JOIN Replacements ON Trainings.id = Replacements.training_id "
                    "WHERE (Trainings.day BETWEEN '"+QString::number(from)+"' AND '"+QString::number(to)+"') "
                    "AND ((Replacements.id IS NOT NULL AND Replacements.coach_id = '"+QString::number(coach)+"') "
                    "OR (Groups.coach_id = '"+QString::number(coach)+"' AND Replacements.id IS NULL))");
        }
    }
    loadSchedule();
}

