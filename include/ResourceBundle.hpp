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
    std::map<std::string, std::string> *database_messages;         //
    std::map<std::string, std::string> *table_messages;            //  maps holds strings info based on
    std::map<std::string, std::string> *insert_messages;           //  language preferences
    std::map<std::string, std::string> *delete_messages;           //

    ResourceBundle();
    ~ResourceBundle();

    void setLocale(std::string locale);

private:

    void initializer(std::string = "en");
    std::map<std::string, std::string>* loadResources(std::string path);    // returns a map pointer with string resources

    void deleteResources();
};

#endif /* ResourceBundle_hpp */
