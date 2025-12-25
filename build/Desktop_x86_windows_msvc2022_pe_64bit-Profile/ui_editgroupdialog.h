/********************************************************************************
** Form generated from reading UI file 'editgroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITGROUPDIALOG_H
#define UI_EDITGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_EditGroupDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_Hierarchy;
    QComboBox *comboBox_Branch;
    QComboBox *comboBox_Group_type;
    QComboBox *comboBox_Coach;
    QDateEdit *dateEdit_Date;
    QTableWidget *tableWidget_Pupils;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *EditGroupDialog)
    {
        if (EditGroupDialog->objectName().isEmpty())
            EditGroupDialog->setObjectName("EditGroupDialog");
        EditGroupDialog->resize(432, 569);
        buttonBox = new QDialogButtonBox(EditGroupDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(80, 530, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_Hierarchy = new QSpinBox(EditGroupDialog);
        spinBox_Hierarchy->setObjectName("spinBox_Hierarchy");
        spinBox_Hierarchy->setGeometry(QRect(370, 50, 51, 29));
        comboBox_Branch = new QComboBox(EditGroupDialog);
        comboBox_Branch->setObjectName("comboBox_Branch");
        comboBox_Branch->setGeometry(QRect(110, 50, 241, 28));
        comboBox_Group_type = new QComboBox(EditGroupDialog);
        comboBox_Group_type->setObjectName("comboBox_Group_type");
        comboBox_Group_type->setGeometry(QRect(110, 10, 241, 28));
        comboBox_Coach = new QComboBox(EditGroupDialog);
        comboBox_Coach->setObjectName("comboBox_Coach");
        comboBox_Coach->setGeometry(QRect(110, 90, 241, 31));
        dateEdit_Date = new QDateEdit(EditGroupDialog);
        dateEdit_Date->setObjectName("dateEdit_Date");
        dateEdit_Date->setGeometry(QRect(110, 130, 110, 29));
        tableWidget_Pupils = new QTableWidget(EditGroupDialog);
        tableWidget_Pupils->setObjectName("tableWidget_Pupils");
        tableWidget_Pupils->setGeometry(QRect(10, 170, 411, 351));
        label = new QLabel(EditGroupDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 91, 31));
        label_2 = new QLabel(EditGroupDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 91, 31));
        label_3 = new QLabel(EditGroupDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 63, 31));

        retranslateUi(EditGroupDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditGroupDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditGroupDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *EditGroupDialog)
    {
        EditGroupDialog->setWindowTitle(QCoreApplication::translate("EditGroupDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditGroupDialog", "\320\242\320\270\320\277 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("EditGroupDialog", "\320\222\320\270\320\264 \321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("EditGroupDialog", "\320\242\321\200\320\265\320\275\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditGroupDialog: public Ui_EditGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITGROUPDIALOG_H
