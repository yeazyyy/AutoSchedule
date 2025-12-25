/********************************************************************************
** Form generated from reading UI file 'addpupilsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPUPILSDIALOG_H
#define UI_ADDPUPILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPupilsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_AddName;
    QComboBox *comboBox_Rank;
    QComboBox *comboBox_Group;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AddPupilsDialog)
    {
        if (AddPupilsDialog->objectName().isEmpty())
            AddPupilsDialog->setObjectName("AddPupilsDialog");
        AddPupilsDialog->resize(384, 263);
        buttonBox = new QDialogButtonBox(AddPupilsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_AddName = new QLineEdit(AddPupilsDialog);
        lineEdit_AddName->setObjectName("lineEdit_AddName");
        lineEdit_AddName->setGeometry(QRect(20, 20, 191, 31));
        comboBox_Rank = new QComboBox(AddPupilsDialog);
        comboBox_Rank->setObjectName("comboBox_Rank");
        comboBox_Rank->setGeometry(QRect(20, 90, 191, 31));
        comboBox_Group = new QComboBox(AddPupilsDialog);
        comboBox_Group->setObjectName("comboBox_Group");
        comboBox_Group->setGeometry(QRect(20, 160, 191, 31));
        label = new QLabel(AddPupilsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 131, 20));
        label_2 = new QLabel(AddPupilsDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 121, 20));

        retranslateUi(AddPupilsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddPupilsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddPupilsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddPupilsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPupilsDialog)
    {
        AddPupilsDialog->setWindowTitle(QCoreApplication::translate("AddPupilsDialog", "Dialog", nullptr));
        lineEdit_AddName->setPlaceholderText(QCoreApplication::translate("AddPupilsDialog", "\320\244\320\230\320\236", nullptr));
        label->setText(QCoreApplication::translate("AddPupilsDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\267\321\200\321\217\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("AddPupilsDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPupilsDialog: public Ui_AddPupilsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPUPILSDIALOG_H
