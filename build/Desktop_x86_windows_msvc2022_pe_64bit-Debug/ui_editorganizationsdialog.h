/********************************************************************************
** Form generated from reading UI file 'editorganizationsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORGANIZATIONSDIALOG_H
#define UI_EDITORGANIZATIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EditOrganizationsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_Coach;
    QLabel *label;

    void setupUi(QDialog *EditOrganizationsDialog)
    {
        if (EditOrganizationsDialog->objectName().isEmpty())
            EditOrganizationsDialog->setObjectName("EditOrganizationsDialog");
        EditOrganizationsDialog->resize(354, 120);
        buttonBox = new QDialogButtonBox(EditOrganizationsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 71, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_Coach = new QComboBox(EditOrganizationsDialog);
        comboBox_Coach->setObjectName("comboBox_Coach");
        comboBox_Coach->setGeometry(QRect(80, 21, 261, 31));
        label = new QLabel(EditOrganizationsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 63, 31));

        retranslateUi(EditOrganizationsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditOrganizationsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditOrganizationsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditOrganizationsDialog);
    } // setupUi

    void retranslateUi(QDialog *EditOrganizationsDialog)
    {
        EditOrganizationsDialog->setWindowTitle(QCoreApplication::translate("EditOrganizationsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditOrganizationsDialog", "\320\242\321\200\320\265\320\275\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditOrganizationsDialog: public Ui_EditOrganizationsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORGANIZATIONSDIALOG_H
