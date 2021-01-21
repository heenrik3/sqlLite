#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <cstdbool>
#include <vector>
#include <string>
#include <new>

#include "sqlite3.h"
#include "ResourceBundle.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

std::string getSqlCommand();    // returns a string containing an sql command by the user
void getMapValues(std::map<std::string,
                  std::string> m,
                  std::string messages[3]);

class Database
{
    public:

      Database();
      virtual ~Database();
      void close();
      void createOrOpenDatabase();
      void createTable();
      void insertData();
      void deleteTable();


    private:
      sqlite3 *db;                    // database connection
      ResourceBundle *resources;      // holds strings resources to be used

      bool isDatabaseOpen();
      void execSQL(std::string messages[3]);
      void setResourceAndExec(std::map<std::string, std::string> m);

};
#endif // DATABASE_HPP
