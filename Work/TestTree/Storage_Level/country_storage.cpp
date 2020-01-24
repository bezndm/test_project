#include "country_storage.h"

CountryStorage::CountryStorage()
{

}

//setters

void CountryStorage::set_mcc(int new_set_mcc)
{
    mcc = new_set_mcc;
}

void CountryStorage::set_code(QString new_set_code)
{
    code = new_set_code;
}

void CountryStorage::set_name(QString new_set_name)
{
    name = new_set_name;
}

void CountryStorage::set_mnc_length(int new_set_mnc_length)
{
    mnc_length = new_set_mnc_length;
}

// getters

int CountryStorage::get_mcc()
{
    return mcc;
}

QString CountryStorage::get_code()
{
    return code;
}

QString CountryStorage::get_name()
{
    return name;
}

int CountryStorage::get_mnc_length()
{
    return mnc_length;
}
