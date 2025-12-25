#ifndef ADDGROUPSDIALOG_H
#define ADDGROUPSDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDate>

namespace Ui {
class AddGroupsDialog;
}

class AddGroupsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupsDialog(QWidget *parent = nullptr);
    ~AddGroupsDialog();
    int getName();
    int getBranch();
    int getCoach();
    QDate getDate();
    int getHierarchy();
    QString getOrganizationName();

private slots:
    void on_comboBox_Group_type_currentTextChanged(const QString &arg1);

    void on_comboBox_Branch_currentTextChanged(const QString &arg1);

private:
    Ui::AddGroupsDialog *ui;
};

#endif // ADDGROUPSDIALOG_H
