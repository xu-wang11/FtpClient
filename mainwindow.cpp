#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include "login.h"
#include "ftpparser.h"
#include <string>
#include "fileicon.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QMessageBox>
#include "parselist.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->client = new Client();
    this->ui->action->setDisabled(true);
    //this->ui->action_3->setDisabled(true);
    this->ui->actionRefresh->setDisabled(true);
    // this->connect(this->ui->Connect, SIGNAL(clicked()), this, SLOT(onConnect()));
    this->connect(this->client, SIGNAL(BufferUpdate()), this, SLOT(onReceive()));
    this->connect(this->client, SIGNAL(MessageSended()), this, SLOT(onSend()));
    this->connect(this->client, SIGNAL(DirInfoUpdated()), this, SLOT(onRenderView()));
    this->connect(this->client, SIGNAL(Connect()), this, SLOT(onConnect()));
    this->connect(this->client, SIGNAL(DisConnect()), this, SLOT(onDisconnect()));
    this->connect(this->client, SIGNAL(AtRoot()), this, SLOT(onDisableBack()));
    this->connect(this->client, SIGNAL(Error(QString)), this, SLOT(onSocketError(QString)));
    this->ui->textEdit->setFont(QFont("Courier", 8));
    this->scene = new QGraphicsScene();
    this->ui->graphicsView->setScene(scene);
    QSize p = this->ui->graphicsView->size();
    this->ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop);
   this->ui->graphicsView->setSceneRect(50, 50, p.width() + 50, p.height() + 50);
    // this->ui->graphicsView->centerOn(- p.width() /2, - p.height() / 2);
    this->ui->graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
   //this->ui->graphicsView->setasetAcceptHoverEvents(true);
   this->ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
   // this->ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->scene->setSceneRect(-p.width(), -2 * p.height(), 0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReceive()
{


    this->ui->textEdit->moveCursor (QTextCursor::End);
    this->ui->textEdit->setTextColor(Qt::blue);
    this->ui->textEdit->insertPlainText ("[S]" + this->client->buffer);
    this->ui->textEdit->moveCursor (QTextCursor::End);

}

void MainWindow::onSend()
{


    this->ui->textEdit->moveCursor (QTextCursor::End);
    this->ui->textEdit->setTextColor(Qt::black);
    this->ui->textEdit->insertPlainText ("[C]" + this->client->Message);
    this->ui->textEdit->moveCursor (QTextCursor::End);

}

void MainWindow::onRenderView()
{
    for(int i = 0; i < this->files.length(); i ++)
    {
        //if(this->scene->c)
        this->scene->removeItem(this->files.at(i));
    }
    this->files.clear();

    QStringList lists = this->client->dirInfos.split('\n');
    int width = this->ui->graphicsView->width();
   // int height = this->ui->graphicsView->height();
    QPoint q = this->ui->graphicsView->mapFromScene(0, 0);

    int n = width / 128;
    QTextCodec *codec = QTextCodec::codecForName("gb18030");
   // QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    for(unsigned int i = 0; i < lists.size() - 1; i ++)
    {
        int j = i % n;
        int k = i / n;
        struct ftpparse f;
        //char buf[200];
        string str = lists[i].toStdString();
        int n = str.length();

        char* buf = new char[n];
       // int n = lists[i].toStdString().length();


        const char* temp = str.c_str();
        int index;

        for(index = 0; index < n; index ++)
        {
            if(temp[index] == '\r')
                break;
            buf[index] =   temp[index];
        }
        buf[index] = '\0';
        ftpparse(&f, buf, index);
        if(f.name == NULL)
            continue;
        FileIcon *fi = new FileIcon(f, this->client);
        fi->setMainWindow(this);
        this->files.push_back(fi);
        fi->setPos(j * 128 + 100, k * 128 + 100);
        scene->addItem(fi);

        qDebug()<<f.name;

    }
    this->update();
}

void MainWindow::onLogin()
{
    this->client->LogOut();
    this->RemoveAllFiles();
    this->ui->textEdit->clear();
    this->files.clear();
    Login* login = new Login(this->client, this);
    login->show();
}

void MainWindow::RemoveAllFiles()
{
    int l = this->files.count();
    for(int i = 0; i < l; i ++)
    {
        this->scene->removeItem(this->files.at(i));

    }
}

void MainWindow::onBack()
{

}
void MainWindow::onUpload()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("All Files(*.*)"));
    if(this->client->socket.isOpen())
    {
        this->client->UploadFile(path);
    }
    else
    {
        QMessageBox::warning(NULL, tr("warning"), tr("No connection"));
    }
}

void MainWindow::onConnect()
{
    this->ui->action->setEnabled(true);
    this->ui->actionRefresh->setEnabled(true);
}

void MainWindow::onDisconnect()
{
    this->ui->action->setDisabled(true);
    //this->ui->action_3->setDisabled(true);
    this->ui->actionRefresh->setDisabled(true);
}

void MainWindow::onDisableBack()
{
    //this->ui->action_3->setDisabled(true);
}

void MainWindow::onSocketError(QString error)
{
    QMessageBox::warning(NULL, tr("warning"), error);
}

void MainWindow::onRefreshWindow()
{
    int cur = this->files.length();
    for(int i = cur - 1; i >= 0; i --)
    {
        this->scene->removeItem(files.at(i));

    }
    files.clear();
    this->client->GetDirsInfo();

}
void MainWindow::onNewfolder()
{
  //  this
}

