#include "databasewindow.h"
#include "ui_databasewindow.h"
#include <QSqlError>
#include <QTranslator>

DatabaseWindow::DatabaseWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);

    //setWindowTitle("База данных");

    orgWin = new OrganizationsWindow(this);
    orgWin->setVisible(false);
    orgWin->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::WindowSystemMenuHint);

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    QSqlTableModel* group_types_model = new QSqlTableModel;
    group_types_model->setTable("Group_types");
    group_types_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    group_types_model->select();
    group_types_model->setHeaderData(1, Qt::Horizontal, tr("Тип группы"));
    group_types_model->setHeaderData(2, Qt::Horizontal, tr("Часы в неделю"));


    ui->tableView_Group_types->setModel(group_types_model);
    ui->tableView_Group_types->hideColumn(0);
    ui->tableView_Group_types->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Group_types->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView_Group_types->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Group_types->setContextMenuPolicy(Qt::CustomContextMenu);


    QSqlTableModel* place_model = new QSqlTableModel;
    place_model->setTable("Place");
    place_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    place_model->select();
    place_model->setHeaderData(1, Qt::Horizontal, tr("Название"));
    place_model->setHeaderData(2, Qt::Horizontal, tr("Пропуск"));
    place_model->setHeaderData(3, Qt::Horizontal, tr("Количество сеансов"));
    place_model->setHeaderData(4, Qt::Horizontal, tr("Количество дорожек"));
    place_model->setHeaderData(5, Qt::Horizontal, tr("Заголовок для расписания"));

    ui->tableView_Place->setModel(place_model);
    ui->tableView_Place->hideColumn(0);
    ui->tableView_Place->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Place->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView_Place->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableView_Place->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tableView_Place->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->tableView_Place->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Place->setContextMenuPolicy(Qt::CustomContextMenu);


    QSqlTableModel* ranks_model = new QSqlTableModel;
    ranks_model->setTable("Ranks");
    ranks_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ranks_model->select();
    ranks_model->setHeaderData(1, Qt::Horizontal, tr("Название"));

    ui->tableView_Ranks->setModel(ranks_model);
    ui->tableView_Ranks->hideColumn(0);
    ui->tableView_Ranks->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Ranks->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Ranks->setContextMenuPolicy(Qt::CustomContextMenu);


    QSqlTableModel* coach_model = new QSqlTableModel;
    coach_model->setTable("Coaches");
    coach_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    coach_model->select();
    coach_model->setHeaderData(1, Qt::Horizontal, tr("ФИО"));

    ui->tableView_Coaches->setModel(coach_model);
    ui->tableView_Coaches->hideColumn(0);
    ui->tableView_Coaches->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Coaches->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Coaches->setContextMenuPolicy(Qt::CustomContextMenu);


    QSqlTableModel* time_model = new QSqlTableModel;
    time_model->setTable("Start_time");
    time_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    time_model->select();
    time_model->setHeaderData(1, Qt::Horizontal, tr("Время сеанса"));

    ui->tableView_Time->setModel(time_model);
    ui->tableView_Time->hideColumn(0);
    ui->tableView_Time->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Time->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Time->setContextMenuPolicy(Qt::CustomContextMenu);


    QSqlTableModel* event_model = new QSqlTableModel;
    event_model->setTable("Events");
    event_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    event_model->select();
    event_model->setHeaderData(1, Qt::Horizontal, tr("Название события"));

    ui->tableView_Events->setModel(event_model);
    ui->tableView_Events->hideColumn(0);
    ui->tableView_Events->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_Events->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_Events->setContextMenuPolicy(Qt::CustomContextMenu);


    // QSqlTableModel* branch_model = new QSqlTableModel;
    // branch_model->setTable("Branches");
    // branch_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    // branch_model->select();
    // branch_model->setHeaderData(1, Qt::Horizontal, tr("Подразделение"));

    // ui->tableView_Branches->setModel(branch_model);
    // //ui->tableView_Branches->hideColumn(0);
    // ui->tableView_Branches->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    // ui->tableView_Branches->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    // ui->tableView_Branches->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    // ui->tableView_Branches->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    // ui->tableView_Branches->setContextMenuPolicy(Qt::CustomContextMenu);


    ui->tableWidget_Branches->setColumnCount(3);
    QStringList branches_table_names;
    branches_table_names << "id" << "Вид спорта" << "Цвет";

    ui->tableWidget_Branches->setHorizontalHeaderLabels(branches_table_names);
    //ui->tableWidget_Branches->hideColumn(0);
    ui->tableWidget_Branches->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_Branches->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_Branches->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget_Branches->setContextMenuPolicy(Qt::CustomContextMenu);

    selectBranches();


    ui->tableWidget_Group->setColumnCount(5);
    QStringList group_table_names;
    group_table_names << "id" << "Тип группы" << "Дата образования" << "Тренер" << "Вид спорта (№ группы)";
    ui->tableWidget_Group->setHorizontalHeaderLabels(group_table_names);
    ui->tableWidget_Group->hideColumn(0);
    ui->tableWidget_Group->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_Group->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Group->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget_Group->setContextMenuPolicy(Qt::CustomContextMenu);

    selectGroups();


    ui->tableWidget_Pupils->setColumnCount(4);
    QStringList pupils_table_names;
    pupils_table_names << "id" << "ФИО" << "Ранг" << "Группа";
    ui->tableWidget_Pupils->setHorizontalHeaderLabels(pupils_table_names);
    ui->tableWidget_Pupils->hideColumn(0);
    ui->tableWidget_Pupils->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_Pupils->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Pupils->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget_Pupils->setContextMenuPolicy(Qt::CustomContextMenu);

    selectPupils();


    connect(ui->tableView_Group_types,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Group_types,group_types_model);});
    connect(ui->tableView_Place,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Place,place_model);});
    connect(ui->tableView_Ranks,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Ranks,ranks_model);});
    //connect(ui->tableView_Branches,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Branches,branch_model);});
    connect(ui->tableView_Coaches,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Coaches,coach_model);});
    connect(ui->tableView_Time,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Time,time_model);});
    connect(ui->tableView_Events,&QTableView::customContextMenuRequested,this,[=](){deleteElement(ui->tableView_Events,event_model);});

    connect(ui->tableWidget_Branches,&QTableWidget::customContextMenuRequested,this,[=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверждение"), tr("Вы уверены что хотите удалить данный элемент?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = ui->tableWidget_Branches->selectedItems()[0]->row();
            QString id = ui->tableWidget_Branches->item(row, 0)->text();
            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Branches WHERE id = '"+id+"'");
            query->exec("UPDATE Groups SET branch_id = 0 WHERE branch_id = '"+id+"'");
            selectBranches();
            selectGroups();
            selectPupils();
        } else {
            // nothing
        }
    });

    connect(ui->tableWidget_Group,&QTableWidget::customContextMenuRequested,this,[=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверждение"), tr("Вы уверены что хотите удалить данный элемент?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = ui->tableWidget_Group->selectedItems()[0]->row();
            QString id = ui->tableWidget_Group->item(row, 0)->text();
            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Groups WHERE id = '"+id+"'");
            query->exec("UPDATE Pupils SET group_id = 0 WHERE group_id = '"+id+"'");
            selectGroups();
            selectPupils();
        } else {
            // nothing
        }
    });

    connect(ui->tableWidget_Pupils,&QTableWidget::customContextMenuRequested,this,[=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверждение"), tr("Вы уверены что хотите удалить данный элемент?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = ui->tableWidget_Pupils->selectedItems()[0]->row();
            QString id = ui->tableWidget_Pupils->item(row, 0)->text();
            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Pupils WHERE id = '"+id+"'");
            selectPupils();
        } else {
            // nothing
        }
    });


    connect(ui->pushButton_AddGroupTypes,&QPushButton::clicked,this,[=](){
        AddGroupTypeDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            int hours = dialog.getHours();
            // check and insert data
            if (name != "" && hours > 0){
                query->exec("SELECT * FROM Group_types WHERE name = '"+name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Такой тип группы уже зарегистрирован в системе."));
                    msgBox.exec();
                    return;
                }
                QSqlRecord record = group_types_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("name", name);
                record.setValue("hours", hours);
                if (group_types_model->insertRecord(-1,record)){
                    group_types_model->submitAll();
                }
            }
        } else {
            //siu
        }});

    connect(ui->pushButton_AddRanks,&QPushButton::clicked,this,[=](){
        AddRanksDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            // check and insert data
            if (name != ""){
                query->exec("SELECT * FROM Ranks WHERE name = '"+name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Такой разряд уже зарегистрирован в системе."));
                    msgBox.exec();
                    return;
                }
                QSqlRecord record = ranks_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("name", name);
                if (ranks_model->insertRecord(-1,record)){
                    ranks_model->submitAll();
                }
            }
        }});

    connect(ui->pushButton_AddPlace,&QPushButton::clicked,this,[=](){
        AddPlaceDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            QString ofset = dialog.getOfset();
            QString amount = dialog.getAmount();
            QString rows = dialog.getRows();
            QString header = dialog.getHeader();
            if (name != ""){

                query->exec("SELECT * FROM Place WHERE name = '"+name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Это место уже зарегистрировано в системе."));
                    msgBox.exec();
                    return;
                }
                QSqlRecord record = place_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("name", name);
                record.setValue("start_ofset", ofset);
                record.setValue("amount_of_starts", amount);
                record.setValue("amount_of_rows", rows);
                record.setValue("schedule_header", header);
                if (place_model->insertRecord(-1,record)){
                    place_model->submitAll();
                }
            }
        } else {
            //siu
        }});

    connect(ui->pushButton_AddBranches,&QPushButton::clicked,this,[=](){
        AddBranchDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            QString color = dialog.getColor();
            if (name != ""){
                query->exec("SELECT * FROM Branches WHERE name = '"+name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Этот вид спорта уже зарегистрирован в системе."));
                    msgBox.exec();
                    return;
                }
                query->exec("INSERT INTO Branches (name, color) VALUES "
                            "('"+name+"', '"+color+"')");
                selectBranches();
            }
        }});

    connect(ui->pushButton_AddCoach,&QPushButton::clicked,this,[=](){
        AddCoachDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            // check and insert data
            if (name != ""){
                QSqlRecord record = coach_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("fullname", name);
                if (coach_model->insertRecord(-1,record)){
                    coach_model->submitAll();
                }
            }
        } else {
            //siu
        }});

    connect(ui->pushButton_AddTime,&QPushButton::clicked,this,[=](){
        AddTimeDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString time = dialog.getTime();
            // check and insert data
            if (time != "" && time != "0:00"){
                QSqlRecord record = time_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("time", time);
                if (time_model->insertRecord(-1,record)){
                    time_model->submitAll();
                }
            }
        } else {
            //siu
        }});

    connect(ui->pushButton_AddGroups,&QPushButton::clicked,this,[=](){
        AddGroupsDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            int name = dialog.getName();
            int branch = dialog.getBranch();
            int coach = dialog.getCoach();
            QDate date = dialog.getDate();
            int hierarchy = dialog.getHierarchy();
            QString organization_name = dialog.getOrganizationName();
            // check and insert data
            if (name == 21){
                query->exec("SELECT* FROM Organizations WHERE name = '"+organization_name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Организация с таким именем уже зарегистрирована."));
                    msgBox.exec();
                    return;
                }
                query->exec("INSERT INTO Groups(group_type_id,date_of_formation,coach_id,branch_id,hierarchy) VALUES"
                            "('"+QString::number(name)+"', '"+QDate::currentDate().toString(Qt::ISODate)+"', 0, 0, 0)");
                query->exec("SELECT id FROM Groups "
                            "ORDER BY id DESC LIMIT 1");
                query->next();
                query->exec("INSERT INTO Organizations(name,group_id) VALUES "
                            "('"+organization_name+"','"+query->value(0).toString()+"')");
                orgWin->selectOrganizations();
            } else {
                if (name != 0 && branch != 0 && coach != 0 && (name == 20 || name == 23 || hierarchy != 0)){
                    if (name == 20 || name == 23)
                        hierarchy = 0;

                    query->exec("SELECT* FROM Groups "
                                "WHERE branch_id = '"+QString::number(branch)+"' AND hierarchy = '"+QString::number(hierarchy)+"' "
                                                                                                                 "AND group_type_id != 20"
                                                                                                                 "AND group_type_id != 23");
                    if (query->next()){
                        QMessageBox msgBox;
                        msgBox.setText(tr("В этом виде спорта это место уже занято."));
                        msgBox.exec();
                        return;
                    }
                    query->exec("INSERT INTO Groups(group_type_id,date_of_formation,coach_id,branch_id,hierarchy) VALUES"
                                "('"+QString::number(name)+"', '"+date.toString(Qt::ISODate)+"', '"+QString::number(coach)+"',"
                                                                                                                                  "'"+QString::number(branch)+"', '"+QString::number(hierarchy)+"')");
                    selectGroups();
                } }
        } else {
            //siu
        }});

    connect(ui->pushButton_AddPupils,&QPushButton::clicked,this,[=](){
        AddPupilsDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            int rank = dialog.getRank();
            int group = dialog.getGroup();
            // check and insert data
            if (name != ""){
                query->exec("INSERT INTO Pupils (fullname,rank_id,group_id) VALUES "
                            "('"+name+"', '"+QString::number(rank)+"', '"+QString::number(group)+"')");
                selectPupils();
            }
        }

    });

    connect(ui->pushButton_AddEvent,&QPushButton::clicked,this,[=](){
        AddEventDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            // check and insert data
            if (name != ""){

                query->exec("SELECT * FROM Event WHERE name = '"+name+"'");
                if (query->next()){
                    QMessageBox msgBox;
                    msgBox.setText(tr("Это событие уже зарегистрировано в системе."));
                    msgBox.exec();
                    return;
                }
                QSqlRecord record = event_model->record();
                record.remove(record.indexOf("id"));
                record.setValue("name", name);
                if (event_model->insertRecord(-1,record)){
                    event_model->submitAll();
                }
            }
        } else {
            //siu
        }});



    connect(ui->tableWidget_Branches,&QTableWidget::cellDoubleClicked,this,[=](int row, int colomn){ // edit
        EditBranchDialog dialog(this);
        QString id = ui->tableWidget_Branches->item(row, 0)->text();
        query->exec("SELECT * FROM Branches WHERE id = '"+id+"'");
        query->next();
        dialog.setName(query->value(1).toString());
        dialog.setColor(query->value(2).toString());

        if (dialog.exec() == QDialog::Accepted){
            QString color = dialog.getColor();
            QString name = dialog.getName();

                query->exec("UPDATE Branches SET name = '"+name+"', color = '"+color+"' "
                " WHERE id = '"+id+"'");
                selectBranches();
        }});


    connect(ui->tableWidget_Group,&QTableWidget::cellDoubleClicked,this,[=](int row, int colomn){ // edit
        EditGroupDialog dialog(this);
        QString id = ui->tableWidget_Group->item(row, 0)->text();
        query->exec("SELECT * FROM Groups WHERE id = '"+id+"'");
        query->next();
        dialog.setId(query->value("id").toInt());
        dialog.setGroupType(query->value("group_type_id").toInt());
        dialog.setDate(QDate::fromString(query->value("date_of_formation").toString(),Qt::ISODate));
        dialog.setCoach(query->value("coach_id").toInt());
        dialog.setBranch(query->value("branch_id").toInt());
        dialog.setHierarchy(query->value("hierarchy").toInt());

        if (dialog.exec() == QDialog::Accepted){
            int group_type = dialog.getGroupType();
            QDate date = dialog.getDate();
            int coach = dialog.getCoach();
            int branch = dialog.getBranch();
            int hierarchy = dialog.getHierarchy();

            if (group_type != 0 && coach != 0 && branch != 0 && (group_type == 20 || group_type == 23 || hierarchy != 0)){
                if (group_type == 20 || group_type == 23)
                    hierarchy = 0;

                query->exec("UPDATE Groups SET group_type_id = '"+QString::number(group_type)+"', date_of_formation = '"+date.toString(Qt::ISODate)+"', "
                                                                                                                                                            "coach_id = '"+QString::number(coach)+"', branch_id = '"+QString::number(branch)+"', "
                                                                                                      "hierarchy= '"+QString::number(hierarchy)+"' WHERE id = '"+id+"'");
                selectGroups();
            }
        } else {
            // empty
        }});

    connect(ui->tableWidget_Pupils,&QTableWidget::cellDoubleClicked,this,[=](int row, int colomn){ // edit
        EditPupilDialog dialog(this);
        QString id = ui->tableWidget_Pupils->item(row, 0)->text();
        query->exec("SELECT fullname,rank_id,group_id FROM Pupils WHERE id = '"+id+"'");
        query->next();
        dialog.setName(query->value(0).toString());
        dialog.setRank(query->value(1).toInt());
        dialog.setGroup(query->value(2).toInt());

        if (dialog.exec() == QDialog::Accepted){
            QString name = dialog.getName();
            int rank = dialog.getRank();
            int group = dialog.getGroup();
            // check and insert data
            if (name != ""){
                query->exec("UPDATE Pupils SET fullname = '"+name+"', rank_id = '"+QString::number(rank)+"', "
                                                                                                                 "group_id = '"+QString::number(group)+"' WHERE id = '"+id+"'");
                selectPupils();
            }
        } else {
            // empty
        }});

}

