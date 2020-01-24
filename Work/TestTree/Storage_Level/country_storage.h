#ifndef COUNTRIES_STORAGE_H
#define COUNTRIES_STORAGE_H

#include <QString>
#include <QDebug>
#include <QSqlDatabase>

#include <stdlib.h>
#include <string.h>
#include <iostream>

class CountryStorage
{
public:
    CountryStorage();

    //setters
    void  set_mcc(int new_set_mcc);
    void  set_code(QString new_set_code);
    void  set_name(QString new_set_name);
    void  set_mnc_length(int new_set_mnc_length);

    // getters
    int         get_mcc(void);
    QString     get_code(void);
    QString     get_name(void);
    int         get_mnc_length(void);

private:
    int mcc;
    QString code;
    QString name;
    int mnc_length;
};

#endif // COUNTRIES_STORAGE_H
