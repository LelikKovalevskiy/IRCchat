#ifndef USER_H
#define USER_H
#include <QString>
#include <QList>
#include <QVector>
#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QTimer>
#include "smartPointer.h"

class user:public QObject
{
    Q_OBJECT;
private:
    smartPointer <QString> name;
    bool isBot;
    smartPointer <QVector<smartPointer<QString> > > base;

signals:
    void randomMessage(smartPointer <QString>);
public:
    user(const char *n, smartPointer <QVector<smartPointer<QString> > > b):base(b),isBot(true)
    {
        smartPointer<QString> tmp(new QString(n));
        name=tmp;
        startTimer(rand()%4000+5000);
    }
    void sentMessage()
    {
        srand(time(NULL));
        emit randomMessage(base->at(rand()%(base->size()-2)+1));
    }
    QString returnName()
    {
        return *name;
    }
    void bot(bool b)
    {
        isBot=b;
    }

protected:
    void timerEvent(QTimerEvent* event)
    {
        if(isBot)
        sentMessage();
    }

};

#endif // USER_H
