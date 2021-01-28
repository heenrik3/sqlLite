#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <cstdbool>
//#include <vector>
#include <string>
#include <new>

#include "sqlite3.h"
#include "Resource_Bundle.hpp"
#include "utilityFunctions.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

class Database
{
    public:

      Database(std::string path);
      virtual ~Database();
      void close();
      void createOrOpenDatabase();
      void execute();

      void changeLocale(std::string path);

    private:
      sqlite3 *db;                                // database connection
      Resource_Bundle *resources;                 // holds a map bundle with strings resources to be used

      bool createDatabase();                      // creates db
      bool isDatabaseOpen();                      // checks if there's a database connection available

      void queryExecutor(std::string sql);        // receives a string with an sql command
/*      void setResourceAndExec(std::map<std::string,
                                std::string> m);  // receives a map with string resources
*/
      std::string getQuery();                // asks for an input and returns a string containing an sql command by the user


};
#endif // DATABASE_HPP
