#ifndef FILETHREAD_H
#define FILETHREAD_H
#include <QFile>
#include <QThread>
class Client;
class FileThread : public QThread
{
    Q_OBJECT
public:
    explicit FileThread(QObject *parent = 0, Client* c= NULL);
protected:
     void run();
    Client* client;
signals:
    
public slots:
    
};

#endif // FILETHREAD_H
