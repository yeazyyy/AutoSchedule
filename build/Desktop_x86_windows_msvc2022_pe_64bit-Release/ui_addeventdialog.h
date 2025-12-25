/********************************************************************************
** Form generated from reading UI file 'addeventdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTDIALOG_H
#define UI_ADDEVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddEventDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AddEventDialog)
    {
        if (AddEventDialog->objectName().isEmpty())
            AddEventDialog->setObjectName("AddEventDialog");
        AddEventDialog->resize(392, 131);
        buttonBox = new QDialogButtonBox(AddEventDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AddEventDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 20, 351, 41));

        retranslateUi(AddEventDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEventDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEventDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEventDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEventDialog)
    {
        AddEventDialog->setWindowTitle(QCoreApplication::translate("AddEventDialog", "Dialog", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("AddEventDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEventDialog: public Ui_AddEventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTDIALOG_H
