#include<QPainter>
#include<QStyleOptionFrameV2>
#include<QKeyEvent>
#include"IPLineEdit.h"
IPLineEdit::IPLineEdit(QWidget*parent)
    :QLineEdit(parent)
{
    buildingSubLine();
}
IPLineEdit::IPLineEdit(constQString&contents,QWidget*parent)
    :QLineEdit(parent)
{
    buildingSubLine();
    setText(contents);
}
IPLineEdit::~IPLineEdit()
{
    for(inti=0;i<4;i++)
        deletem_pLineEdit[i];
}
voidIPLineEdit::buildingSubLine()
{
    //QRegExprx("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-4]|[01]?\\d\\d?)");
#if0///掩码的情况
    QRegExp rx0("(2[0-1]\\d|22[0-3]|1\\d\\d|[1-9]\\d|[1-9])");///第一项目的范围为1-223
    QRegExpValidator* validator0=new QRegExpValidator(rx0,this);
#endif
    QRegEx prx("(2[0-4]\\d|25[0-5]|1\\d\\d|[1-9]?\\d)");///排除0\\d的情况
    QRegExpValidator* validator=newQRegExpValidator(rx,this);
    for(inti=0;i<4;i++)
    {
        m_pLineEdit[i]=newQLineEdit(this);
        m_pLineEdit[i]->setFrame(false);
        m_pLineEdit[i]->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        m_pLineEdit[i]->setMaxLength(3);
        m_pLineEdit[i]->setValidator(validator);
        m_pLineEdit[i]->show();
        m_pLineEdit[i]->installEventFilter(this);
    }
}
bool IPLineEdit::eventFilter(QObject*obj,QEvent*event)
{
    if(children().contains(obj)&&event->type()==QEvent::KeyPress)
    {
        QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
        QLineEdit*line=qobject_cast<QLineEdit*>(obj);
        QString text=line->text();
        const QRegExpValidator*validator=NULL;
        intpos=0;
        switch(keyEvent->key()){
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
            text+=keyEvent->text();
            validator=qobject_cast<constQRegExpValidator*>(line->validator());
            if(validator->validate(text,pos)==QValidator::Acceptable&&text.length()==3)
                for(int i=0;i<3;i++){
                    if(m_pLineEdit[i]==line){
                        line->insert(keyEvent->text());
                        m_pLineEdit[i+1]->setFocus();
                        m_pLineEdit[i+1]->selectAll();
                        return true;
                    }
                }
            return QObject::eventFilter(obj,event);
        case Qt::Key_Backspace:
            if(text.isEmpty())
                for(int i=3;i>0;i--){
                    if(m_pLineEdit[i]==line){
                        m_pLineEdit[i-1]->setFocus();
                        m_pLineEdit[i-1]->setCursorPosition(m_pLineEdit[i-1]->text().length());
                        m_pLineEdit[i-1]->backspace();
                        return true;
                    }
                }
            return QObject::eventFilter(obj,event);
        case Qt::Key_Left:
            if(line->cursorPosition()==0)
                for(int i=3;i>0;i--){
                    if(m_pLineEdit[i]==line){
                        m_pLineEdit[i-1]->setFocus();
                        m_pLineEdit[i-1]->setCursorPosition(m_pLineEdit[i-1]->text().length());
                        returntrue;
                    }
                }
            return QObject::eventFilter(obj,event);
        case Qt::Key_Right:
            if(line->cursorPosition()==text.length())
                for(int i=0;i<3;i++){
                    if(m_pLineEdit[i]==line){
                        m_pLineEdit[i+1]->setFocus();
                        m_pLineEdit[i+1]->setCursorPosition(0);
                        return true;
                    }
                }

        }
    }
    return true;
}
