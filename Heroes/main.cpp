#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "Test.h"
using namespace std;

int main()
{
    srand(time(0));
    char choice;
    cout << "1.Test\n2.Main menu.\n";
    cin >> choice;
    switch(choice)
    {
        case '1': test3(); break;
        case '2': menu::showMenu(); break;
    }
return 0;
}
