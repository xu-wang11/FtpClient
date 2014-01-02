/********************************************************************************
** Form generated from reading UI file 'property.ui'
**
** Created: Mon Oct 28 00:38:55 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTY_H
#define UI_PROPERTY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Property
{
public:
    QLabel *Icon;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *filetype;
    QLabel *filesize;
    QLabel *filetime;
    QLineEdit *filename;

    void setupUi(QWidget *Property)
    {
        if (Property->objectName().isEmpty())
            Property->setObjectName(QString::fromUtf8("Property"));
        Property->resize(341, 248);
        Icon = new QLabel(Property);
        Icon->setObjectName(QString::fromUtf8("Icon"));
        Icon->setGeometry(QRect(20, 10, 61, 50));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Icon->sizePolicy().hasHeightForWidth());
        Icon->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        Icon->setFont(font);
        line = new QFrame(Property);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 70, 311, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Property);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 51, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Property);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 160, 54, 12));
        label_3->setFont(font);
        label_4 = new QLabel(Property);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 111, 31));
        label_4->setFont(font);
        filetype = new QLabel(Property);
        filetype->setObjectName(QString::fromUtf8("filetype"));
        filetype->setGeometry(QRect(140, 110, 121, 21));
        filetype->setFont(font);
        filesize = new QLabel(Property);
        filesize->setObjectName(QString::fromUtf8("filesize"));
        filesize->setGeometry(QRect(140, 160, 91, 16));
        filesize->setFont(font);
        filetime = new QLabel(Property);
        filetime->setObjectName(QString::fromUtf8("filetime"));
        filetime->setGeometry(QRect(140, 190, 121, 31));
        filetime->setFont(font);
        filename = new QLineEdit(Property);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(100, 20, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        filename->setFont(font1);

        retranslateUi(Property);

        QMetaObject::connectSlotsByName(Property);
    } // setupUi

    void retranslateUi(QWidget *Property)
    {
        Property->setWindowTitle(QApplication::translate("Property", "Form", 0, QApplication::UnicodeUTF8));
        Icon->setText(QApplication::translate("Property", "File", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Property", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Property", "Size:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Property", "timestamp:", 0, QApplication::UnicodeUTF8));
        filetype->setText(QApplication::translate("Property", "TextLabel", 0, QApplication::UnicodeUTF8));
        filesize->setText(QApplication::translate("Property", "TextLabel", 0, QApplication::UnicodeUTF8));
        filetime->setText(QApplication::translate("Property", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Property: public Ui_Property {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTY_H
