#ifndef ADDPLACEDIALOG_H
#define ADDPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class AddPlaceDialog;
}

class AddPlaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlaceDialog(QWidget *parent = nullptr);
    ~AddPlaceDialog();
    QString getName();
    QString getOfset();
    QString getAmount();
    QString getRows();
    QString getHeader();


private:
    Ui::AddPlaceDialog *ui;
};

#endif // ADDPLACEDIALOG_H
