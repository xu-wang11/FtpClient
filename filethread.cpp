#include "filethread.h"
#include "client.h"
FileThread::FileThread(QObject *parent, Client* c) :
    QThread(parent)
{
    this->client = c;
}
void FileThread::run()
{
    QFile file(this->client->path);
    file.open(QIODevice::WriteOnly);

    while(this->client->datasocket.waitForReadyRead())
    {
        file.write(this->client->datasocket.readAll());
    }

    file.close();
    this->client->datasocket.disconnectFromHost();
    if(!this->client->ReceiveMessage())
        return;
    this->exit();

}
