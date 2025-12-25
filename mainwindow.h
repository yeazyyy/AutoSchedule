#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QTableWidget>
#include <QTranslator>
#include <QEvent>
#include "databasewindow.h"
#include "schedule.h"

// QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
// QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void setTitleBarColor(HWND hwnd, COLORREF color);

protected:
    void changeEvent(QEvent * event) override;

private slots:
    void on_pushButton_DBW_clicked();
    void on_pushButton_Schedule_clicked();
    void on_comboBox_changeLanguage_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    DatabaseWindow* dbw;
    Schedule* scheduleWindow;
    QTranslator* qtTranslator;
};
#endif // MAINWINDOW_H
