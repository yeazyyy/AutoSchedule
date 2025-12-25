#ifndef EDITPUPILDIALOG_H
#define EDITPUPILDIALOG_H

#include <QDialog>
#include <QString.h>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class EditPupilDialog;
}

class EditPupilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPupilDialog(QWidget *parent = nullptr);
    ~EditPupilDialog();
    QString getName();
    int getRank();
    int getGroup();
    void setName(QString _name);
    void setRank(int _rank);
    void setGroup(int _group);

private:
    Ui::EditPupilDialog *ui;
};

#endif // EDITPUPILDIALOG_H
