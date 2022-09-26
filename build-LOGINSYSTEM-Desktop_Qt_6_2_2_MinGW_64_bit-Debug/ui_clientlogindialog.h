/********************************************************************************
** Form generated from reading UI file 'clientlogindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLOGINDIALOG_H
#define UI_CLIENTLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientloginDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_username;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QPushButton *pushButton_signup;

    void setupUi(QDialog *ClientloginDialog)
    {
        if (ClientloginDialog->objectName().isEmpty())
            ClientloginDialog->setObjectName(QString::fromUtf8("ClientloginDialog"));
        ClientloginDialog->resize(760, 618);
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        ClientloginDialog->setFont(font);
        ClientloginDialog->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(ClientloginDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(410, 80, 331, 511));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"border-radius:20px;"));
        groupBox->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 200, 91, 20));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        plainTextEdit_username = new QPlainTextEdit(groupBox);
        plainTextEdit_username->setObjectName(QString::fromUtf8("plainTextEdit_username"));
        plainTextEdit_username->setGeometry(QRect(10, 230, 241, 41));
        plainTextEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 69, 171, 111));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/Images/Images/user.png);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 290, 111, 20));
        label_3->setFont(font2);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 320, 241, 41));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 460, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 410, 216, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        label_4->setFont(font3);
        label_4->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout->addWidget(label_4);

        pushButton_signup = new QPushButton(widget);
        pushButton_signup->setObjectName(QString::fromUtf8("pushButton_signup"));
        QFont font4;
        font4.setPointSize(11);
        pushButton_signup->setFont(font4);
        pushButton_signup->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_signup->setStyleSheet(QString::fromUtf8("#pushButton_signup:hover{text-decoration: underline;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton_signup);


        retranslateUi(ClientloginDialog);

        QMetaObject::connectSlotsByName(ClientloginDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientloginDialog)
    {
        ClientloginDialog->setWindowTitle(QCoreApplication::translate("ClientloginDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ClientloginDialog", "Client Login", nullptr));
        label->setText(QCoreApplication::translate("ClientloginDialog", "Username", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("ClientloginDialog", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientloginDialog", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("ClientloginDialog", "Not registered yet?", nullptr));
        pushButton_signup->setText(QCoreApplication::translate("ClientloginDialog", "Signup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientloginDialog: public Ui_ClientloginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGINDIALOG_H
