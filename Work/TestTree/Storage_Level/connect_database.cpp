#include "connect_database.h"

ConnectDatabase::ConnectDatabase()
{
    database = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));

    database->setHostName("localhost");
    database->setDatabaseName(QCoreApplication::applicationDirPath() + "/system.db");
   // database->setDatabaseName("C:/Users/Dima Beznosko/Desktop/Work/system.db");
    database->setUserName("");
    database->setPassword("");

    if(database->open())
    {
        qDebug() << "Database Succrss!";
    }
    else
    {
        qDebug() << "Not open Database";
    }
}
