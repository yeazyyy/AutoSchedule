/********************************************************************************
** Form generated from reading UI file 'editbranchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITBRANCHDIALOG_H
#define UI_EDITBRANCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditBranchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_AddName;
    QPushButton *pushButtonColor;
    QLineEdit *lineEdit_Color;

    void setupUi(QDialog *EditBranchDialog)
    {
        if (EditBranchDialog->objectName().isEmpty())
            EditBranchDialog->setObjectName("EditBranchDialog");
        EditBranchDialog->resize(338, 165);
        buttonBox = new QDialogButtonBox(EditBranchDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 120, 271, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_AddName = new QLineEdit(EditBranchDialog);
        lineEdit_AddName->setObjectName("lineEdit_AddName");
        lineEdit_AddName->setGeometry(QRect(20, 30, 171, 31));
        pushButtonColor = new QPushButton(EditBranchDialog);
        pushButtonColor->setObjectName("pushButtonColor");
        pushButtonColor->setGeometry(QRect(210, 30, 111, 31));
        lineEdit_Color = new QLineEdit(EditBranchDialog);
        lineEdit_Color->setObjectName("lineEdit_Color");
        lineEdit_Color->setGeometry(QRect(20, 80, 121, 31));

        retranslateUi(EditBranchDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditBranchDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditBranchDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditBranchDialog);
    } // setupUi

    void retranslateUi(QDialog *EditBranchDialog)
    {
        EditBranchDialog->setWindowTitle(QCoreApplication::translate("EditBranchDialog", "Dialog", nullptr));
        lineEdit_AddName->setPlaceholderText(QCoreApplication::translate("EditBranchDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButtonColor->setText(QCoreApplication::translate("EditBranchDialog", "\320\246\320\262\320\265\321\202", nullptr));
        lineEdit_Color->setPlaceholderText(QCoreApplication::translate("EditBranchDialog", "\320\246\320\262\320\265\321\202 (#af1de4)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditBranchDialog: public Ui_EditBranchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITBRANCHDIALOG_H
