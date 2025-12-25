#ifndef EDITORGANIZATIONSDIALOG_H
#define EDITORGANIZATIONSDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class EditOrganizationsDialog;
}

class EditOrganizationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditOrganizationsDialog(QWidget *parent = nullptr);
    ~EditOrganizationsDialog();
    QString getCoach();
    void setCoach(QString coach_id);

private:
    Ui::EditOrganizationsDialog *ui;
};

#endif // EDITORGANIZATIONSDIALOG_H
