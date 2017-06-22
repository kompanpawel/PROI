#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <windows.h>
#include "Hero.h"
#include <vector>
#include "Monster.h"

class menu
{
    static Hero *hero;
    static Monster *monster;
    static vector <Monster*> easy_monsters;
    static vector <Monster*> medium_monsters;
    static vector <Monster*> hard_monsters;
    static vector <Monster*> bossses;

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
    static void save();
    static void load();
    static void createMonsters();
    static void restoreMonstersHP();
    static void deleteMonsters();
};

#endif // MENU_H
