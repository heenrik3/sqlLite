//
//  Menu.cpp
//  sqlLite
//
//  Created by Henrik3 on 26/01/2021.
//
//

#include "../include/Menu.hpp"

Menu::Menu()
{
    menuItems = load("resource/en/menu.dat");
}

Menu::~Menu()
{
  destroy();
}

std::map<std::string, std::string>* Menu::load(std::string path)
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

void Menu::destroy()
{

    delete menuItems;

}

void Menu::show()
{

    for (auto item : *menuItems)
    {
      std::cout << item << '\n';
    }

}
