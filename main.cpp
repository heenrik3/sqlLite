#include <iostream>
#include "include/Database.hpp"
#include "include/Menu.hpp"
#include "include/utilityFunctions.hpp"

int main(int argc, char const *argv[])
{
    std::string resourcesPath = setPreferences();

    Menu *m = new Menu(resourcesPath);
    Database *db = new Database(resourcesPath);

    bool run = true;

    do {

        m->show();

        switch (m->getOption()) {

          case 1:
          run = false;
          break;
        }

    } while(run);
    return 0;
}
