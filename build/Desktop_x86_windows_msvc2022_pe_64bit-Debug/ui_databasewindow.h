/********************************************************************************
** Form generated from reading UI file 'databasewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWINDOW_H
#define UI_DATABASEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *tableWidget_Group;
    QPushButton *pushButton_AddGroups;
    QPushButton *pushButton_Organizations;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_Pupils;
    QPushButton *pushButton_AddPupils;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QTableView *tableView_Coaches;
    QPushButton *pushButton_AddCoach;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableView *tableView_Group_types;
    QPushButton *pushButton_AddGroupTypes;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QTableView *tableView_Ranks;
    QPushButton *pushButton_AddRanks;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QTableWidget *tableWidget_Branches;
    QPushButton *pushButton_AddBranches;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_7;
    QTableView *tableView_Events;
    QPushButton *pushButton_AddEvent;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QTableView *tableView_Time;
    QPushButton *pushButton_AddTime;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_4;
    QTableView *tableView_Place;
    QPushButton *pushButton_AddPlace;
    QPushButton *pushButton_Home;

    void setupUi(QWidget *DatabaseWindow)
    {
        if (DatabaseWindow->objectName().isEmpty())
            DatabaseWindow->setObjectName("DatabaseWindow");
        DatabaseWindow->resize(1353, 751);
        verticalLayout_2 = new QVBoxLayout(DatabaseWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(DatabaseWindow);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_5 = new QHBoxLayout(tab);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        tableWidget_Group = new QTableWidget(tab);
        tableWidget_Group->setObjectName("tableWidget_Group");

        verticalLayout_9->addWidget(tableWidget_Group);

        pushButton_AddGroups = new QPushButton(tab);
        pushButton_AddGroups->setObjectName("pushButton_AddGroups");

        verticalLayout_9->addWidget(pushButton_AddGroups);

        pushButton_Organizations = new QPushButton(tab);
        pushButton_Organizations->setObjectName("pushButton_Organizations");

        verticalLayout_9->addWidget(pushButton_Organizations);


        horizontalLayout_5->addLayout(verticalLayout_9);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_4 = new QHBoxLayout(tab_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        tableWidget_Pupils = new QTableWidget(tab_2);
        tableWidget_Pupils->setObjectName("tableWidget_Pupils");

        verticalLayout_8->addWidget(tableWidget_Pupils);

        pushButton_AddPupils = new QPushButton(tab_2);
        pushButton_AddPupils->setObjectName("pushButton_AddPupils");

        verticalLayout_8->addWidget(pushButton_AddPupils);


        horizontalLayout_4->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");

        verticalLayout_7->addWidget(label_5);

        tableView_Coaches = new QTableView(tab_3);
        tableView_Coaches->setObjectName("tableView_Coaches");

        verticalLayout_7->addWidget(tableView_Coaches);

        pushButton_AddCoach = new QPushButton(tab_3);
        pushButton_AddCoach->setObjectName("pushButton_AddCoach");

        verticalLayout_7->addWidget(pushButton_AddCoach);


        horizontalLayout_3->addLayout(verticalLayout_7);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_17 = new QVBoxLayout(tab_4);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(tab_4);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        tableView_Group_types = new QTableView(tab_4);
        tableView_Group_types->setObjectName("tableView_Group_types");
        tableView_Group_types->setMaximumSize(QSize(350, 16777215));

        verticalLayout_3->addWidget(tableView_Group_types);

        pushButton_AddGroupTypes = new QPushButton(tab_4);
        pushButton_AddGroupTypes->setObjectName("pushButton_AddGroupTypes");

        verticalLayout_3->addWidget(pushButton_AddGroupTypes);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");

        verticalLayout_5->addWidget(label_3);

        tableView_Ranks = new QTableView(tab_4);
        tableView_Ranks->setObjectName("tableView_Ranks");

        verticalLayout_5->addWidget(tableView_Ranks);

        pushButton_AddRanks = new QPushButton(tab_4);
        pushButton_AddRanks->setObjectName("pushButton_AddRanks");

        verticalLayout_5->addWidget(pushButton_AddRanks);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");

        verticalLayout_4->addWidget(label_2);

        tableWidget_Branches = new QTableWidget(tab_4);
        tableWidget_Branches->setObjectName("tableWidget_Branches");

        verticalLayout_4->addWidget(tableWidget_Branches);

        pushButton_AddBranches = new QPushButton(tab_4);
        pushButton_AddBranches->setObjectName("pushButton_AddBranches");

        verticalLayout_4->addWidget(pushButton_AddBranches);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_7 = new QLabel(tab_4);
        label_7->setObjectName("label_7");

        verticalLayout_20->addWidget(label_7);

        tableView_Events = new QTableView(tab_4);
        tableView_Events->setObjectName("tableView_Events");

        verticalLayout_20->addWidget(tableView_Events);

        pushButton_AddEvent = new QPushButton(tab_4);
        pushButton_AddEvent->setObjectName("pushButton_AddEvent");

        verticalLayout_20->addWidget(pushButton_AddEvent);


        horizontalLayout->addLayout(verticalLayout_20);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(tab_4);
        label_6->setObjectName("label_6");

        verticalLayout_6->addWidget(label_6);

        tableView_Time = new QTableView(tab_4);
        tableView_Time->setObjectName("tableView_Time");

        verticalLayout_6->addWidget(tableView_Time);

        pushButton_AddTime = new QPushButton(tab_4);
        pushButton_AddTime->setObjectName("pushButton_AddTime");

        verticalLayout_6->addWidget(pushButton_AddTime);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_18->addLayout(horizontalLayout);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_4 = new QLabel(tab_4);
        label_4->setObjectName("label_4");

        verticalLayout_19->addWidget(label_4);

        tableView_Place = new QTableView(tab_4);
        tableView_Place->setObjectName("tableView_Place");

        verticalLayout_19->addWidget(tableView_Place);

        pushButton_AddPlace = new QPushButton(tab_4);
        pushButton_AddPlace->setObjectName("pushButton_AddPlace");

        verticalLayout_19->addWidget(pushButton_AddPlace);


        verticalLayout_18->addLayout(verticalLayout_19);


        verticalLayout_17->addLayout(verticalLayout_18);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_Home = new QPushButton(DatabaseWindow);
        pushButton_Home->setObjectName("pushButton_Home");

        verticalLayout_2->addWidget(pushButton_Home);


        retranslateUi(DatabaseWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(DatabaseWindow);
    } // setupUi

    void retranslateUi(QWidget *DatabaseWindow)
    {
        DatabaseWindow->setWindowTitle(QCoreApplication::translate("DatabaseWindow", "Form", nullptr));
        pushButton_AddGroups->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        pushButton_Organizations->setText(QCoreApplication::translate("DatabaseWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\267\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DatabaseWindow", "\320\223\321\200\321\203\320\277\320\277\321\213", nullptr));
        pushButton_AddPupils->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DatabaseWindow", "\320\241\320\277\320\276\321\200\321\202\321\201\320\274\320\265\320\275\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("DatabaseWindow", "\320\242\321\200\320\265\320\275\320\265\321\200\321\213", nullptr));
        pushButton_AddCoach->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DatabaseWindow", "\320\242\321\200\320\265\320\275\320\265\321\200\321\213", nullptr));
        label->setText(QCoreApplication::translate("DatabaseWindow", "\320\242\320\270\320\277\321\213 \320\263\321\200\321\203\320\277\320\277", nullptr));
        pushButton_AddGroupTypes->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseWindow", "\320\241\320\277\320\276\321\200\321\202\320\270\320\262\320\275\321\213\320\265 \321\200\320\260\320\267\321\200\321\217\320\264\321\213", nullptr));
        pushButton_AddRanks->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseWindow", "\320\222\320\270\320\264\321\213 \321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        pushButton_AddBranches->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        label_7->setText(QCoreApplication::translate("DatabaseWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        pushButton_AddEvent->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        label_6->setText(QCoreApplication::translate("DatabaseWindow", "\320\241\320\265\320\260\320\275\321\201\321\213", nullptr));
        pushButton_AddTime->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        label_4->setText(QCoreApplication::translate("DatabaseWindow", "\320\234\320\265\321\201\321\202\320\260 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\276\320\272", nullptr));
        pushButton_AddPlace->setText(QCoreApplication::translate("DatabaseWindow", "+", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("DatabaseWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        pushButton_Home->setText(QCoreApplication::translate("DatabaseWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseWindow: public Ui_DatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWINDOW_H
