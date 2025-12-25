/********************************************************************************
** Form generated from reading UI file 'addgroupsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPSDIALOG_H
#define UI_ADDGROUPSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddGroupsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_Branch;
    QDateEdit *dateEdit_Date;
    QComboBox *comboBox_Group_type;
    QComboBox *comboBox_Coach;
    QSpinBox *spinBox_Hierarchy;
    QLineEdit *lineEdit_OrganizationName;
    QLabel *label_gt;
    QLabel *label_c;
    QLabel *label_h;
    QLabel *label_br;

    void setupUi(QDialog *AddGroupsDialog)
    {
        if (AddGroupsDialog->objectName().isEmpty())
            AddGroupsDialog->setObjectName("AddGroupsDialog");
        AddGroupsDialog->resize(404, 331);
        buttonBox = new QDialogButtonBox(AddGroupsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_Branch = new QComboBox(AddGroupsDialog);
        comboBox_Branch->setObjectName("comboBox_Branch");
        comboBox_Branch->setGeometry(QRect(30, 120, 241, 28));
        dateEdit_Date = new QDateEdit(AddGroupsDialog);
        dateEdit_Date->setObjectName("dateEdit_Date");
        dateEdit_Date->setGeometry(QRect(30, 230, 110, 29));
        comboBox_Group_type = new QComboBox(AddGroupsDialog);
        comboBox_Group_type->setObjectName("comboBox_Group_type");
        comboBox_Group_type->setGeometry(QRect(30, 50, 241, 28));
        comboBox_Coach = new QComboBox(AddGroupsDialog);
        comboBox_Coach->setObjectName("comboBox_Coach");
        comboBox_Coach->setGeometry(QRect(30, 190, 241, 28));
        spinBox_Hierarchy = new QSpinBox(AddGroupsDialog);
        spinBox_Hierarchy->setObjectName("spinBox_Hierarchy");
        spinBox_Hierarchy->setGeometry(QRect(290, 120, 51, 29));
        lineEdit_OrganizationName = new QLineEdit(AddGroupsDialog);
        lineEdit_OrganizationName->setObjectName("lineEdit_OrganizationName");
        lineEdit_OrganizationName->setGeometry(QRect(30, 120, 241, 28));
        label_gt = new QLabel(AddGroupsDialog);
        label_gt->setObjectName("label_gt");
        label_gt->setGeometry(QRect(70, 20, 161, 20));
        label_c = new QLabel(AddGroupsDialog);
        label_c->setObjectName("label_c");
        label_c->setGeometry(QRect(80, 160, 141, 20));
        label_h = new QLabel(AddGroupsDialog);
        label_h->setObjectName("label_h");
        label_h->setGeometry(QRect(280, 90, 81, 20));
        label_br = new QLabel(AddGroupsDialog);
        label_br->setObjectName("label_br");
        label_br->setGeometry(QRect(70, 90, 161, 20));

        retranslateUi(AddGroupsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddGroupsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddGroupsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddGroupsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupsDialog)
    {
        AddGroupsDialog->setWindowTitle(QCoreApplication::translate("AddGroupsDialog", "Dialog", nullptr));
        lineEdit_OrganizationName->setPlaceholderText(QCoreApplication::translate("AddGroupsDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        label_gt->setText(QCoreApplication::translate("AddGroupsDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_c->setText(QCoreApplication::translate("AddGroupsDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\321\200\320\265\320\275\320\265\321\200\320\260", nullptr));
        label_h->setText(QCoreApplication::translate("AddGroupsDialog", "\320\230\320\265\321\200\320\260\321\200\321\205\320\270\321\217", nullptr));
        label_br->setText(QCoreApplication::translate("AddGroupsDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\262\320\270\320\264 \321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroupsDialog: public Ui_AddGroupsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPSDIALOG_H
