/********************************************************************************
** Form generated from reading UI file 'addtimedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTIMEDIALOG_H
#define UI_ADDTIMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddTimeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTimeEdit *timeEdit_Time;
    QLabel *label;

    void setupUi(QDialog *AddTimeDialog)
    {
        if (AddTimeDialog->objectName().isEmpty())
            AddTimeDialog->setObjectName("AddTimeDialog");
        AddTimeDialog->resize(443, 112);
        buttonBox = new QDialogButtonBox(AddTimeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(90, 70, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        timeEdit_Time = new QTimeEdit(AddTimeDialog);
        timeEdit_Time->setObjectName("timeEdit_Time");
        timeEdit_Time->setGeometry(QRect(330, 20, 101, 31));
        label = new QLabel(AddTimeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 301, 31));

        retranslateUi(AddTimeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddTimeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddTimeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTimeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTimeDialog)
    {
        AddTimeDialog->setWindowTitle(QCoreApplication::translate("AddTimeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddTimeDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\260\320\271\320\274\320\270\320\275\320\263 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \321\201\320\265\320\260\320\275\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTimeDialog: public Ui_AddTimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTIMEDIALOG_H
