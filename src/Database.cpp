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
    if(this->isDatabaseOpen()) {
      sqlite3_close(this->db);
      this->db = NULL;
    } else {

      std::cout << "No open database!" << std::endl;
    }

}

void Database::createOrOpenDatabase()
{
    int error = 0;                     // boolean to test the return command
    const char *dbName;
    std::string *name = new std::string;

    std::cout << "\n\tDatabase name:" << std::endl;

    fflush(stdin);
    std::getline(std::cin, *name);

    *name = *name + ".db";                 // add .db at the end of string to form "databaseName".db

    dbName = name->c_str();               // databaseName is converted to char array

    error = sqlite3_open(dbName, &this->db);

    if (error) {
        std::cout << "Error creating DB: " << sqlite3_errmsg(this->db) << std::endl;
    }
    else
    {
        std::cout << "Database created/opened Successfully!" << std::endl;

    }

    delete name;
}

void Database::createTable()
{

    if(this->isDatabaseOpen())
    {

      std::string command[3] = {" ", "Error creating table!", "Table created!"};
      command[1] = getSQLCommand();


    } else {

      std::cout << "No open database!" << std::endl;
    }
}

void Database::deleteTable()
{
  //sql = "DELETE FROM PERSON WHERE ID = 2;";
  std::string command[3] = {" ", "Error deleting table!", "Table deleted!"};
  command[1] = this->getSQLCommand();



}

void Database::insertData()
{
    int insertionResult = 0;

    std::string command[3] = {" ", "Error inserting data!", "New data added!"};

    std::string sql = getSQLCommand();

    insertionResult = sqlite3_exec(this->db, sql.c_str(), callback, NULL, NULL);

    if (insertionResult != SQLITE_OK)
    {
      std::cerr << command[2] << '\n';

    } else

    {
      std::cout << command[3] << '\n';
    }


}

std::string Database::getSQLCommand()
{
    std::string command = " ";

    std::cout << "\n\t Input SQL command: " << std::endl;

    fflush(stdin);

    std::getline(std::cin, command);

    return command;
}


bool Database::isDatabaseOpen()
{
    if(this->db == NULL)
    {
      return false;
    }

    return true;
}
