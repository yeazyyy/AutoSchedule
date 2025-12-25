/********************************************************************************
** Form generated from reading UI file 'addranksdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRANKSDIALOG_H
#define UI_ADDRANKSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddRanksDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_AddName;

    void setupUi(QDialog *AddRanksDialog)
    {
        if (AddRanksDialog->objectName().isEmpty())
            AddRanksDialog->setObjectName("AddRanksDialog");
        AddRanksDialog->resize(318, 121);
        buttonBox = new QDialogButtonBox(AddRanksDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 70, 291, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_AddName = new QLineEdit(AddRanksDialog);
        lineEdit_AddName->setObjectName("lineEdit_AddName");
        lineEdit_AddName->setGeometry(QRect(20, 20, 201, 31));

        retranslateUi(AddRanksDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddRanksDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddRanksDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddRanksDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRanksDialog)
    {
        AddRanksDialog->setWindowTitle(QCoreApplication::translate("AddRanksDialog", "Dialog", nullptr));
        lineEdit_AddName->setPlaceholderText(QCoreApplication::translate("AddRanksDialog", "\320\240\320\260\320\267\321\200\321\217\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRanksDialog: public Ui_AddRanksDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRANKSDIALOG_H