void DatabaseWindow::selectBranches(){
    ui->tableWidget_Branches->setRowCount(0);
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT Branches.id, Branches.name, Branches.color "
                "FROM Branches "
                "ORDER BY Branches.id");

    while(query->next()){
        int size = ui->tableWidget_Branches->rowCount();
        ui->tableWidget_Branches->insertRow(size);
        ui->tableWidget_Branches->setItem(size, 0, new QTableWidgetItem(query->value(0).toString()));
        ui->tableWidget_Branches->setItem(size, 1, new QTableWidgetItem(query->value(1).toString()));
        ui->tableWidget_Branches->setItem(size, 2, new QTableWidgetItem(""));
        ui->tableWidget_Branches->item(size, 2)->setBackground(QBrush(QColor(query->value(2).toString())));
    }
}

void DatabaseWindow::selectGroups(){
    ui->tableWidget_Group->setRowCount(0);
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT Groups.id, Group_types.name, Groups.date_of_formation, Coaches.fullname, Branches.name, Groups.branch_id, Groups.hierarchy "
                "FROM Groups "
                "JOIN Group_types ON Groups.group_type_id = Group_types.id "
                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                "LEFT JOIN Branches ON Groups.branch_id = Branches.id "
                "WHERE Groups.group_type_id != 21 "
                "ORDER BY Groups.id");

    while(query->next()){
        int size = ui->tableWidget_Group->rowCount();
        ui->tableWidget_Group->insertRow(size);
        ui->tableWidget_Group->setItem(size, 0, new QTableWidgetItem(query->value(0).toString()));
        ui->tableWidget_Group->setItem(size, 1, new QTableWidgetItem(query->value(1).toString()));
        ui->tableWidget_Group->setItem(size, 2, new QTableWidgetItem(query->value(2).toString()));
        if (query->value(3).isNull()){
            ui->tableWidget_Group->setItem(size, 3, new QTableWidgetItem(tr("Тренер не назначен")));
        } else {
            ui->tableWidget_Group->setItem(size, 3, new QTableWidgetItem(query->value(3).toString()));
        }
        if (query->value(4).isNull()) {
            ui->tableWidget_Group->setItem(size, 4, new QTableWidgetItem(tr("Вид спорта не указан")));
        } else {
            if (query->value(1).toString() == "ПГ" || query->value(1).toString() == "УОР"){
                ui->tableWidget_Group->setItem(size, 4, new QTableWidgetItem(query->value(4).toString()));
            } else {
                ui->tableWidget_Group->setItem(size, 4, new QTableWidgetItem(query->value(4).toString() + " (" + query->value(5).toString()
                                                                             + "/" + query->value(6).toString() + ") "));
            }
        }
    }
}

