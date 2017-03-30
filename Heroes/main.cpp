#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "Test.h"
using namespace std;

int main()
{
    srand(time(0));
    test1();
    menu::showMenu();

}
