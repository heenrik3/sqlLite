//
//  Resource_Bundle.hpp
//  sqlLite
//
//  Created by <author> on 27/01/2021.
//
//

#ifndef Resource_Bundle_hpp
#define Resource_Bundle_hpp

#include <iostream>
#include <fstream>
#include <map>

class Resource_Bundle {

public:

    std::map<std::string, std::string>* bundle;

    Resource_Bundle(std::string path);
    ~Resource_Bundle();

    std::map<std::string, std::string>* load(std::string path);
    void destroy();
    void modifyBundle(std::string path);

};


#endif /* Resource_Bundle_hpp */
