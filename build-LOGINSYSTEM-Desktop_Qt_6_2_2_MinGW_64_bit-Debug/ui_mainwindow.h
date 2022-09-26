/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label;
    QPushButton *employeebutton;
    QPushButton *clientbutton;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/KARYALAYA.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("border-image: url(:/images/office-management-system.png);\n"
"border-image: url(:/Images/Images/WeyM8.jpeg);\n"
"\n"
"border-color: rgb(5, 5, 5);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, -50, 341, 281));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/login.png);\n"
"border-image: url(:/Images/Images/KARYALAYA-removebg-preview.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 0, 561, 121));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/KARYALAYA.png);"));
        employeebutton = new QPushButton(centralwidget);
        employeebutton->setObjectName(QString::fromUtf8("employeebutton"));
        employeebutton->setGeometry(QRect(590, 50, 81, 81));
        employeebutton->setCursor(QCursor(Qt::PointingHandCursor));
        employeebutton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/Images/Employee-2.png);\n"
"border-image: url(:/Images/Images/Employee-2.png);\n"
"border-radius : 8px;"));
        clientbutton = new QPushButton(centralwidget);
        clientbutton->setObjectName(QString::fromUtf8("clientbutton"));
        clientbutton->setGeometry(QRect(690, 50, 80, 81));
        clientbutton->setCursor(QCursor(Qt::PointingHandCursor));
        clientbutton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/Images/client.png);\n"
"border-image: url(:/Images/Images/client.png);\n"
"border-radius : 8px;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 200, 281, 151));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/Images/Office.jpg);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(650, 20, 71, 21));
        MainWindow->setCentralWidget(centralwidget);
        label_4->raise();
        label_2->raise();
        label->raise();
        employeebutton->raise();
        clientbutton->raise();
        label_3->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login And Registration System", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        employeebutton->setText(QString());
        clientbutton->setText(QString());
        label_4->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "LOG IN AS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
