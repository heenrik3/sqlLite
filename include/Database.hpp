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

void clear();

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
      sqlite3 *db;                                 // database connection
      ResourceBundle *resources;                  // holds a map bundle with strings resources to be used

      bool isDatabaseOpen();                      // checks if there's a database connection available
      std::string getSqlCommand();                // returns a string containing an sql command by the user
      void execSQL(std::string sql,
                    std::map<std::string,
                     std::string> m);             // receives a string with an sql command and a map
      void setResourceAndExec(std::map<std::string,
                                std::string> m);  // receives a map with resources

};
#endif // DATABASE_HPP
