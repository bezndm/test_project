#ifndef COUNTRIESSTORAGE_H
#define COUNTRIESSTORAGE_H

#include <QString>
#include <QDebug>
#include <QSqlDatabase>

#include <stdlib.h>
#include <string.h>
#include <iostream>


class OperatorStorage
{
public:
    OperatorStorage();

    //setters
    void        set_mcc(QString new_set_mcc);
    void        set_mnc(QString new_set_mnc);
    void        set_name(QString new_set_name);

    // getters
    QString     get_mcc(void);
    QString     get_mnc(void);
    QString     get_name(void);

private:
    QString     mcc;
    QString     mnc;
    QString     name;

};

#endif // COUNTRIESSTORAGE_H
