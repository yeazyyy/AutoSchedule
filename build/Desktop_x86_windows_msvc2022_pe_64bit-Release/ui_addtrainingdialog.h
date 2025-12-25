/********************************************************************************
** Form generated from reading UI file 'addtrainingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRAININGDIALOG_H
#define UI_ADDTRAININGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddTrainingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_Group;
    QSpinBox *spinBox_Rows;
    QLineEdit *lineEdit_Commentary;
    QComboBox *comboBox_SwapCoach;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddTrainingDialog)
    {
        if (AddTrainingDialog->objectName().isEmpty())
            AddTrainingDialog->setObjectName("AddTrainingDialog");
        AddTrainingDialog->resize(354, 255);
        buttonBox = new QDialogButtonBox(AddTrainingDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(60, 210, 281, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_Group = new QComboBox(AddTrainingDialog);
        comboBox_Group->setObjectName("comboBox_Group");
        comboBox_Group->setGeometry(QRect(20, 40, 231, 31));
        spinBox_Rows = new QSpinBox(AddTrainingDialog);
        spinBox_Rows->setObjectName("spinBox_Rows");
        spinBox_Rows->setGeometry(QRect(280, 40, 48, 29));
        spinBox_Rows->setMinimum(1);
        lineEdit_Commentary = new QLineEdit(AddTrainingDialog);
        lineEdit_Commentary->setObjectName("lineEdit_Commentary");
        lineEdit_Commentary->setGeometry(QRect(20, 160, 231, 31));
        comboBox_SwapCoach = new QComboBox(AddTrainingDialog);
        comboBox_SwapCoach->setObjectName("comboBox_SwapCoach");
        comboBox_SwapCoach->setGeometry(QRect(20, 110, 231, 31));
        label = new QLabel(AddTrainingDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 131, 20));
        label_2 = new QLabel(AddTrainingDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 0, 71, 41));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(AddTrainingDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 261, 21));

        retranslateUi(AddTrainingDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddTrainingDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddTrainingDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTrainingDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTrainingDialog)
    {
        AddTrainingDialog->setWindowTitle(QCoreApplication::translate("AddTrainingDialog", "Dialog", nullptr));
        comboBox_Group->setPlaceholderText(QString());
        lineEdit_Commentary->setPlaceholderText(QCoreApplication::translate("AddTrainingDialog", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        label->setText(QCoreApplication::translate("AddTrainingDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("AddTrainingDialog", "\320\224\320\276\321\200\320\276\320\266\320\272\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("AddTrainingDialog", "\320\227\320\260\320\274\320\265\320\275\320\260 \321\202\321\200\320\265\320\275\320\265\321\200\320\260 (\320\265\321\201\320\273\320\270 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTrainingDialog: public Ui_AddTrainingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRAININGDIALOG_H
