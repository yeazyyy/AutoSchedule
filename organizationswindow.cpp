#include "organizationswindow.h"
#include "ui_organizationswindow.h"
#include <QSqlError>

OrganizationsWindow::OrganizationsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrganizationsWindow)
{
    ui->setupUi(this);

    //setWindowTitle("Внешние организации");

    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    ui->tableWidget_Organizations->setColumnCount(3);
    QStringList organizations_table_names;
    organizations_table_names << "id" << tr("Название организации") << tr("Тренер");
    ui->tableWidget_Organizations->setHorizontalHeaderLabels(organizations_table_names);
    ui->tableWidget_Organizations->hideColumn(0);
    ui->tableWidget_Organizations->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_Organizations->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Organizations->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget_Organizations->setContextMenuPolicy(Qt::CustomContextMenu);

    selectOrganizations();

    connect(ui->tableWidget_Organizations,&QTableWidget::customContextMenuRequested,this,[=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверждение"), tr("Вы уверены что хотите удалить данный элемент?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = ui->tableWidget_Organizations->selectedItems()[0]->row();
            QString id = ui->tableWidget_Organizations->item(row, 0)->text();
            query->exec("SELECT group_id FROM Organizations WHERE id = '"+id+"'");
            query->next();
            QString group_id = query->value(0).toString();
            //qDebug() << group_id;
            query->exec("PRAGMA foreign_keys = ON");
            query->exec("DELETE FROM Organizations WHERE id = '"+id+"'");
            query->exec("DELETE FROM Groups WHERE id = '"+group_id+"'");
            selectOrganizations();
        }
    });

    connect(ui->tableWidget_Organizations,&QTableWidget::cellDoubleClicked,this,[=](int row, int colomn){ // edit
        EditOrganizationsDialog dialog(this);
        QString id = ui->tableWidget_Organizations->item(row, 0)->text();

        query->exec("SELECT Groups.coach_id, Organizations.group_id "
                    "FROM Organizations "
                    "JOIN Groups ON Organizations.group_id = Groups.id "
                    "WHERE Organizations.id = '"+id+"'");
        query->next();

        QString group_id = query->value(1).toString();
        dialog.setCoach(query->value(0).toString());

        if (dialog.exec() == QDialog::Accepted){
            QString coach = dialog.getCoach();

            query->exec("UPDATE Groups SET coach_id = '"+coach+"' "
                                                                   "WHERE id = '"+group_id+"'");
            selectOrganizations();
        }});
}

OrganizationsWindow::~OrganizationsWindow()
{
    delete ui;
}

void OrganizationsWindow::selectOrganizations(){
    ui->tableWidget_Organizations->setRowCount(0);
    QSqlQuery* query = new QSqlQuery(QSqlDatabase::database());

    query->exec("SELECT Organizations.id, Organizations.name, Coaches.fullname, Groups.coach_id "
                "FROM Organizations "
                "JOIN Groups ON Organizations.group_id = Groups.id "
                "LEFT JOIN Coaches ON Groups.coach_id = Coaches.id "
                "ORDER BY Organizations.id");

    while(query->next()){
        int size = ui->tableWidget_Organizations->rowCount();
        ui->tableWidget_Organizations->insertRow(size);
        ui->tableWidget_Organizations->setItem(size, 0, new QTableWidgetItem(query->value(0).toString()));
        ui->tableWidget_Organizations->setItem(size, 1, new QTableWidgetItem(query->value(1).toString()));
        if (query->value(3).toInt() == 0) {
            // if (QApplication::instance()->property("language").toString().contains("ru")) {
            ui->tableWidget_Organizations->setItem(size, 2, new QTableWidgetItem(tr("Тренер не задан")));
            // } else if (QApplication::instance()->property("language").toString().contains("en")) {
            //     ui->tableWidget_Organizations->setItem(size, 2, new QTableWidgetItem("Coach not set"));
            // }
        } else {
            ui->tableWidget_Organizations->setItem(size, 2, new QTableWidgetItem(query->value(2).toString()));
        }
    }
}

void OrganizationsWindow::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    // setWindowTitle(tr("Внешние организации"));
    ui->tableWidget_Organizations->clear();
    selectOrganizations();

    if (QApplication::instance()->property("language").toString().contains("ru")) {
        QStringList organizations_table_names;
        organizations_table_names << "id" << "Название организации" << "Тренер";
        ui->tableWidget_Organizations->setHorizontalHeaderLabels(organizations_table_names);

    } else if (QApplication::instance()->property("language").toString().contains("en")) {
        QStringList organizations_table_names;
        organizations_table_names << "id" << "Organization" << "Coach";
        ui->tableWidget_Organizations->setHorizontalHeaderLabels(organizations_table_names);
    }
}

void OrganizationsWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

