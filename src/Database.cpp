#include "../include/Database.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


Database::Database(std::string path)
{
    this->db = nullptr;

    resources = new Resource_Bundle(path + "database.dat");
}

Database::~Database()
{
    if(isDatabaseOpen())
    {
      close();
    }

    delete resources;

}
/*
void Database::open(std::string tableName)
{
    if (this->isDatabaseOpen())
    {

      std::cout << "Database already open!" << std::endl;

    }

    else {
      bool error = false;

      error = sqlite3_open(tableName.c_str(), &this->db);

      if (error) {
          std::cerr << "Error open DB " << sqlite3_errmsg(this->db) << std::endl;
      } else {
          std::cout << "Opened Database Successfully!" << std::endl;
        }
    }

} */

void Database::close()
{

    if(isDatabaseOpen()) {

      sqlite3_close(db);

      db = nullptr;

    } else {
      std::cout << (*resources->bundle)["notOpen"] << std::endl;
    }

}

void Database::createOrOpenDatabase()
{
    if (createDatabase()) {
        clear();
        std::cout << (*resources->bundle)["error"] << sqlite3_errmsg(this->db) << std::endl;
    }
    else
    {
        clear();
        std::cout << (*resources->bundle)["success"] << std::endl;
    }

}

void Database::execute()
{
    queryExecutor(getQuery());
}
/*
void Database::createTable()
{
    setResourceAndExec(*resources->table_messages);
}

void Database::insertData()
{
    setResourceAndExec(*resources->insert_messages);
}

void Database::deleteTable()
{
    setResourceAndExec(*resources->delete_messages);
}
*/
void Database::changeLocale(std::string path)
{
    resources->modifyBundle(path + "database.dat");
}

bool Database::isDatabaseOpen()
{
    if(db == nullptr)
    {
      return false;
    }

    return true;
}

std::string Database::getQuery()
{
    std::string command;

    clear();
    std::cout << (*resources->bundle)["input"] << std::endl;

    fflush(stdin);

    std::getline(std::cin, command);

    return command;
}
/*
void Database::setResourceAndExec(std::map<std::string, std::string> m)   // this func receives a map containing strings resources,
{                                                                         // test if there's a database connection, asks for SQL command
                                                                          // and pass them to be executed
  if(isDatabaseOpen())
  {
    std::string sql = getSqlCommand();

    execSQL(sql, m);
  }
  else {

    clear();
    std::cout << (*resources->bundle)["notOpen"] << std::endl;
  }
}*/

void Database::queryExecutor(std::string query)     // receives a string containing an sql command,
{                                                               // and a map containing error and success messages
  int exit;
  char* messaggeError;

  exit = sqlite3_exec(db,
                      query.c_str(),      // sql string is converted to char array required by the function
                      NULL,
                      0,
                      &messaggeError);

  if (exit != SQLITE_OK) {

      clear();
      std::cerr << (*resources->bundle)["error"] + " :\n" + query << std::endl;

      sqlite3_free(messaggeError);
  }
  else
  {
    clear();
    std::cout << (*resources->bundle)["success"] << std::endl;
  }

}

bool Database::createDatabase()
{
  const char *dbName;
  std::string tmpName;

  clear();

  std::cout << (*resources->bundle)["name"] << std::endl;

  fflush(stdin);
  std::getline(std::cin, tmpName);

  tmpName += ".db";                       // add .db at the end of string to form "databaseName".db

  dbName = tmpName.c_str();               // databaseName is converted to char array that is required by the sqlite3_open function

  return (bool) sqlite3_open(dbName, &this->db);

}
