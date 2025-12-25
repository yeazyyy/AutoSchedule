#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include <QFile>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = nullptr);
    ~ConfirmDialog();
    void save();
    QString getFrom();
    QString getTo();
    int getFontSize();
    int getHeightList();
    void setPlace(int place);

private slots:

private:
    Ui::ConfirmDialog *ui;

};

#endif // CONFIRMDIALOG_H
