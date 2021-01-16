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
      void open(std::string);
      void close();
      void createDatabase();
      void createTable();
      void deleteTable();
      void insertData();


    private:
      sqlite3 *db;            // database pointer

      std::string getSQLCommand();              // return a string containing an sql command by the user
      void sqlExec(std::string command[3]);     // receives an string array containing a comand, a positive and negative error messages
      void sqlExecInsDel(std::string command[3]);  //
      bool isDatabaseOpen();

};
#endif // DATABASE_HPP
