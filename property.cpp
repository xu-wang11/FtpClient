#include "property.h"
#include "ui_property.h"

Property::Property(QString _path, QString name, QString type, QString size, QString time, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Property)
{
    ui->setupUi(this);
    this->ui->filename->setText(name);
    this->ui->filesize->setText(size);
    this->ui->filetype->setText(type);
    this->ui->filetime->setText(time);
    //path = _path;
    this->ui->Icon->setScaledContents(true);
    this->ui->Icon->setPixmap(QPixmap(_path));


}

Property::~Property()
{
    delete ui;
}
