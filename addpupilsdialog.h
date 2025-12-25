#ifndef ADDPUPILSDIALOG_H
#define ADDPUPILSDIALOG_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class AddPupilsDialog;
}

class AddPupilsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPupilsDialog(QWidget *parent = nullptr);
    ~AddPupilsDialog();
    QString getName();
    int getRank();
    int getGroup();

private:
    Ui::AddPupilsDialog *ui;
};

#endif // ADDPUPILSDIALOG_H
