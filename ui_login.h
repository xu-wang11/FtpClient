/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Mon Oct 28 00:38:55 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *IP_Input;
    QLineEdit *Port_Input;
    QLineEdit *UserName_Input;
    QLineEdit *Password_Input;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(20);
        Login->setFont(font);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 61, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 80, 51, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 51, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 160, 31, 31));
        label_4->setFont(font1);
        IP_Input = new QLineEdit(Login);
        IP_Input->setObjectName(QString::fromUtf8("IP_Input"));
        IP_Input->setGeometry(QRect(120, 40, 151, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(12);
        IP_Input->setFont(font2);
        Port_Input = new QLineEdit(Login);
        Port_Input->setObjectName(QString::fromUtf8("Port_Input"));
        Port_Input->setGeometry(QRect(120, 80, 41, 31));
        QFont font3;
        font3.setPointSize(12);
        Port_Input->setFont(font3);
        UserName_Input = new QLineEdit(Login);
        UserName_Input->setObjectName(QString::fromUtf8("UserName_Input"));
        UserName_Input->setGeometry(QRect(120, 120, 151, 31));
        UserName_Input->setFont(font3);
        Password_Input = new QLineEdit(Login);
        Password_Input->setObjectName(QString::fromUtf8("Password_Input"));
        Password_Input->setGeometry(QRect(120, 160, 151, 31));
        Password_Input->setFont(font3);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 230, 81, 31));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 230, 81, 31));
        pushButton_2->setFont(font1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "IP\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Login", "\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        IP_Input->setText(QApplication::translate("Login", "166.111.80.5", 0, QApplication::UnicodeUTF8));
        Port_Input->setText(QApplication::translate("Login", "21", 0, QApplication::UnicodeUTF8));
        UserName_Input->setText(QApplication::translate("Login", "anonymous", 0, QApplication::UnicodeUTF8));
        Password_Input->setText(QApplication::translate("Login", "networking", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Login", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Login", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
