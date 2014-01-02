#-------------------------------------------------
#
# Project created by QtCreator 2013-10-10T13:39:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FtpClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    login.cpp \
    ftpparser.cpp \
    fileicon.cpp \
    property.cpp \
    filethread.cpp

HEADERS  += mainwindow.h \
    client.h \
    login.h \
    ftpparser.h \
    fileicon.h \
    property.h \
    parselist.h \
    qurlinfo.h \
    filethread.h

FORMS    += mainwindow.ui \
    login.ui \
    property.ui

RESOURCES += \
    images.qrc



