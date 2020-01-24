#ifndef CONNECT_DATABASE_H
#define CONNECT_DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QCoreApplication>
#include <QDebug>

class ConnectDatabase
{
public:
    ConnectDatabase();

    QSqlDatabase *database;
};

#endif // CONNECT_DATABASE_H
