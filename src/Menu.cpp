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
    menuItems = new Resource_Bundle("resources/en/menu.dat");

    this.option = 0;
}

Menu::~Menu()
{
    destroy();
}

void Menu::show()
{
    std::string buffer;
    int min, max;

    min = 1; max = 6;

    do {
      clear();

      for (int i = min; i < max; i++)
      {
        std::cout << std::to_string(i) + ". " + (*menuItems->bundle)["menu" + std::to_string(i)] << std::endl;
      }

      std::cout << (*menuItems->bundle)["option"] << std::endl;

      std::getline(std::cin, buffer);

      try {
        this.option = std::stoi(buffer);
      } catch(const std::invalid_argument& ia) {}   // when inserted letters as arguments

    } while(this.option < min || this.option > max-1);
}

int Menu::getOption()
{
    return this.option;
}

void Menu::destroy()
{
    delete menuItems;
}
