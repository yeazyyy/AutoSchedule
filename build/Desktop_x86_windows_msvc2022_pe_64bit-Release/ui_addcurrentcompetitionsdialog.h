/********************************************************************************
** Form generated from reading UI file 'addcurrentcompetitionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCURRENTCOMPETITIONSDIALOG_H
#define UI_ADDCURRENTCOMPETITIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCurrentCompetitionsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddCurrentCompetitionsDialog)
    {
        if (AddCurrentCompetitionsDialog->objectName().isEmpty())
            AddCurrentCompetitionsDialog->setObjectName("AddCurrentCompetitionsDialog");
        AddCurrentCompetitionsDialog->resize(900, 550);
        verticalLayout_2 = new QVBoxLayout(AddCurrentCompetitionsDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(AddCurrentCompetitionsDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 874, 486));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox = new QComboBox(AddCurrentCompetitionsDialog);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        buttonBox = new QDialogButtonBox(AddCurrentCompetitionsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setMaximumSize(QSize(200, 16777215));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddCurrentCompetitionsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCurrentCompetitionsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCurrentCompetitionsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCurrentCompetitionsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCurrentCompetitionsDialog)
    {
        AddCurrentCompetitionsDialog->setWindowTitle(QCoreApplication::translate("AddCurrentCompetitionsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCurrentCompetitionsDialog: public Ui_AddCurrentCompetitionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCURRENTCOMPETITIONSDIALOG_H
