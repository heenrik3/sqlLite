//
//  Resource_Bundle.cpp
//  sqlLite
//
//  Created by <author> on 27/01/2021.
//
//

#include "../include/Resource_Bundle.hpp"

Resource_Bundle::Resource_Bundle(std::string path)
{
    bundle = load(path);
}

Resource_Bundle::~Resource_Bundle()
{
    destroy();
}

std::map<std::string, std::string>* Resource_Bundle::load(std::string path)
{
  std::fstream stringResourcesFile;

  stringResourcesFile.open(path);

  if (stringResourcesFile.is_open()) {

    int position;

    std::map<std::string,
              std::string>* newMap;

    std::string line, key, value;

    newMap  = new std::map<std::string, std::string>;

    while ( std::getline(stringResourcesFile, line) )
    {
      position = line.find(":");              // finds the " : " between key and value

      key = line.substr(0, position);         // all the characters before " : " becomes a key

      value = line.substr(position + 1);      // all the characters after " : " becomes a value

      (*newMap)[key] = value;                 // map receives the key and the value of that line
    }

    stringResourcesFile.close();

    return newMap;
  }
  else
  {
      std::cout << "Error opening file: " + path << std::endl;
      exit(1);
  }
}

void Resource_Bundle::destroy()
{
    delete bundle;
}

void Resource_Bundle::modifyBundle(std::string path)
{

    destroy();
    bundle = load(path);

}
