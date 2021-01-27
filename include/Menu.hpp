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

#include "utilityFunctions.hpp"

class Menu {

public:

  std::map<std::string, std::string> *menuItems;

    Menu();
    ~Menu();

    std::map<std::string, std::string>* load(std::string path);

    void destroy();
    void show();

};


#endif /* Menu_hpp */
