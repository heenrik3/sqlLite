//
//  utilityFunctions.cpp
//  sqlLite
//
//  Created by henrik3 on 26/01/2021.
//
//

#include "../include/utilityFunctions.hpp"

void clear()    // clear screen
{
  system(clears);
}

std::string setPreferences()
{
  std::fstream languagesAvailableFile;
  std::string path, languageFile;
  path = "resources/";
  languageFile = "preferences.dat";

  languagesAvailableFile.open(path + languageFile);

  if (languagesAvailableFile.is_open()) {

      std::string buffer, line, key, value, toBeReturned;
      int index, min, max, option, position;

      std::map<std::string,
                std::string> newMap;

      min = max = 1;

      while ( std::getline(languagesAvailableFile, line) )
      {
        position = line.find(":");              // finds the " : " between key and value

        key = line.substr(0, position);         // all the characters before " : " becomes a key

        value = line.substr(position + 1);      // all the characters after " : " becomes a value

        newMap[key] = value;                // map receives the key and the value of that line

        max++;
      }

      languagesAvailableFile.close();

      do
      {
          clear();
          index = 1;
          std::cout << "Choose a language: " << '\n';

          for(auto item : newMap)
          {
            std::cout << std::to_string(index) + ". " + item.first << '\n';
            index++;
          }

          std::getline(std::cin, buffer);

          try {
            option = std::stoi(buffer);
          } catch(const std::invalid_argument& ia) {}   // when inserted letters as arguments

        } while(option < min || option > max-1);

      index = 1;
      for(auto item : newMap)
        {
          if (index == option) {
              toBeReturned = item.second;
          }
          index++;
        }

      return path + toBeReturned + "/";
    }
    else
    {
        std::cout << "Error opening file: " + path + languageFile << std::endl;
        exit(1);
    }
}
