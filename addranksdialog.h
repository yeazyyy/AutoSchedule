#ifndef ADDRANKSDIALOG_H
#define ADDRANKSDIALOG_H

#include <QDialog>

namespace Ui {
class AddRanksDialog;
}

class AddRanksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRanksDialog(QWidget *parent = nullptr);
    ~AddRanksDialog();
    QString getName();

private:
    Ui::AddRanksDialog *ui;
};

#endif // ADDRANKSDIALOG_H
