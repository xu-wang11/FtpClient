#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include "client.h"
#include "fileicon.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void RemoveAllFiles();
public:
    Ui::MainWindow *ui;
    Client* client;
    QFont Black;
    QFont Red;
    QFont Green;
    QGraphicsScene* scene;
    QList<FileIcon*> files;
    QString root;
    QString curPath;

public slots:
    void onReceive();
    void onSend();
    void onRenderView();
    void onLogin();
    void onBack();
    void onUpload();
    void onConnect();
    void onDisconnect();
    void onDisableBack();
    void onSocketError(QString error);
    void onRefreshWindow();
    void onNewfolder();

};

#endif // MAINWINDOW_H
