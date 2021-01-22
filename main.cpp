#include <iostream>
#include "include/Database.hpp"

int main(int argc, char const *argv[])
{
    Database* db = new Database();

    bool run = true;

    do {
      std::cout << "\n \tChoose option:" << '\n';
      std::cout << "\n \t1.Create or open database" << '\n';
      std::cout << "\n \t2.Create table database" << '\n';
      std::cout << "\n \t3.Create or open database" << '\n';

    } while (run);
    db->createOrOpenDatabase();

    db->createTable();
    db->insertData();

    delete db;
    return 0;
}
