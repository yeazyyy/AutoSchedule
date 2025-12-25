/********************************************************************************
** Form generated from reading UI file 'editpupildialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPUPILDIALOG_H
#define UI_EDITPUPILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_EditPupilDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_EditPupil;
    QComboBox *comboBox_EditRank;
    QComboBox *comboBox_EditGroup;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *EditPupilDialog)
    {
        if (EditPupilDialog->objectName().isEmpty())
            EditPupilDialog->setObjectName("EditPupilDialog");
        EditPupilDialog->resize(353, 232);
        buttonBox = new QDialogButtonBox(EditPupilDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_EditPupil = new QLineEdit(EditPupilDialog);
        lineEdit_EditPupil->setObjectName("lineEdit_EditPupil");
        lineEdit_EditPupil->setGeometry(QRect(70, 30, 271, 31));
        comboBox_EditRank = new QComboBox(EditPupilDialog);
        comboBox_EditRank->setObjectName("comboBox_EditRank");
        comboBox_EditRank->setGeometry(QRect(70, 80, 271, 31));
        comboBox_EditGroup = new QComboBox(EditPupilDialog);
        comboBox_EditGroup->setObjectName("comboBox_EditGroup");
        comboBox_EditGroup->setGeometry(QRect(70, 130, 271, 31));
        label = new QLabel(EditPupilDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 41, 31));
        label_2 = new QLabel(EditPupilDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 51, 31));
        label_3 = new QLabel(EditPupilDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 51, 31));

        retranslateUi(EditPupilDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditPupilDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditPupilDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditPupilDialog);
    } // setupUi

    void retranslateUi(QDialog *EditPupilDialog)
    {
        EditPupilDialog->setWindowTitle(QCoreApplication::translate("EditPupilDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditPupilDialog", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("EditPupilDialog", "\320\240\320\260\320\267\321\200\321\217\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("EditPupilDialog", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPupilDialog: public Ui_EditPupilDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPUPILDIALOG_H
