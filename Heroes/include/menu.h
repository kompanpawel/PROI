#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <windows.h>
#include "Hero.h"

class menu
{
   static Hero *hero;
   static void cleanScreen()
   {
       system("cls");
   }
   static void stopScreen()
   {
       std::cout << "\nType any character to continue " << endl;
       std::cin.clear();
       std::cin.ignore();
       std::cin.get();
   }
public:
    Menu() = delete;
    static int showMenu();
    static void createHero();
    static void pickMonster();
    static void rest();
    static bool showHero();
    static void setDifficulty();
    static void showMod();
};

#endif // MENU_H
