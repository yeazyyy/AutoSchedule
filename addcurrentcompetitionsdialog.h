#ifndef ADDCURRENTCOMPETITIONSDIALOG_H
#define ADDCURRENTCOMPETITIONSDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QTime>
#include <QShowEvent>

namespace Ui {
class AddCurrentCompetitionsDialog;
}

class AddCurrentCompetitionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCurrentCompetitionsDialog(QWidget *parent = nullptr);
    ~AddCurrentCompetitionsDialog();
    void setStarts(int _start_ofset, int _amount_of_starts);
    bool** getMatrix();
    QString getEvent();
    void setPlace(QString _place);

protected:
    //void showEvent(QShowEvent *event) override;

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::AddCurrentCompetitionsDialog *ui;
    void init();
    QGridLayout* grid;
    QSqlQuery* query;

    int columns = 9;

    int start_ofset = 0;
    int amount_of_starts = 0;
    bool** matrix;
    QString place = "0";
    QVector<QLabel*> labels;
};

#endif // ADDCURRENTCOMPETITIONSDIALOG_H
