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

              break;
          case 2: break;
          case 3: break;
          case 4: break;
          case 5:
              resourcesPath = setPreferences();
              m->changeLocale(resourcesPath);
              db->changeLocale(resourcesPath);
            break;
          case 6: run = false; break;
        }

    } while(run);

    delete db;
    delete m;
    return 0;
}
