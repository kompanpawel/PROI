#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "Test.h"
using namespace std;

int main()
{
    srand(time(0));
    #ifdef DEBUG
    test1();
    return 0;
    #endif //DEBUG
    return menu::showMenu();

}
