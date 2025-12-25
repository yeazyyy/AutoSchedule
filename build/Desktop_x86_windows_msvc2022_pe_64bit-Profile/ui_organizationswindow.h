/********************************************************************************
** Form generated from reading UI file 'organizationswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZATIONSWINDOW_H
#define UI_ORGANIZATIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrganizationsWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_Organizations;

    void setupUi(QWidget *OrganizationsWindow)
    {
        if (OrganizationsWindow->objectName().isEmpty())
            OrganizationsWindow->setObjectName("OrganizationsWindow");
        OrganizationsWindow->resize(800, 600);
        horizontalLayout = new QHBoxLayout(OrganizationsWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget_Organizations = new QTableWidget(OrganizationsWindow);
        tableWidget_Organizations->setObjectName("tableWidget_Organizations");

        horizontalLayout->addWidget(tableWidget_Organizations);


        retranslateUi(OrganizationsWindow);

        QMetaObject::connectSlotsByName(OrganizationsWindow);
    } // setupUi

    void retranslateUi(QWidget *OrganizationsWindow)
    {
        OrganizationsWindow->setWindowTitle(QCoreApplication::translate("OrganizationsWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrganizationsWindow: public Ui_OrganizationsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZATIONSWINDOW_H
