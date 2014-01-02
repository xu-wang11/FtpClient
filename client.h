///Client 封装了socket

#ifndef CLIENT_H
#define CLIENT_H
#include<QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

class Client:public QObject
{
    Q_OBJECT
public:
    Client();
public:
    QHostAddress addr;
    int port;
    QString LoginName; //登陆用户名
    QString LoginPassword;//用户名密码
    QTcpSocket socket;
    QTcpSocket datasocket;
    int    StatusCode;//cur
    QString root;
    QString CurrentPath;
    QString path;
    QString name;
    bool InitConnect(QString ip, int port, QString name, QString pass);

    bool SendMessage(QString str);

    bool ReceiveMessage();
    void Login();
    void LogOut();
    void UploadFile(QString path);
    void GetDirsInfo();
    void RetriveFile(QString str);
    void Receive_MSG();
    void SaveAs(QString path, QString filename);
public:
    void Exec_USER(QString name);
    void Exec_PASS(QString pass);
    void Exec_PASV();
    void Exec_PORT();
    void Exec_SYST();
    void Exec_CDUP();
    void Exec_TYPE();
    void Exec_LIST();
    void Exec_RETR(QString path, QString name);
    void Exec_STOR(QString path);
    void Exec_DELE();
    void Exec_MKD();
    void Exec_RMD();
    void Exec_SIZE();
    void Exec_RNFR();
    void Exec_RNTO();
    void Exec_QUIT();
    void Exec_HELP();
    void Exec_CWD(QString path);
    void Exec_PWD();

public:
    QString buffer;//缓存收到的数据
    QString CMD; // cmd
    QString dirInfos;
    QString Message;
    bool IsConnect;


    //void GetDirsInfo();
signals:
    void BufferUpdate();
    void MessageSended();
    void DirInfoUpdated();
    void Connect();
    void DisConnect();
    void AtRoot();
    void Error(QString error);

};

#endif // CLIENT_H
