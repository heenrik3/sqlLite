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
    std::string path = "resources/en/";

    this->database_messages = loadResources(path + "database.dat");
    this->table_messages = loadResources(path + "table.dat");
    this->insert_messages = loadResources(path + "insert.dat");
    this->delete_messages = loadResources(path + "deletion.dat");
}

ResourceBundle::~ResourceBundle()
{
    delete this->database_messages;
    delete this->table_messages;
    delete this->insert_messages;
    delete this->delete_messages;
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
      position = line.find(":");

      key = line.substr(0, position);

      value = line.substr(position + 1);

      (*newMap)[key] = value;
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
