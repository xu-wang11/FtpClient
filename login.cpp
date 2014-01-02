#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include<QMessageBox>
Login::Login(Client* _w, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    this->client = _w;
    ui->setupUi(this);
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(ConnectServer()));

}

Login::~Login()
{
    delete ui;
}
bool Login::ConnectServer()
{
    QRegExp regexp1("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    if(!regexp1.exactMatch(this->ui->IP_Input->text()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("IP Addres Error"));
        this->ui->IP_Input->setFocus();
        return false;
    }
    QRegExp regexp2("(/^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)/)");
    if(!regexp2.exactMatch(this->ui->Port_Input->text()))
    {
        QMessageBox::warning(this, tr("Warning"),tr("Port Error"));
        this->ui->Port_Input->setFocus();
        return false;
    }
    if(this->ui->UserName_Input->text() == "")
    {
        QMessageBox::warning(this, tr("Warning"),tr("No UserName"));
        this->ui->Port_Input->setFocus();
        return false;
    }
    if(this->ui->Password_Input->text() == "")
    {
        QMessageBox::warning(this, tr("Warning"),tr("No Password"));
        this->ui->Port_Input->setFocus();
        return false;
    }
    bool ret = this->client->InitConnect(this->ui->IP_Input->text(), this->ui->Port_Input->text().toInt(), this->ui->UserName_Input->text(), this->ui->Password_Input->text());
    if(ret == true)
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Connect Error"));
    }
    return true;
}

