#ifndef FILEICON_H
#define FILEICON_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include "client.h"
struct ftpparse;
class MainWindow;
class FileIcon: public QGraphicsItem
{

public:
    FileIcon(struct ftpparse ftp, Client* client);
public:
    QString filename;
    QString iconpath;
    int size;
    QString CreateTime;
    int FileSize;
    bool IsDir;
    bool isSelected;
    QMenu* menu;
    QAction* property;
    QAction* saveAsFile;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * e );
    QRectF boundingRect()const;
    Client* client;
    MainWindow* window;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //QPainterPath shape()const;

    void setIconPath();
    void setMainWindow(MainWindow* _w);

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
public slots:
    void ViewProperty();
    void SaveAs();


};

#endif // FILEICON_H
