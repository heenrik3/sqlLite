#include <iostream>
#include "include/Database.hpp"

int main(int argc, char const *argv[])
{
    Database* db = new Database();
    db->open("f.db");
    delete db;
    return 0;
}
