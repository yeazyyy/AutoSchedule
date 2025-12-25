#ifndef ADDTRAININGDIALOG_H
#define ADDTRAININGDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>


namespace Ui {
class AddTrainingDialog;
}

class AddTrainingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTrainingDialog(QWidget *parent = nullptr);
    ~AddTrainingDialog();
    int getGroup();
    void setMaxRows(int max);
    QString getCommentary();
    int getRows();
    void setRows(int rows);
    void setGroup(int _id);
    void disableSpinBox();
    int getSwapCoach();

private:
    Ui::AddTrainingDialog *ui;
};

#endif // ADDTRAININGDIALOG_H
