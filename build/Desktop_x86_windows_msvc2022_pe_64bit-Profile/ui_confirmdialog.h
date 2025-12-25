/********************************************************************************
** Form generated from reading UI file 'confirmdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIALOG_H
#define UI_CONFIRMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit_Confirm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_FullName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit_From;
    QLabel *label_4;
    QDateEdit *dateEdit_To;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_header;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_Worker;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit_WorkerFullName;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBox_FontSize;
    QSpinBox *spinBox_HeightList;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfirmDialog)
    {
        if (ConfirmDialog->objectName().isEmpty())
            ConfirmDialog->setObjectName("ConfirmDialog");
        ConfirmDialog->resize(681, 493);
        verticalLayout_2 = new QVBoxLayout(ConfirmDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        textEdit_Confirm = new QTextEdit(ConfirmDialog);
        textEdit_Confirm->setObjectName("textEdit_Confirm");
        textEdit_Confirm->setMaximumSize(QSize(16777215, 200));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        textEdit_Confirm->setFont(font);

        verticalLayout_3->addWidget(textEdit_Confirm);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(ConfirmDialog);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        textEdit_FullName = new QTextEdit(ConfirmDialog);
        textEdit_FullName->setObjectName("textEdit_FullName");
        textEdit_FullName->setMaximumSize(QSize(150, 30));
        textEdit_FullName->setFont(font);

        horizontalLayout_2->addWidget(textEdit_FullName);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(ConfirmDialog);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(10, 16777215));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        dateEdit_From = new QDateEdit(ConfirmDialog);
        dateEdit_From->setObjectName("dateEdit_From");
        dateEdit_From->setFont(font);

        horizontalLayout_3->addWidget(dateEdit_From);

        label_4 = new QLabel(ConfirmDialog);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(20, 16777215));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        dateEdit_To = new QDateEdit(ConfirmDialog);
        dateEdit_To->setObjectName("dateEdit_To");
        dateEdit_To->setFont(font);

        horizontalLayout_3->addWidget(dateEdit_To);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        label_header = new QLabel(ConfirmDialog);
        label_header->setObjectName("label_header");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label_header->setFont(font2);
        label_header->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_header);

        label = new QLabel(ConfirmDialog);
        label->setObjectName("label");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(12);
        font3.setBold(false);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        textEdit_Worker = new QTextEdit(ConfirmDialog);
        textEdit_Worker->setObjectName("textEdit_Worker");
        textEdit_Worker->setMinimumSize(QSize(350, 0));
        textEdit_Worker->setMaximumSize(QSize(500, 50));
        textEdit_Worker->setFont(font);

        horizontalLayout_4->addWidget(textEdit_Worker);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        textEdit_WorkerFullName = new QTextEdit(ConfirmDialog);
        textEdit_WorkerFullName->setObjectName("textEdit_WorkerFullName");
        textEdit_WorkerFullName->setMaximumSize(QSize(150, 30));
        textEdit_WorkerFullName->setFont(font);

        horizontalLayout_4->addWidget(textEdit_WorkerFullName);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        spinBox_FontSize = new QSpinBox(ConfirmDialog);
        spinBox_FontSize->setObjectName("spinBox_FontSize");
        spinBox_FontSize->setMaximumSize(QSize(50, 16777215));
        spinBox_FontSize->setValue(9);

        horizontalLayout_6->addWidget(spinBox_FontSize);

        spinBox_HeightList = new QSpinBox(ConfirmDialog);
        spinBox_HeightList->setObjectName("spinBox_HeightList");
        spinBox_HeightList->setEnabled(true);
        spinBox_HeightList->setMinimumSize(QSize(0, 0));
        spinBox_HeightList->setMaximumSize(QSize(50, 16777215));
        spinBox_HeightList->setMaximum(1000);
        spinBox_HeightList->setValue(720);

        horizontalLayout_6->addWidget(spinBox_HeightList);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        buttonBox = new QDialogButtonBox(ConfirmDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(ConfirmDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConfirmDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConfirmDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConfirmDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDialog)
    {
        ConfirmDialog->setWindowTitle(QCoreApplication::translate("ConfirmDialog", "Dialog", nullptr));
        textEdit_Confirm->setPlaceholderText(QCoreApplication::translate("ConfirmDialog", "\320\243\320\242\320\222\320\225\320\240\320\226\320\224\320\220\320\256...", nullptr));
        label_2->setText(QCoreApplication::translate("ConfirmDialog", " ___________________________", nullptr));
        textEdit_FullName->setPlaceholderText(QCoreApplication::translate("ConfirmDialog", "\320\244\320\230\320\236", nullptr));
        label_3->setText(QCoreApplication::translate("ConfirmDialog", "\321\201", nullptr));
        label_4->setText(QCoreApplication::translate("ConfirmDialog", "\320\277\320\276", nullptr));
        label_header->setText(QCoreApplication::translate("ConfirmDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("ConfirmDialog", "(\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274)", nullptr));
        textEdit_Worker->setHtml(QCoreApplication::translate("ConfirmDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_Worker->setPlaceholderText(QCoreApplication::translate("ConfirmDialog", "\320\227\320\260\320\274\320\265\321\201\321\202\320\270\321\202\320\265\320\273\321\214", nullptr));
        textEdit_WorkerFullName->setPlaceholderText(QCoreApplication::translate("ConfirmDialog", "\320\244\320\230\320\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDialog: public Ui_ConfirmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIALOG_H
