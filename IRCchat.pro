#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T02:59:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IRCchat
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    user.h \
    inputLine.h \
    myException.h \
    smartPointer.h

OTHER_FILES += \
    base.txt
