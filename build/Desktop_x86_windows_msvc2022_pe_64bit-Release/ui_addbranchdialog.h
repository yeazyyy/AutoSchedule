/********************************************************************************
** Form generated from reading UI file 'addbranchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBRANCHDIALOG_H
#define UI_ADDBRANCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddBranchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_AddName;
    QLineEdit *lineEdit_Color;
    QPushButton *pushButtonColor;

    void setupUi(QDialog *AddBranchDialog)
    {
        if (AddBranchDialog->objectName().isEmpty())
            AddBranchDialog->setObjectName("AddBranchDialog");
        AddBranchDialog->resize(363, 136);
        buttonBox = new QDialogButtonBox(AddBranchDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 80, 311, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_AddName = new QLineEdit(AddBranchDialog);
        lineEdit_AddName->setObjectName("lineEdit_AddName");
        lineEdit_AddName->setGeometry(QRect(30, 30, 171, 31));
        lineEdit_Color = new QLineEdit(AddBranchDialog);
        lineEdit_Color->setObjectName("lineEdit_Color");
        lineEdit_Color->setGeometry(QRect(30, 80, 121, 31));
        pushButtonColor = new QPushButton(AddBranchDialog);
        pushButtonColor->setObjectName("pushButtonColor");
        pushButtonColor->setGeometry(QRect(220, 30, 111, 31));

        retranslateUi(AddBranchDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBranchDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBranchDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddBranchDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBranchDialog)
    {
        AddBranchDialog->setWindowTitle(QCoreApplication::translate("AddBranchDialog", "Dialog", nullptr));
        lineEdit_AddName->setPlaceholderText(QCoreApplication::translate("AddBranchDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_Color->setPlaceholderText(QCoreApplication::translate("AddBranchDialog", "\320\246\320\262\320\265\321\202 (#af1de4)", nullptr));
        pushButtonColor->setText(QCoreApplication::translate("AddBranchDialog", "\320\246\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBranchDialog: public Ui_AddBranchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBRANCHDIALOG_H
