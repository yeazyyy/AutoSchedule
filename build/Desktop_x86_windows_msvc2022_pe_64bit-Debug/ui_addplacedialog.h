/********************************************************************************
** Form generated from reading UI file 'addplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLACEDIALOG_H
#define UI_ADDPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddPlaceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_AddName;
    QSpinBox *spinBox_Ofset;
    QSpinBox *spinBox_Amount;
    QSpinBox *spinBox_Rows;
    QLineEdit *lineEdit_Header;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddPlaceDialog)
    {
        if (AddPlaceDialog->objectName().isEmpty())
            AddPlaceDialog->setObjectName("AddPlaceDialog");
        AddPlaceDialog->resize(390, 282);
        buttonBox = new QDialogButtonBox(AddPlaceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_AddName = new QLineEdit(AddPlaceDialog);
        lineEdit_AddName->setObjectName("lineEdit_AddName");
        lineEdit_AddName->setGeometry(QRect(20, 30, 201, 31));
        spinBox_Ofset = new QSpinBox(AddPlaceDialog);
        spinBox_Ofset->setObjectName("spinBox_Ofset");
        spinBox_Ofset->setGeometry(QRect(20, 70, 48, 29));
        spinBox_Amount = new QSpinBox(AddPlaceDialog);
        spinBox_Amount->setObjectName("spinBox_Amount");
        spinBox_Amount->setGeometry(QRect(20, 110, 48, 29));
        spinBox_Rows = new QSpinBox(AddPlaceDialog);
        spinBox_Rows->setObjectName("spinBox_Rows");
        spinBox_Rows->setGeometry(QRect(20, 150, 48, 29));
        lineEdit_Header = new QLineEdit(AddPlaceDialog);
        lineEdit_Header->setObjectName("lineEdit_Header");
        lineEdit_Header->setGeometry(QRect(20, 190, 351, 28));
        label = new QLabel(AddPlaceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 70, 71, 31));
        label_2 = new QLabel(AddPlaceDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 110, 121, 31));
        label_3 = new QLabel(AddPlaceDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 150, 291, 31));

        retranslateUi(AddPlaceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddPlaceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddPlaceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddPlaceDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPlaceDialog)
    {
        AddPlaceDialog->setWindowTitle(QCoreApplication::translate("AddPlaceDialog", "Dialog", nullptr));
        lineEdit_AddName->setPlaceholderText(QCoreApplication::translate("AddPlaceDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_Header->setPlaceholderText(QCoreApplication::translate("AddPlaceDialog", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("AddPlaceDialog", "\320\237\321\200\320\276\320\277\321\203\321\201\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("AddPlaceDialog", "\320\232\320\276\320\273-\320\262\320\276 \321\201\320\265\320\260\320\275\321\201\320\276\320\262", nullptr));
        label_3->setText(QCoreApplication::translate("AddPlaceDialog", "\320\232\320\276\320\273-\320\262\320\276 \320\264\320\276\321\200\320\276\320\266\320\265\320\272 (\320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205 \320\263\321\200\321\203\320\277\320\277)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlaceDialog: public Ui_AddPlaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLACEDIALOG_H
