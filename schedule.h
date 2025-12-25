#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>
#include <QCloseEvent>
#include <QShowEvent>
#include <QLabel>
#include <QTime>
#include <QScrollArea>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCalendar>
#include <QMessageBox>

#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>
#include <QTextTable>
#include <QTextTableFormat>
#include <QTextCharFormat>
#include <QTextBlockFormat>
#include <QTextFrameFormat>
#include <QProcess>
#include <QFile>
#include <QDesktopServices>
#include <QFont>
#include <QFontMetrics>
#include <QShowEvent>

#include "qgridlayout.h"
#include "addtrainingdialog.h"
#include "addcurrentcompetitionsdialog.h"
#include "confirmdialog.h"
#include "addcancellationsdialog.h"

namespace Ui {
class Schedule;
}

class Schedule : public QWidget
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

protected:
    void changeEvent(QEvent * event) override;

private slots:
    void on_pushButton_Home_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_AddEvent_clicked();
    void on_pushButton_Confirm_clicked();

    void on_pushButton_Cancellations_clicked();

private:
    Ui::Schedule *ui;
    void closeEvent(QCloseEvent* event); // x
    void showEvent(QShowEvent *event);

    QGridLayout* grid;
    QSqlQuery* query;
    int columns = 9;
    int flag = 0;
    int last_selected_group_id = 0;
    int last_selected_rows = 0;
    int last_selected_swap_id = 0;
    int** rows_matrix;
    int tmp = -1;

    int start_ofset = 0;
    int amount_of_starts = 0;
    int amount_of_rows = 0;

    void fillSchedule();
    void loadSchedule();
    void initScrollArea();
    void initDbData();
    void checkErrors();

    void generatePDF(QString file_name, QString from, QString to, int font_size, int maxPageHeight);
    void test();
    QVector<QLabel*> labels;


signals:
    void goHome();

};

#endif // SCHEDULE_H