void DatabaseWindow::selectPupils(){
    ui->tableWidget_Pupils->setRowCount(0);
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT Pupils.id, Pupils.fullname, Ranks.name, Group_types.name, Coaches.fullname, "
                "Groups.branch_id, Groups.hierarchy, Pupils.group_id, Pupils.rank_id "
                "FROM Pupils "
                "LEFT JOIN Ranks ON Pupils.rank_id = Ranks.id "
                "LEFT JOIN Groups ON Pupils.group_id = Groups.id "
                "LEFT JOIN Group_types ON Groups.group_type_id = Group_types.id "
                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                "ORDER BY Pupils.id");

    while(query->next()){
        int size = ui->tableWidget_Pupils->rowCount();
        ui->tableWidget_Pupils->insertRow(size);
        ui->tableWidget_Pupils->setItem(size, 0, new QTableWidgetItem(query->value(0).toString()));
        ui->tableWidget_Pupils->setItem(size, 1, new QTableWidgetItem(query->value(1).toString()));
        if (query->value(8).toInt() == 0){
            ui->tableWidget_Pupils->setItem(size, 2, new QTableWidgetItem(""));
        } else {
            ui->tableWidget_Pupils->setItem(size, 2, new QTableWidgetItem(query->value(2).toString()));
        }
        if (query->value(7).toInt()!=0){
            ui->tableWidget_Pupils->setItem(size, 3, new QTableWidgetItem(query->value(3).toString() + " (" + query->value(5).toString()
                                                                          + "/" + query->value(6).toString() + ") " + query->value(4).toString()));
        } else {
            ui->tableWidget_Pupils->setItem(size, 3, new QTableWidgetItem(tr("Группа не задана")));
        }
    }
}

