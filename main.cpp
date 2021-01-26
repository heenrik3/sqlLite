#include <iostream>
#include "include/Database.hpp"

int main(int argc, char const *argv[])
{
    Database *db = new Database();
    db->createOrOpenDatabase();

    db->changeLocale("pt");
    db->createOrOpenDatabase();


    delete db;
    return 0;
}
