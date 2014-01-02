#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include<QtNetwork/QTcpSocket>
#include "client.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(Client* socket, QWidget *parent = 0);
    Client* client;
    ~Login();

private:
    Ui::Login *ui;
public slots:
    bool ConnectServer();

};

#endif // LOGIN_H
