#include "../include/Database.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void getResource(std::map<std::string, std::string> m, std::string messages[3])
{
  int index = 1;

  for (auto item : m)
  {
      messages[index] = item.second;
      index++;
  }
}

std::string getSqlCommand()
{
    std::string command;

    std::cout << "\n\t Input SQL command: " << std::endl;

    fflush(stdin);

    std::getline(std::cin, command);

    return command;
}


Database::Database()
{
    this->db = NULL;

    resources = new ResourceBundle();
}

Database::~Database()
{
    if(this->isDatabaseOpen())
    {
      this->close();
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
    if(this->isDatabaseOpen()) {
      sqlite3_close(this->db);
      this->db = NULL;
    } else {

      std::cout << "No open database!" << std::endl;
    }

}

void Database::createOrOpenDatabase()
{
    int error;                     // boolean to test the return command
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
        std::cout << "Database created/opened successfully!" << std::endl;

    }

    delete name;
}

void Database::createTable()
{

    if(isDatabaseOpen())
    {
        setResourceAndExec(*resources->table_messages);

    } else {

      std::cout << "No open database!" << std::endl;
    }
}

void Database::deleteTable()
{
  //sql = "DELETE FROM PERSON WHERE ID = 2;";
  std::string command[3] = {" ", "Error deleting table!", "Table deleted!"};
  command[0] = getSqlCommand();



}

void Database::insertData()
{
  if(isDatabaseOpen())
  {
    std::string messages[3] = {"qweqe", "asdd ", " asdijad"};

    getResource(*resources->insert_messages, messages);

    messages[0] = getSqlCommand();

    for (int i = 0; i < 3; i++) {
      std::cout << "\n i: " + std::to_string(i) + " " + messages[i] << '\n';
    }
    /* execSQL(messages); */

  } else {

    std::cout << "No open database!" << std::endl;
  }

}

void Database::setResourceAndExec(std::map<std::string, std::string> m)
{
  std::string messages[3] = {"", "", ""};

  getResource(m, messages);

  messages[0] = getSqlCommand();

  execSQL(messages);
}

void Database::execSQL(std::string messages[3])     // receives a string array: first position holds an sql command,
{                                                  // second and third holds negative and positive messages for the result

  int exit;
  char* messaggeError;

  exit = sqlite3_exec(db,
                      messages[0].c_str(),      // string is converted to char array
                      NULL,
                      0,
                      &messaggeError);

  if (exit != SQLITE_OK) {

      std::cerr << messages[2] << std::endl;

      sqlite3_free(messaggeError);
  }
  else
      std::cout << messages[1] << std::endl;
}

bool Database::isDatabaseOpen()
{
    if(this->db == NULL)
    {
      return false;
    }

    return true;
}
