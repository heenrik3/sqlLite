//
//  utilityFunctions.hpp
//  sqlLite
//
//  Created by henrik3 on 26/01/2021.
//
//

#ifndef utilityFunctions_hpp
#define utilityFunctions_hpp

#include <iostream>
#include <fstream>
#include <map>

#ifdef _WIN32
#define clears "cls" // windows
#endif

#ifdef __linux__
#define clears "clear" // linux
#endif

void clear();
std::string setPreferences();


#endif /* utilityFunctions_hpp */