void DatabaseWindow::deleteElement(QTableView* table, QSqlTableModel* model){
    if (table->selectionModel()->hasSelection()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверждение"), tr("Вы уверены что хотите удалить данный элемент?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = table->currentIndex().row();
            model->removeRow(row);
            model->select();
        }
    }
}

void DatabaseWindow::closeEvent(QCloseEvent *event){ // x
    event->ignore();
    emit goHome();
    event->accept();
}

DatabaseWindow::~DatabaseWindow()
{
    delete ui;
}

void DatabaseWindow::on_pushButton_Home_clicked()
{
    this->close();
    emit goHome();
}


void DatabaseWindow::on_pushButton_Organizations_clicked()
{
    orgWin->show();
}


void DatabaseWindow::on_tabWidget_currentChanged(int index)
{
    selectPupils();
    selectGroups();
}

void DatabaseWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
    //QMainWindow::changeEvent(event);
}

void DatabaseWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
        ui->tableView_Group_types->model()->setHeaderData(1, Qt::Horizontal, tr("Тип группы"));
        ui->tableView_Group_types->model()->setHeaderData(2, Qt::Horizontal, tr("Часы в неделю"));

        ui->tableView_Place->model()->setHeaderData(1, Qt::Horizontal, tr("Название"));
        ui->tableView_Place->model()->setHeaderData(2, Qt::Horizontal, tr("Пропуск"));
        ui->tableView_Place->model()->setHeaderData(3, Qt::Horizontal, tr("Количество сеансов"));
        ui->tableView_Place->model()->setHeaderData(4, Qt::Horizontal, tr("Количество дорожек"));
        ui->tableView_Place->model()->setHeaderData(5, Qt::Horizontal, tr("Заголовок для расписания"));

        ui->tableView_Ranks->model()->setHeaderData(1, Qt::Horizontal, tr("Название"));
        ui->tableView_Coaches->model()->setHeaderData(1, Qt::Horizontal, tr("ФИО"));
        ui->tableView_Time->model()->setHeaderData(1, Qt::Horizontal, tr("Время сеанса"));
        ui->tableView_Events->model()->setHeaderData(1, Qt::Horizontal, tr("Название события"));

        QStringList branches_table_names;
        branches_table_names << "id" << tr("Вид спорта") << tr("Цвет");
        ui->tableWidget_Branches->setHorizontalHeaderLabels(branches_table_names);

        QStringList group_table_names;
        group_table_names << "id" << tr("Тип группы") << tr("Дата образования") << tr("Тренер") << tr("Вид спорта (№ группы)");
        ui->tableWidget_Group->setHorizontalHeaderLabels(group_table_names);

        QStringList pupils_table_names;
        pupils_table_names << "id" << tr("ФИО") << tr("Ранг") << tr("Группа");
        ui->tableWidget_Pupils->setHorizontalHeaderLabels(pupils_table_names);

}

