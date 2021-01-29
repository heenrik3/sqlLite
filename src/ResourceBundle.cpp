//
//  ResourceBundle.cpp
//  sqlLite
//
//  Created by <author> on 19/01/2021.
//
//

#include "../include/ResourceBundle.hpp"

ResourceBundle::ResourceBundle()
{
    initializer();
}

ResourceBundle::~ResourceBundle()
{
    deleteResources();
}

void ResourceBundle::setLocale(std::string locale)
{

    deleteResources();
    initializer(locale);

}

void ResourceBundle::initializer(std::string locale)
{
  std::string path, dbName, tableName, insertName, deleteName;

  path       = "resources/" + locale + "/";
  dbName     = "database.dat";
  tableName  = "table.dat";
  insertName = "insert.dat";
  deleteName = "deletion.dat";

  database_messages = loadResources(path + dbName);
  table_messages    = loadResources(path + tableName);
  insert_messages   = loadResources(path + insertName);
  delete_messages   = loadResources(path + deleteName);
}

std::map<std::string, std::string>* ResourceBundle::loadResources(std::string path)
{
  std::fstream stringResources;

  stringResources.open(path);

  if (stringResources.is_open()) {

    int position;
    std::map<std::string,
              std::string> *newMap;
    std::string line, key, value;

    newMap  = new std::map<std::string, std::string>;

    while ( std::getline(stringResources, line) )
    {
      position = line.find(":");              // finds the " : " between key and value

      key = line.substr(0, position);         // all the characters before " : " becomes a key

      value = line.substr(position + 1);      // all the characters after " : " becomes a value

      (*newMap)[key] = value;                 // map receives the key and the value of that line
    }

    stringResources.close();

    return newMap;
  }
  else
  {
      std::cout << "Error opening file: " + path << std::endl;
      exit(1);
  }
}

void ResourceBundle::deleteResources()
{
  delete database_messages;
  delete table_messages;
  delete insert_messages;
  delete delete_messages;
}
