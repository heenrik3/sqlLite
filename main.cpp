#include <iostream>
#include "include/Database.hpp"

int main(int argc, char const *argv[])
{
    Database* db = new Database();
    
    delete db;
    return 0;
}
