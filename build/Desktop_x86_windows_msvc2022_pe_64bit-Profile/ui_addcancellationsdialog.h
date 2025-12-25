/********************************************************************************
** Form generated from reading UI file 'addcancellationsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCANCELLATIONSDIALOG_H
#define UI_ADDCANCELLATIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddCancellationsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_Coach;
    QComboBox *comboBox_From;
    QComboBox *comboBox_To;
    QCheckBox *checkBox_Delete;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddCancellationsDialog)
    {
        if (AddCancellationsDialog->objectName().isEmpty())
            AddCancellationsDialog->setObjectName("AddCancellationsDialog");
        AddCancellationsDialog->resize(419, 178);
        buttonBox = new QDialogButtonBox(AddCancellationsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_Coach = new QComboBox(AddCancellationsDialog);
        comboBox_Coach->setObjectName("comboBox_Coach");
        comboBox_Coach->setGeometry(QRect(170, 20, 231, 31));
        comboBox_From = new QComboBox(AddCancellationsDialog);
        comboBox_From->setObjectName("comboBox_From");
        comboBox_From->setGeometry(QRect(40, 60, 161, 31));
        comboBox_To = new QComboBox(AddCancellationsDialog);
        comboBox_To->setObjectName("comboBox_To");
        comboBox_To->setGeometry(QRect(240, 60, 161, 31));
        checkBox_Delete = new QCheckBox(AddCancellationsDialog);
        checkBox_Delete->setObjectName("checkBox_Delete");
        checkBox_Delete->setGeometry(QRect(20, 100, 201, 26));
        label = new QLabel(AddCancellationsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 141, 31));
        label_2 = new QLabel(AddCancellationsDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 21, 31));
        label_3 = new QLabel(AddCancellationsDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 60, 21, 31));

        retranslateUi(AddCancellationsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCancellationsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCancellationsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCancellationsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCancellationsDialog)
    {
        AddCancellationsDialog->setWindowTitle(QCoreApplication::translate("AddCancellationsDialog", "Dialog", nullptr));
        checkBox_Delete->setText(QCoreApplication::translate("AddCancellationsDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("AddCancellationsDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\321\200\320\265\320\275\320\265\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AddCancellationsDialog", "\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("AddCancellationsDialog", "\320\277\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCancellationsDialog: public Ui_AddCancellationsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCANCELLATIONSDIALOG_H
