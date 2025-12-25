/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_AddEvent;
    QPushButton *pushButton_Cancellations;
    QPushButton *pushButton_Confirm;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_Home;

    void setupUi(QWidget *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName("Schedule");
        Schedule->resize(800, 600);
        horizontalLayout_4 = new QHBoxLayout(Schedule);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(Schedule);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 460, 536));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox = new QComboBox(Schedule);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        pushButton_AddEvent = new QPushButton(Schedule);
        pushButton_AddEvent->setObjectName("pushButton_AddEvent");

        horizontalLayout->addWidget(pushButton_AddEvent);

        pushButton_Cancellations = new QPushButton(Schedule);
        pushButton_Cancellations->setObjectName("pushButton_Cancellations");

        horizontalLayout->addWidget(pushButton_Cancellations);

        pushButton_Confirm = new QPushButton(Schedule);
        pushButton_Confirm->setObjectName("pushButton_Confirm");

        horizontalLayout->addWidget(pushButton_Confirm);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        textBrowser = new QTextBrowser(Schedule);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(170, 16777215));

        verticalLayout_3->addWidget(textBrowser);

        textBrowser_2 = new QTextBrowser(Schedule);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setMaximumSize(QSize(170, 16777215));

        verticalLayout_3->addWidget(textBrowser_2);

        pushButton_Home = new QPushButton(Schedule);
        pushButton_Home->setObjectName("pushButton_Home");
        pushButton_Home->setMaximumSize(QSize(170, 16777215));

        verticalLayout_3->addWidget(pushButton_Home);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Schedule);

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QWidget *Schedule)
    {
        Schedule->setWindowTitle(QCoreApplication::translate("Schedule", "Form", nullptr));
        pushButton_AddEvent->setText(QCoreApplication::translate("Schedule", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        pushButton_Cancellations->setText(QCoreApplication::translate("Schedule", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\321\217 \321\202\321\200\320\265\320\275\320\265\321\200\320\260", nullptr));
        pushButton_Confirm->setText(QCoreApplication::translate("Schedule", "\320\243\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        pushButton_Home->setText(QCoreApplication::translate("Schedule", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
