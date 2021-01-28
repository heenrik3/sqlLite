#include <iostream>
#include "include/Database.hpp"
#include "include/Menu.hpp"

int main(int argc, char const *argv[])
{
    Menu *m = new Menu();
    Database *db = new Database();

    bool run = true;

    do {

        m->show();
        switch (m->getOption()) {
          case 1:
            if (db->execute(new std::string command = )) {
              /* code */
            }
        }

    } while(run);
    return 0;
}
