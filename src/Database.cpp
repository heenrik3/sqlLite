#include "../include/Database.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

Database::Database()
{
    this->db = NULL;
}

Database::~Database()
{
    if(this->isDatabaseOpen())
    {
      this->close();
    }

}

void Database::open(std::string tableName)
{
    if (this->isDatabaseOpen())
    {

      std::cout << "Database already open!" << std::endl;

    }

    else {
      bool error = false;

      error = (bool) sqlite3_open(tableName.c_str(), &this->db);

      if (error) {
          std::cerr << "Error open DB " << sqlite3_errmsg(this->db) << std::endl;
      } else {
          std::cout << "Opened Database Successfully!" << std::endl;
        }
    }

}

void Database::close()
{
    if(this->isDatabaseOpen()) {
      sqlite3_close(this->db);
      this->db = NULL;
    } else {

      std::cout << "No open database!" << std::endl;
    }

}

void Database::createDatabase()
{
    bool error = false;                     // boolean to test the return command
    const char *dbName;
    std::string *name = new std::string;

    std::cout << "\n\tDatabase name:" << std::endl;

    fflush(stdin);
    std::getline(std::cin, *name);

    *name = *name + ".db";                 // add .db at the end of string to form "databaseName".db

    dbName = name->c_str();               // databaseName is converted to char array

    error = sqlite3_open(dbName, &this->db);

    if (error) {
        std::cerr << "Error creating DB " << sqlite3_errmsg(this->db) << std::endl;
    } else {
        std::cout << "Database created Successfully!" << std::endl;
      }

    this->close();

    delete name;
}

void Database::createTable()
{

    if(this->isDatabaseOpen())
    {

      std::string command[3] = {" ", "Error creating table!", "Table deleted!"};
      command[1] = this->getSQLCommand();

      this->sqlExecInsDel(command);
    } else {

      std::cout << "No open database!" << std::endl;
    }
}

void Database::deleteTable()
{
  //sql = "DELETE FROM PERSON WHERE ID = 2;";
  std::string command[3] = {" ", "Error deleting table!", "Table deleted!"};
  command[1] = this->getSQLCommand();

  this->sqlExecInsDel(command);

}

void Database::insertData()
{

    std::string command[3] = {"", "Error inserting data!", "New data added!"};
    command[1] = (this->getSQLCommand()); //this->getSQLCommand();

    this->sqlExecInsDel(command);

}

std::string Database::getSQLCommand()
{
  bool running = true;
  std::string cmd = "";
  std::string *temp = new std::string;

  while(running)
  {
    //system("clear");
    std::cout << "\n\t command to be executed: \n" + cmd << std::endl;
    std::cout << "\n\t Input SQL command, e to exit: " << std::endl;
    fflush(stdin);
    std::getline(std::cin,*temp);

    if(*temp == "e")
    {
      running = false;
    }
     else {
        cmd += *temp;
      }
  }

  delete temp;
  return cmd;
}

void Database::sqlExec(std::string command[3])
{

  int exit = 0;
  char* messaggeError;

  exit = sqlite3_exec(this->db, command[1].c_str(), callback, 0, &messaggeError);

  if (exit != SQLITE_OK) {
      std::cerr << command[2] << std::endl;
      sqlite3_free(messaggeError);
      //return false;
  }
  else {
      std::cout << command[3] << std::endl;
      //return true;
  }

}

void Database::sqlExecInsDel(std::string command[3])
{
    int exit = 0;
    char* messaggeError;

    exit = sqlite3_exec(this->db, command[1].c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << command[2] << std::endl;
        sqlite3_free(messaggeError);
        //return false;
    }
    else {
        std::cout << command[3] << std::endl;
        //return true;
    }
}

bool Database::isDatabaseOpen()
{
    if(this->db == NULL)
    {
      return false;
    }

    return true;
}
