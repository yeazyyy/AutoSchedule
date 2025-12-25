#ifndef EDITBRANCHDIALOG_H
#define EDITBRANCHDIALOG_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class EditBranchDialog;
}

class EditBranchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditBranchDialog(QWidget *parent = nullptr);
    ~EditBranchDialog();
    QString getColor();
    void setColor(QString color);
    QString getName();
    void setName(QString name);

private slots:
    void on_pushButtonColor_clicked();

private:
    Ui::EditBranchDialog *ui;
};

#endif // EDITBRANCHDIALOG_H
