//
//  ResourceBundle.hpp
//  sqlLite
//
//  Created by <author> on 19/01/2021.
//
//

#ifndef ResourceBundle_hpp
#define ResourceBundle_hpp

#include <iostream>
#include <fstream>
#include <map>

class ResourceBundle {

public:
    std::map<std::string, std::string> table_messages;
    std::map<std::string, std::string> insert_messages;
    std::map<std::string, std::string> delete_messages;

    ResourceBundle();
    ~ResourceBundle();

private:

    void loadResources(std::map<std::string, std::string> m, std::string path);

};


#endif /* ResourceBundle_hpp */
