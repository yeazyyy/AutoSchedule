#ifndef ORGANIZATIONSWINDOW_H
#define ORGANIZATIONSWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QShowEvent>
#include "editorganizationsdialog.h"

namespace Ui {
class OrganizationsWindow;
}

class OrganizationsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OrganizationsWindow(QWidget *parent = nullptr);
    ~OrganizationsWindow();
    void selectOrganizations();

protected:
    void showEvent(QShowEvent *event) override;
    void changeEvent(QEvent * event) override;

private:
    Ui::OrganizationsWindow *ui;
};

#endif // ORGANIZATIONSWINDOW_H
