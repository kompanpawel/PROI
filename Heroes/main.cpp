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
    char choice;
    cout << "1.Test\n2.Main menu.\n";
    cin >> choice;
    switch(choice)
    {
        case '2': menu::showMenu(); break;
    }
return 0;
}
