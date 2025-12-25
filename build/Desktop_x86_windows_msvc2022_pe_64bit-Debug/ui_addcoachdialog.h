/********************************************************************************
** Form generated from reading UI file 'addcoachdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOACHDIALOG_H
#define UI_ADDCOACHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddCoachDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditAddName;

    void setupUi(QDialog *AddCoachDialog)
    {
        if (AddCoachDialog->objectName().isEmpty())
            AddCoachDialog->setObjectName("AddCoachDialog");
        AddCoachDialog->resize(385, 125);
        buttonBox = new QDialogButtonBox(AddCoachDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 70, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEditAddName = new QLineEdit(AddCoachDialog);
        lineEditAddName->setObjectName("lineEditAddName");
        lineEditAddName->setGeometry(QRect(20, 20, 341, 31));

        retranslateUi(AddCoachDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCoachDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCoachDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCoachDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCoachDialog)
    {
        AddCoachDialog->setWindowTitle(QCoreApplication::translate("AddCoachDialog", "Dialog", nullptr));
        lineEditAddName->setPlaceholderText(QCoreApplication::translate("AddCoachDialog", "\320\244\320\230\320\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCoachDialog: public Ui_AddCoachDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOACHDIALOG_H
