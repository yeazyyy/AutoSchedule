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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_EditGroupDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_Group_type;
    QLabel *label_2;
    QComboBox *comboBox_Branch;
    QSpinBox *spinBox_Hierarchy;
    QLabel *label_3;
    QComboBox *comboBox_Coach;
    QDateEdit *dateEdit_Date;
    QTableWidget *tableWidget_Pupils;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditGroupDialog)
    {
        if (EditGroupDialog->objectName().isEmpty())
            EditGroupDialog->setObjectName("EditGroupDialog");
        EditGroupDialog->resize(432, 569);
        gridLayout = new QGridLayout(EditGroupDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(EditGroupDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        comboBox_Group_type = new QComboBox(EditGroupDialog);
        comboBox_Group_type->setObjectName("comboBox_Group_type");

        gridLayout->addWidget(comboBox_Group_type, 0, 2, 1, 1);

        label_2 = new QLabel(EditGroupDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        comboBox_Branch = new QComboBox(EditGroupDialog);
        comboBox_Branch->setObjectName("comboBox_Branch");

        gridLayout->addWidget(comboBox_Branch, 1, 2, 1, 1);

        spinBox_Hierarchy = new QSpinBox(EditGroupDialog);
        spinBox_Hierarchy->setObjectName("spinBox_Hierarchy");

        gridLayout->addWidget(spinBox_Hierarchy, 1, 3, 1, 1);

        label_3 = new QLabel(EditGroupDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox_Coach = new QComboBox(EditGroupDialog);
        comboBox_Coach->setObjectName("comboBox_Coach");

        gridLayout->addWidget(comboBox_Coach, 2, 2, 1, 1);

        dateEdit_Date = new QDateEdit(EditGroupDialog);
        dateEdit_Date->setObjectName("dateEdit_Date");

        gridLayout->addWidget(dateEdit_Date, 3, 2, 1, 1);

        tableWidget_Pupils = new QTableWidget(EditGroupDialog);
        tableWidget_Pupils->setObjectName("tableWidget_Pupils");

        gridLayout->addWidget(tableWidget_Pupils, 4, 0, 1, 4);

        buttonBox = new QDialogButtonBox(EditGroupDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 1, 1, 3);


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
