#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <cstdbool>
#include <ifstream>
#include <vector>
#include <new>

#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

class Database
{
    public:
      Database();
      virtual ~Database();
      void close();
      void createOrOpenDatabase();
      void createTable();
      void deleteTable();
      void insertData();

    private:
      sqlite3 *db;            // database connection

      void getResources();
      std::string getSqlCommand();   // returns a string containing an sql command by the user

      void execSQL(std::string messages[3]);
      bool isDatabaseOpen();


};
#endif // DATABASE_HPP
