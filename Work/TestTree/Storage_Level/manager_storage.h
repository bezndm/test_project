#ifndef MANAGERSTORAGE_H
#define MANAGERSTORAGE_H

#include "country_storage.h"
#include "operator_storage.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QString>
#include <QDebug>

class ManagerStorage : public QObject
{
    Q_OBJECT
public:
    ManagerStorage(QSqlDatabase *db);
    virtual ~ManagerStorage(void);

    bool select_all_countries_from_lists();
    bool select_all_operators_from_lists();



    bool insert_operator(OperatorStorage Storage);
    bool update_operator(OperatorStorage Storage);

    QList<CountryStorage> listCountryStorage;
    QList<OperatorStorage> listOperatorStorage;


private:
    QSqlQuery *query;


};

#endif // MANAGERSTORAGE_H
