/********************************************************************************
** Form generated from reading UI file 'addressbook.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOK_H
#define UI_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBook
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddressBook)
    {
        if (AddressBook->objectName().isEmpty())
            AddressBook->setObjectName("AddressBook");
        AddressBook->resize(800, 600);
        centralwidget = new QWidget(AddressBook);
        centralwidget->setObjectName("centralwidget");
        AddressBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddressBook);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        AddressBook->setMenuBar(menubar);
        statusbar = new QStatusBar(AddressBook);
        statusbar->setObjectName("statusbar");
        AddressBook->setStatusBar(statusbar);

        retranslateUi(AddressBook);

        QMetaObject::connectSlotsByName(AddressBook);
    } // setupUi

    void retranslateUi(QMainWindow *AddressBook)
    {
        AddressBook->setWindowTitle(QCoreApplication::translate("AddressBook", "AddressBook", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddressBook: public Ui_AddressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
