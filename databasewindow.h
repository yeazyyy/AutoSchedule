#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QTableView>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QDate>
#include <QSqlRelationalDelegate>
#include <QCloseEvent>
#include <QShowEvent>

#include "addranksdialog.h"
#include "addbranchdialog.h"
#include "addplacedialog.h"
#include "addgrouptypedialog.h"
#include "addcoachdialog.h"
#include "addgroupsdialog.h"
#include "addpupilsdialog.h"
#include "addtimedialog.h"
#include "addeventdialog.h"
#include "editpupildialog.h"
#include "editgroupdialog.h"
#include "organizationswindow.h"
#include "editorganizationsdialog.h"
#include "editbranchdialog.h"

namespace Ui {
class DatabaseWindow;
}

class DatabaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseWindow(QWidget *parent = nullptr);
    ~DatabaseWindow();

protected:
    void changeEvent(QEvent * event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_Home_clicked();

    void on_pushButton_Organizations_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::DatabaseWindow *ui;
    void deleteElement(QTableView* table, QSqlTableModel* model);
    void selectPupils();
    void selectGroups();
    void selectBranches();
    OrganizationsWindow* orgWin;
    void closeEvent(QCloseEvent* event); // x

signals:
    void goHome();
};

#endif // DATABASEWINDOW_H
