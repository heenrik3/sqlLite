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

#ifdef _WIN32
#define clears "cls" // windows
#endif

#ifdef __linux__
#define clears "clear" // linux
#endif

void clear();


#endif /* utilityFunctions_hpp */
