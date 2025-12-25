#ifndef ADDGROUPTYPEDIALOG_H
#define ADDGROUPTYPEDIALOG_H

#include <QDialog>

namespace Ui {
class AddGroupTypeDialog;
}

class AddGroupTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupTypeDialog(QWidget *parent = nullptr);
    ~AddGroupTypeDialog();
    QString getName();
    int getHours();

private:
    Ui::AddGroupTypeDialog *ui;
};

#endif // ADDGROUPTYPEDIALOG_H
