#include "fileicon.h"
#include <time.h>
#include <QVector>
#include <QMap>
#include <QPainter>
#include<QWidget>
#include <QStyle>
#include "ftpparser.h"
#include <QBrush>
#include "mainwindow.h"
#include "property.h"
#include <QFileDialog>
#include <QMessageBox>
FileIcon::FileIcon(struct ftpparse _file, Client* _c)
{
    this->filename = _file.name;
    this->CreateTime = ctime(&(_file.mtime));
    this->size = _file.size;
    this->IsDir = _file.flagtrycwd;
    this->setIconPath();
    size = 128;
    this->isSelected = false;
    this->client = _c;
    this->window = NULL;



}

void FileIcon::setIconPath()
{
    QMap<QString, QString> SupportFileType;
    SupportFileType.insert(".accdb", "ACCDB");
    SupportFileType.insert(".avi", "AVI");
    SupportFileType.insert(".bmp", "BMP");
    SupportFileType.insert(".css", "CSS");
    SupportFileType.insert(".doc","DOC");
    SupportFileType.insert(".docx", "DOC");
    SupportFileType.insert(".gif", "GIF");
    SupportFileType.insert(".html", "HTML");
    SupportFileType.insert(".cshtml", "HTML");
    SupportFileType.insert(".xhtml", "HTML");

    SupportFileType.insert(".mp3", "WMA");
    SupportFileType.insert(".mp4", "MOV");

    SupportFileType.insert(".png", "PNG");
    SupportFileType.insert(".ppt", "PPT");
    SupportFileType.insert(".pptx", "PPT");
    SupportFileType.insert(".psd", "PSD");
    SupportFileType.insert(".rar", "RAR");

    SupportFileType.insert(".sys", "SET");
    SupportFileType.insert(".txt", "TXT");
    SupportFileType.insert(".wav", "WAV");
    SupportFileType.insert(".xls", "EXCEL");
    SupportFileType.insert(".zip", "ZIP");
    SupportFileType.insert(".xml", "XML");
    if(this->IsDir == true)
    {
        this->iconpath = ":/images/images/DIR.png";
        return;
    }
    else
    {

        QMap<QString, QString>::Iterator it;
        for(it = SupportFileType.begin(); it != SupportFileType.end(); it ++)
        {
            if(this->filename.endsWith(it.key()))
            {
                this->iconpath = ":/images/images/" + it.value() +".png";
                return;
            }
        }
    }
    this->iconpath = ":/images/images/READ.png";


}

void FileIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isSelected == true)
    {
        QBrush *b = new QBrush();
        b->setColor(QColor(72, 180, 242));
        painter->setBrush(*b);
        //  painter->drawRect(0, 0, 128, 128);
        painter->fillRect(0, 0, 100, 120, QColor(143, 197, 228));
    }
    QPixmap  pix;
    pix.load(this->iconpath);
    painter->drawPixmap(0, 0, 100, 100, pix);
    QString name = filename.size() > 10?filename.mid(0, 10) + "...":filename;
    painter->drawText(0, 50, 100, 120, Qt::AlignCenter, name);
   // painter->drawRect(QRectF(-10, -10, 10, 10));

}

QRectF FileIcon::boundingRect()const
{
    return QRectF(0, 0, 100, 120);
}

/**QPainterPath FileIcon::shape()
{

}*/
void FileIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        for(int i = 0; i < this->window->files.size(); i ++)
        {
            this->window->files.at(i)->isSelected = false;
           // this->window->files.at(i)->update(this->window->files.at(i)->boundingRect());
        }
        this->isSelected = !this->isSelected;
        this->window->scene->update();
        return;
    }

}

void FileIcon::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
        QMenu menu;
        menu.addAction("Save As");
        menu.addAction("Property");
       // if(this->IsDir == true)
        //menu.actions().at(0)->set;
        QAction *a = menu.exec(event->screenPos());
        if(a->text() == "Save As")
        {
            QStringList list = this->filename.split('.');
            QString str = list.at(list.length() - 1);
            QString filter = "Ftp:(*." + str + ")";
            QString path = QFileDialog::getSaveFileName(NULL, "Save As", this->filename, filter);
             if(!path.isEmpty())
             {
                   this->window->client->SaveAs(path, this->filename);
             }
        }
        else if(a->text() == "Property")
        {
            Property* p = new Property(this->iconpath, this->filename, this->IsDir?QString("Directory"):QString("File"), QString::number(this->FileSize) +QString("B"), this->CreateTime);
            p->show();

        }
}

void FileIcon::SaveAs()
{

}

void FileIcon::ViewProperty()
{


}

void FileIcon::setMainWindow(MainWindow* _w)
{
    this->window = _w;
}

void FileIcon::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * e)
{
    if(this->IsDir)
    {

        this->window->client->Exec_CWD(this->filename);


        this->window->client->GetDirsInfo();
    }

}



