#include "client.h"
#include <exception>
#include <iostream>
#include <QStringList>
#include <QTextCodec>
#include <fstream>
#include <QFile>
#include "filethread.h"

using namespace std;

Client::Client()
{
    this->IsConnect = false;
}

bool Client::InitConnect(QString _ip, int _port, QString name, QString pass)
{
    this->LoginName = name;
    this->LoginPassword = pass;
    this->addr.setAddress(_ip);
    this->port = _port;
    try
    {
        this->Message = "ftp try to connect to" + _ip +":" + _port + "...\n";

        this->socket.connectToHost(this->addr, port);
        emit MessageSended();
    }
    catch(...)
    {
        return false;
    }
    if(this->socket.state()  == QAbstractSocket::UnconnectedState)
    {
        emit Error("Cannot connect to Host!");
        return false;
    }
    if(ReceiveMessage()== false)
        return false;
    Exec_USER(name);
    Exec_PASS(pass);
    this->IsConnect = true;
    emit Connect();
    this->Exec_PWD();
    GetDirsInfo();
    return true;
}
/**
  *ReceiveMessage can receive one message once. one message = StatusCode + ' '...
  */
bool Client::ReceiveMessage()
{
    buffer.clear();
    QString recv;
    int flag = true;
    while(this->socket.waitForReadyRead())
    {
            flag = false;
            recv = this->socket.readAll();
            buffer.append(recv);
            if(recv[3] == ' '){
                this->CMD = recv;
                this->StatusCode = this->CMD.mid(0, 3).toInt();
                if(this->StatusCode >= 400)
                {
                    emit Error(this->CMD);
                    return false;
                }
                break;
            }
    }
    if(flag)
    {
        emit Error("cannot receive from Server");
        return false;
    }
    emit BufferUpdate();
    return true;

}

bool Client::SendMessage(QString str)
{
    this->Message = str;
    if(this->socket.write(str.toStdString().c_str(), str.toStdString().length())<0)
    {
        emit Error("cannot send to Server");
        return false;
    }
    if(this->socket.waitForBytesWritten())
    {
        emit MessageSended();
        return true;
    }
    emit Error("send time out.");
    return false;

}

void Client::Login()
{

}

void Client::GetDirsInfo()
{
    Exec_PASV();

    if(!this->SendMessage("CLNT \r\n"))
        return;
    if(!ReceiveMessage())
        return;
    if(!SendMessage("OPTS UTF8 ON\r\n"))
        return;
    if(!ReceiveMessage())
        return;
    Exec_LIST();
}

//FORMAT: USER
void Client::Exec_USER(QString name)
{
    if(!SendMessage("USER " + name + "\r\n"))
        return;
    if(!ReceiveMessage())
        return;
}
//FORMAT: PASS
void Client::Exec_PASS(QString pass)
{
    if(!SendMessage("PASS " + pass + "\r\n"))
        return;
    if(!ReceiveMessage())
        return;
}

//FORMAT:PASV
void Client::Exec_PASV()
{
    if(!SendMessage("PASV\r\n"))
        return;

    if(!ReceiveMessage())
        return;

    QStringList sub = CMD.split('(')[1].split(',');
    int a[6];
    for(int i = 0; i < sub.length() - 1; i ++)
    {
        a[i] = sub.at(i).toInt();
    }
    a[5] = sub.at(5).split(')').at(0).toInt();

    QString ip = QString::number(a[0])+ "."+ QString::number(a[1])+"." + QString::number(a[2])+"." + QString::number(a[3]);
    this->datasocket.connectToHost(ip, a[4] * 256 + a[5]);
}

void Client::Exec_PORT()
{

}

void Client::Exec_SYST()
{
    if(!SendMessage("SYST\r\n"))
        return;
    if(!ReceiveMessage())
        return;
}

void Client::Exec_TYPE()
{
    if(!SendMessage("TYPE I\r\n"))
        return;
    if(!ReceiveMessage())
        return;
}

void Client::Exec_LIST()
{
    QString str="LIST\r\n";
    if(!SendMessage(str))
        return;
    if(!ReceiveMessage())
        return;
    this->dirInfos.clear();
    while(this->datasocket.waitForReadyRead())
    {


            QByteArray array = this->datasocket.readAll();

            this->dirInfos.append(QString::fromUtf8(array));

    }
    this->datasocket.close();
    emit DirInfoUpdated();
     if(!ReceiveMessage())
         return;



}

void Client::Exec_RETR(QString path, QString filename)
{
    if(!SendMessage("RETR " + filename + "\r\n"))
        return;
    if(!ReceiveMessage())
        return;
    this->path = path;
    this->name = filename;
    FileThread * thread = new FileThread(NULL, this);
    this->datasocket.moveToThread(thread);
    thread->start();


}

void Client::Exec_STOR(QString path)
{
    QStringList lists = path.split('/');
    if(!SendMessage("STOR " + lists.at(lists.length() - 1) + "\r\n"))
        return;
     if(!ReceiveMessage())
         return;
    if(this->StatusCode == 150)
    {
        bool flag = this->datasocket.waitForConnected();
        if(flag)
        {
            QFile file(path);
            file.open(QIODevice::ReadOnly);
            while(!file.atEnd())
            {
                QByteArray buf = file.read(1000);
                this->datasocket.write(buf);
                this->datasocket.waitForBytesWritten();
            }
            this->datasocket.close();
        }
        if(!ReceiveMessage())
            return;
    }
}

void Client::Exec_DELE()
{

}

void Client::Exec_MKD()
{

}

void Client::Exec_RMD()
{

}

void Client::Exec_SIZE()
{

}

void Client::Exec_RNFR()
{

}

void Client::Exec_RNTO()
{

}

void Client::Exec_QUIT()
{

}

void Client::Exec_HELP()
{

}

void Client::Exec_CWD(QString dir)
{
    QString path = this->CurrentPath + dir;
    if(!SendMessage("CWD " + path + "\r\n"))
        return;
    if(!ReceiveMessage())
        return;
    this->CurrentPath = path + "/";
}

void Client::Exec_PWD()
{
    if(!SendMessage("PWD\r\n"))
        return;
    if(!ReceiveMessage())
        return;
    int first = CMD.indexOf('\"');
    int end = CMD.indexOf("\"", first + 1);
    this->root = CMD.mid(first + 1, end - first - 1);
    this->CurrentPath = this->root;
}

void Client::LogOut()
{
    this->addr.clear();
    this->port = 0;
    this->buffer.clear();
    this->root.clear();
    this->CMD.clear();
    this->CurrentPath.clear();
    this->socket.close();
    this->datasocket.close();
}

void Client::UploadFile(QString path)
{
    this->Exec_PASV();
    this->Exec_STOR(path);

}

void Client::SaveAs(QString path, QString filename)
{
    Exec_PASV();
    Exec_RETR(path, filename);
}

