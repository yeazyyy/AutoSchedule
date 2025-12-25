#ifndef ADDTIMEDIALOG_H
#define ADDTIMEDIALOG_H

#include <QDialog>

namespace Ui {
class AddTimeDialog;
}

class AddTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTimeDialog(QWidget *parent = nullptr);
    ~AddTimeDialog();
    QString getTime();

private:
    Ui::AddTimeDialog *ui;
};

#endif // ADDTIMEDIALOG_H
