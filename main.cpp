#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    MainWindow w;
    w.setFixedSize( QApplication::desktop()->width(),  QApplication::desktop()->height());

    w.showMaximized();

    return a.exec();
}
