#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QException>

class fileOpenException: public std::exception
{
        const char *what() const throw() {return "Can not open file!!!";}
};

#endif // MYEXCEPTION_H
