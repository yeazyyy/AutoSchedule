#ifndef EDITGROUPDIALOG_H
#define EDITGROUPDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>

namespace Ui {
class EditGroupDialog;
}

class EditGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditGroupDialog(QWidget *parent = nullptr);
    ~EditGroupDialog();
    void setId(int id);
    int getGroupType();
    void setGroupType(int group_type_id);
    QDate getDate();
    void setDate(QDate date);
    int getCoach();
    void setCoach(int coach_id);
    int getBranch();
    void setBranch(int branch_id);
    int getHierarchy();
    void setHierarchy(int hierarchy);

private slots:
    void on_comboBox_Group_type_currentTextChanged(const QString &arg1);

private:
    Ui::EditGroupDialog *ui;
};

#endif // EDITGROUPDIALOG_H
