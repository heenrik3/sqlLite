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
                db->createOrOpenDatabase();
              break;
          case 2:
              db->execute();
            break;
          case 3:
              resourcesPath = setPreferences();
              m->changeLocale(resourcesPath);
              db->changeLocale(resourcesPath);
            break;
          case 4: run = false; break;
        }

    } while(run);

    delete db;
    delete m;
    return 0;
}
