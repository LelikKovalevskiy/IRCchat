#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QVector>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>
#include <QString>
#include <QTextStream>
#include <myException.h>
#include "smartPointer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    smartPointer <QVector<smartPointer<QString> > > baseInVector(new QVector<smartPointer<QString> >());
    QString tmp;
    QFile file("base.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        srand(time(NULL));
        QTextStream in(&file);
        while(!in.atEnd())
       {
           smartPointer<QString> phrase(new QString());
           for(int i=0,r=rand()%4+3;i<r;++i)
           {
               in>>tmp;
               if(in.atEnd())
               {
                   (*phrase)+=tmp;
                   baseInVector->push_back(phrase);
                   break;
               }
               (*phrase)+=tmp;
               (*phrase)+=" ";
           }
           baseInVector->push_back(phrase);
       }
        file.close();
    }
    smartPointer<user>first(new user("Alexey Kovalevskiy",baseInVector));
    smartPointer<user>second(new user("Alesix",baseInVector));
    smartPointer<user>third(new user("Anna Masalska",baseInVector));
    smartPointer<user>fourth(new user("Zhenya Troshko",baseInVector));
    smartPointer<QVector<smartPointer<user> > > userList(new  QVector<smartPointer<user> >);
    userList->push_back(first);
    userList->push_back(second);
    userList->push_back(third);
    userList->push_back(fourth);
    mWin* win=new mWin(userList);
    win->resize(800,600);
    win->show();
    return a.exec();
}
