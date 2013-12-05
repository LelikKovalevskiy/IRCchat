#ifndef INPUTLINE_H
#define INPUTLINE_H
#include <QtWidgets>
class inputLine:public QLineEdit
{
    Q_OBJECT
signals:
    void print();
protected:
    void keyPressEvent(QKeyEvent* event)
    {
        if(event->key()==Qt::Key_Enter)
        {
            emit print();
        }
        else
           QLineEdit::keyPressEvent(event);
    }
};

#endif // INPUTLINE_H
