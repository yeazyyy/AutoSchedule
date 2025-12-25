#ifndef ADDCOACHDIALOG_H
#define ADDCOACHDIALOG_H

#include <QDialog>

namespace Ui {
class AddCoachDialog;
}

class AddCoachDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCoachDialog(QWidget *parent = nullptr);
    ~AddCoachDialog();
    QString getName();

private:
    Ui::AddCoachDialog *ui;
};

#endif // ADDCOACHDIALOG_H
