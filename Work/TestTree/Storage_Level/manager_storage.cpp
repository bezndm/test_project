#include "manager_storage.h"


ManagerStorage::ManagerStorage(QSqlDatabase *database)
{
    this->query = new QSqlQuery(*database);

}

ManagerStorage::~ManagerStorage()
{

}



bool ManagerStorage::select_all_countries_from_lists()
{
    CountryStorage  _countryStorage;
    OperatorStorage _operatorStorage;

    bool result = false;

    query->prepare( "SELECT countries.name, countries.mcc, countries.code, countries.mnc_length FROM countries ORDER BY countries.name ASC");

    result = query->exec();

    if(result == true)
    {
        while(query->next())
        {
            _countryStorage.set_name(query->value(0).toString());
            _countryStorage.set_mcc(query->value(1).toInt());
            _countryStorage.set_code(query->value(2).toString());
            _countryStorage.set_mnc_length(query->value(3).toInt());


            listCountryStorage.append(_countryStorage);

        }

        qDebug() << "Query select_all_countries_from_lists is Succses!";

    }
    else
    {
        qDebug() << "Query is Faild!";
    }

    return result;
}



bool ManagerStorage::select_all_operators_from_lists()
{
    CountryStorage  _countryStorage;
    OperatorStorage _operatorStorage;

    bool result = false;

    query->prepare( "SELECT operators.name, operators.mcc, operators.mnc FROM operators ORDER BY operators.name ASC");

    result = query->exec();

    if(result == true)
    {
        while(query->next())
        {
            _operatorStorage.set_name(query->value(0).toString());
            _operatorStorage.set_mcc(query->value(1).toString());
            _operatorStorage.set_mnc(query->value(2).toString());

            listOperatorStorage.append(_operatorStorage);
        }

        qDebug() << "Query select_all_operators_from_lists is Succses!";

    }
    else
    {
        qDebug() << "Query is Faild!";
    }

    return result;
}





bool ManagerStorage::insert_operator(OperatorStorage Storage)
{
    bool result = false;

    query->prepare(  "INSERT INTO operators ("
                    "name,"
                    "mcc,"
                    "mnc) "

                    "VALUES ( "
                    ":name,"
                    ":mcc,"
                    ":mnc) "
                    );

    query->bindValue(":name",   Storage.get_name());
    query->bindValue(":mcc",    Storage.get_mcc());
    query->bindValue(":mnc",    Storage.get_mnc());


    result = query->exec();

    if(result == true)
    {
        qDebug() << "Query insert_operator is Succses!";
    }
    else
    {
        qDebug() << "Query is Faild!";
    }

    return result;
}



bool ManagerStorage::update_operator(OperatorStorage Storage)
{
    bool result = false;

    query->prepare(  "UPDATE operators SET "
                    "name         =   :name"

                    " WHERE mcc  =   :mcc "
                    "AND mnc = :mnc"
                    );

    query->bindValue(":name",   Storage.get_name());

    query->bindValue(":mcc",    Storage.get_mcc());
    query->bindValue(":mnc",    Storage.get_mnc());



    result = query->exec();



    if(result == true)
    {
        qDebug() << "Query update_operator is Succses!";
    }
    else
    {
        qDebug() << "Query is Faild!";
    }

    return result;

}
