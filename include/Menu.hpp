//
//  Menu.hpp
//  sqlLite
//
//  Created by Henrik3 on 26/01/2021.
//
//

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <fstream>
#include <map>

#include "Resource_Bundle.hpp"
#include "utilityFunctions.hpp"

class Menu {

public:

    Resource_Bundle *menuItems;
    int option;

    Menu(std::string path);
    ~Menu();

    int getOption();

    void show();
    void destroy();
    void changeLocale(std::string path);

};


#endif /* Menu_hpp */
