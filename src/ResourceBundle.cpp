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
    loadResources(table_messages, "resources/en/table.dat");
    loadResources(insert_messages, "resources/en/insert.dat");
}

ResourceBundle::~ResourceBundle()
{

}

void ResourceBundle::loadResources(std::map<std::string, std::string> m, std::string path)
{
  std::fstream stringResources;

  stringResources.open(path);

  if (stringResources.is_open()) {

    int position;
    std::string line, key, value;

    while ( std::getline(stringResources, line) )
    {
      position = line.find(":");

      key = line.substr(0, position);

      value = line.substr(position + 1);

      m[key] = value;

    }

    stringResources.close();
  }
  else
  {
      std::cout << "Error opening file: " + path << std::endl;
      exit(1);
  }
}
