#ifndef ADDBRANCHDIALOG_H
#define ADDBRANCHDIALOG_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class AddBranchDialog;
}

class AddBranchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBranchDialog(QWidget *parent = nullptr);
    ~AddBranchDialog();
    QString getName();
    QString getColor();

private slots:
    void on_pushButtonColor_clicked();

private:
    Ui::AddBranchDialog *ui;
};

#endif // ADDBRANCHDIALOG_H
