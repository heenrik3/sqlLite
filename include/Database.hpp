#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <iostream>
#include <cstdbool>
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

      std::string getSQLCommand();              // returns a string containing an sql command by the user

      bool isDatabaseOpen();

};
#endif // DATABASE_HPP
