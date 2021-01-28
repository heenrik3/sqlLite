#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <cstdbool>
#include <vector>
#include <string>
#include <new>

#include "sqlite3.h"
#include "ResourceBundle.hpp"
#include "utilityFunctions.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

class Database
{
    public:

      Database();
      virtual ~Database();
      void close();
      void createOrOpenDatabase();
      void execute(std::string query);
      /*
      void createTable();
      void insertData();
      void deleteTable();*/

      void changeLocale();

    private:
      sqlite3 *db;                                // database connection
      ResourceBundle *resources;                  // holds a map bundle with strings resources to be used

      bool createDatabase();                      // creates db
      bool isDatabaseOpen();                      // checks if there's a database connection available

      void execSQL(std::string sql,
                    std::map<std::string,
                     std::string> m);             // receives a string with an sql command and a map
      void setResourceAndExec(std::map<std::string,
                                std::string> m);  // receives a map with string resources

      std::string getSqlCommand();                // asks for an input and returns a string containing an sql command by the user


};
#endif // DATABASE_HPP
