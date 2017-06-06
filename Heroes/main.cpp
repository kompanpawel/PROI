#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "Test.h"
using namespace std;
void stopScreen()
   {
       std::cout << "\nType any character to continue " << endl;
       std::cin.clear();
       std::cin.ignore();
       std::cin.get();
   }
int main()
{
    srand(time(0));
    menu::showMenu();
return 0;
}
