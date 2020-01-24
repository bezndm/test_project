#include "operator_storage.h"

OperatorStorage::OperatorStorage()
{

}

//setters

void OperatorStorage::set_mcc(QString new_set_mcc)
{
    mcc = new_set_mcc;
}

void OperatorStorage::set_mnc(QString new_set_mnc)
{
    mnc = new_set_mnc;
}

void OperatorStorage::set_name(QString new_set_name)
{
    name = new_set_name;
}


// getters

QString OperatorStorage::get_mcc()
{
    return mcc;
}

QString OperatorStorage::get_mnc()
{
    return mnc;
}

QString OperatorStorage::get_name()
{
    return name;
}
