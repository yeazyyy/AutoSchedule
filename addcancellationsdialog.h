#ifndef ADDCANCELLATIONSDIALOG_H
#define ADDCANCELLATIONSDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class AddCancellationsDialog;
}

class AddCancellationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCancellationsDialog(QWidget *parent = nullptr);
    ~AddCancellationsDialog();
    int getCoach();
    int getFrom();
    int getTo();
    bool getDelete();

protected:
    void changeEvent(QEvent * event) override;

private slots:
    void on_comboBox_From_currentTextChanged(const QString &arg1);
    void on_comboBox_To_currentTextChanged(const QString &arg1);

private:
    Ui::AddCancellationsDialog *ui;
    void fillFrom(int to);
    void fillTo(int from);
    QString days[7] = {
        tr("Понедельник"),
        tr("Вторник"),
        tr("Среда"),
        tr("Четверг"),
        tr("Пятница"),
        tr("Суббота"),
        tr("Воскресенье")
    };
    int flag = 0;
};

#endif // ADDCANCELLATIONSDIALOG_H
