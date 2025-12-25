/********************************************************************************
** Form generated from reading UI file 'addgrouptypedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPTYPEDIALOG_H
#define UI_ADDGROUPTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddGroupTypeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QLineEdit *lineEditAddName;
    QLabel *label;

    void setupUi(QDialog *AddGroupTypeDialog)
    {
        if (AddGroupTypeDialog->objectName().isEmpty())
            AddGroupTypeDialog->setObjectName("AddGroupTypeDialog");
        AddGroupTypeDialog->resize(222, 153);
        buttonBox = new QDialogButtonBox(AddGroupTypeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 100, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(AddGroupTypeDialog);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(150, 60, 48, 29));
        lineEditAddName = new QLineEdit(AddGroupTypeDialog);
        lineEditAddName->setObjectName("lineEditAddName");
        lineEditAddName->setGeometry(QRect(20, 20, 181, 28));
        label = new QLabel(AddGroupTypeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 131, 31));

        retranslateUi(AddGroupTypeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddGroupTypeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddGroupTypeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddGroupTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupTypeDialog)
    {
        AddGroupTypeDialog->setWindowTitle(QCoreApplication::translate("AddGroupTypeDialog", "Dialog", nullptr));
        lineEditAddName->setPlaceholderText(QCoreApplication::translate("AddGroupTypeDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\270\320\277\320\260 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label->setText(QCoreApplication::translate("AddGroupTypeDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\260\321\201\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroupTypeDialog: public Ui_AddGroupTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPTYPEDIALOG_H
