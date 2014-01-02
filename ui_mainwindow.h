/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Oct 28 14:01:17 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect;
    QAction *action_2;
    QAction *action;
    QAction *action_4;
    QAction *actionRefresh;
    QAction *actionNewfolder;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 487);
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QString::fromUtf8("action_connect"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon1);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon2);
        actionNewfolder = new QAction(MainWindow);
        actionNewfolder->setObjectName(QString::fromUtf8("actionNewfolder"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/NewFolder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewfolder->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        textEdit->setFont(font);

        horizontalLayout->addWidget(textEdit);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_connect);
        menu->addSeparator();
        menu->addAction(action_2);
        mainToolBar->addAction(action_4);
        mainToolBar->addAction(action);
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addAction(actionNewfolder);

        retranslateUi(MainWindow);
        QObject::connect(action_4, SIGNAL(triggered()), MainWindow, SLOT(onLogin()));
        QObject::connect(action, SIGNAL(triggered()), MainWindow, SLOT(onUpload()));
        QObject::connect(actionRefresh, SIGNAL(triggered()), MainWindow, SLOT(onRefreshWindow()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245(connect)", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_4->setToolTip(QApplication::translate("MainWindow", "connect", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRefresh->setToolTip(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewfolder->setText(QApplication::translate("MainWindow", "newfolder", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewfolder->setToolTip(QApplication::translate("MainWindow", "add folder", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
