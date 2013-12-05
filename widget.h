#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include <QtWidgets>
#include "user.h"
#include "inputLine.h"
#include "myException.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};
class mWin:public QWidget
{
    Q_OBJECT
private:
    smartPointer<QVector<smartPointer<user> > > userList;
    smartPointer<user> current;
    QVBoxLayout* main2;
    QHBoxLayout* main;
    QTextEdit* chat;
    QTableWidget *tab;
    inputLine* write;
    QVBoxLayout* userListWidget;
    QComboBox* userChoiseWidget;
public slots:
    void printMessage(smartPointer<QString> str)
    {
        user* s=(user*)sender();
        QString message=s->returnName()+"<strong><font color=red>:   </font></strong>"+*str;
        chat->append(message);
    }
    void changeCurrentUser(int n)
    {
            if(n==0)
            {
                if(current)
                {
                    current->bot(true);
                    write->setReadOnly(true);
                }

            }
            else
            {
                if(current)
                {
                    current->bot(true);
                    current=userList->at(n-1);
                    current->bot(false);
                    write->setReadOnly(false);
                }
                else
                {
                    current=userList->at(n-1);
                    current->bot(false);
                    write->setReadOnly(false);
                }
            }
    }
    void printFromLineEdit()
    {
        chat->append(current->returnName()+"<strong><font color=red>: </font></strong>"+write->text());
        write->clear();
    }
public:
    mWin(smartPointer<QVector<smartPointer<user> > > userVector)
    {
        userList=userVector;
        current=0;
        main=new QHBoxLayout();
        main2=new QVBoxLayout();
        chat=new QTextEdit();
        tab=new QTableWidget();
        write=new inputLine();
        userListWidget=new QVBoxLayout();
        userChoiseWidget=new QComboBox();
        chat->setReadOnly(true);
        write->setReadOnly(true);
        main->addLayout(userListWidget);
        main->addWidget(chat);
        main2->addLayout(main);
        main2->addWidget(write);
        setLayout(main2);

        userListWidget->addWidget(new QLabel("<font color=green>В чате:</font>"));
        userChoiseWidget->addItem("SPECTATOR");
        for(int i=0;i<userVector->size();++i)
        {
            smartPointer<QLabel> tmp(new QLabel(userVector->at(i)->returnName()));
            userListWidget->addWidget(tmp.standartPointer());
            userChoiseWidget->addItem(userVector->at(i)->returnName());
        }
        userListWidget->addWidget(new QLabel("<font color=green>Вы:</font>"));
        userListWidget->addWidget(userChoiseWidget);
        userListWidget->addStretch();
        //////////////////connect////////////////
        for(int i=0;i<userVector->size();++i)
        {
            connect(userList->at(i),SIGNAL(randomMessage(smartPointer<QString>)),SLOT(printMessage(smartPointer<QString>)));
        }
        connect(userChoiseWidget,SIGNAL(currentIndexChanged(int)),SLOT(changeCurrentUser(int)));
        connect(write,SIGNAL(print()),SLOT(printFromLineEdit()));
    }
};

#endif // WIDGET_H
