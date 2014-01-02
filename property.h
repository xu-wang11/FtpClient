#ifndef PROPERTY_H
#define PROPERTY_H

#include <QWidget>

namespace Ui {
class Property;
}

class Property : public QWidget
{
    Q_OBJECT

public:
    explicit Property(QString path, QString name, QString type, QString size, QString time, QWidget *parent = 0);
    QString path;
    ~Property();
//void paintEvent(QPaintEvent *);
private:
    Ui::Property *ui;
};

#endif // PROPERTY_H
