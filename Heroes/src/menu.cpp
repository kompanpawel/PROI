#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Hero.h"
#include "menu.h"
#include "save_error.h"
#include "Monster.h"
#include "EarthMonster.h"
#include "FireMonster.h"
#include "WaterMonster.h"
#include "AirMonster.h"
using namespace std;

Hero *menu::hero = nullptr;
Monster *menu::monster = nullptr;
vector <Monster*> menu::easy_monsters;
vector <Monster*> menu::medium_monsters;
vector <Monster*> menu::hard_monsters;
vector <Monster*> menu::bossses;

int menu::showMenu()
{
    setDifficulty();
    createMonsters();
    while(1)
    {
        cleanScreen();
        cout << "1. Create your hero\n";
        cout << "2. Show your hero\n";
        cout << "3. Fight with monsters\n";
        cout << "4. Take a rest and restore your HP (but monsters are getting stronger)\n";
        cout << "5. Save game\n";
        cout << "6. Load game\n";
        cout << "7. Quit and end your adventure\n";

        char option = '0';
        cin >> option;
        cin.clear();

        switch(option)
        {
            case '1': createHero(); break;
            case '2': showHero(); break;
            case '3': pickMonster(); break;
            case '4': rest(); break;
            case '5':
                {
                    try {save();}
                    catch (save_error &a)
                    {
                        cout << a.what() << endl;
                    }
                    break;
                }
            case '6': load(); break;
            case '7':
                if( hero != nullptr )
                    delete hero;
                deleteMonsters();
                return 0;
        }
    }
}

void menu::createHero()
{
    cleanScreen();
    if (hero!=nullptr)
    {
        cout << "You have your own hero, that's enough for now!";
        stopScreen();
        return;
    }
    cout << "Name: ";
    string name;
    cin >> name;

    cout << "Pick your class(1 - Warrior; 2 - Hunter; 3 - Sorcerer) \n";
    string class_of_hero;
    char pick = '0';
    cin >> pick;
    switch(pick)
    {
        case '1': class_of_hero = "Warrior"; break;
        case '2': class_of_hero = "Hunter"; break;
        case '3': class_of_hero = "Sorcerer"; break;
        default: return; break;
    }

    hero = new Hero(name, class_of_hero,0,0,0,0, Weapon(0,0), Armor(0),0,0);
    stopScreen();
}
bool menu::showHero()
{
    cleanScreen();
    if(hero == nullptr)
    {
        cout << "You did not create any hero.";
        stopScreen();
        return false;
    }
    else
        cout << *hero << endl;

    stopScreen();
    return true;
}

void menu::pickMonster()
{
    cleanScreen();
    if(hero == nullptr)
        {
            cout << "You did not create your hero. How do you think you want to fight???";
            stopScreen();
            return;
        }


    cout << "Choose monster to fight[1. Easy  2.Medium  3.Hard  4.Final boss]\n";
    char option = '0';
    cin >> option;
    switch(option)
    {
        case '1':
            {
                int chosen = rand() %4;
                easy_monsters[chosen]->setModifier(hero->licznik);
                easy_monsters[chosen]->setAllStats();
                bool result = hero->fight(easy_monsters[chosen]);
                if (result)
                {
                    hero->levelUp();
                    cout << hero->getName()<< " wins\n";
                }
                else
                    {
                        delete hero;
                        hero = nullptr;
                    }
                break;
            }
        case '2':
            {
                int chosen = rand() %4;
                medium_monsters[chosen]->setModifier(hero->licznik);
                medium_monsters[chosen]->setAllStats();
                bool result = hero->fight(medium_monsters[chosen]);
                if(result)
                {
                    hero->levelUp();
                    cout << hero->getName()<< " wins\n";
                }
                else
                    {
                        delete hero;
                        hero = nullptr;
                    }
                 break;
            }
        case '3':
            {
                int chosen = rand() %4;
                hard_monsters[chosen]->setModifier(hero->licznik);
                hard_monsters[chosen]->setAllStats();
                bool result = hero->fight(hard_monsters[chosen]);
                 if(result)
                 {
                    hero->levelUp();
                    cout << hero->getName()<< " wins\n";
                }
                else
                    {
                        delete hero;
                        hero = nullptr;
                    }
                break;
            }
        case '4':
            {
                int chosen = rand() %4;
                bossses[chosen]->setModifier(hero->licznik);
                bossses[chosen]->setAllStats();
                bool result = hero->fight(bossses[chosen]);
                if(result)
                {
                    hero->levelUp();
                    cout << hero->getName()<< " wins\n";
                }
                else
                    {
                        delete hero;
                        hero = nullptr;
                    }
                 break;
            }
    }
    restoreMonstersHP();
    stopScreen();
}

void menu::rest()
{
    cleanScreen();
    if(hero == nullptr)
    {
        cout << "You did not create any hero.";
        stopScreen();
        return;
    }
    else
        hero->restore();
    stopScreen();
}

void menu::setDifficulty()
{
    int choice;
    cout << "Choose difficulty:\n1. Easy (your hero get HP restored after lvl up)\n2. Hard(your hero need to restore HP after fight)\n";
    cin >> choice;
    switch(choice)
    {
        case 1: hero->setDifficulty("easy"); break;
        case 2: hero->setDifficulty("hard"); break;
        default: hero->setDifficulty("easy"); break;
    }
}

void menu::save()
{
    if (hero == nullptr)
    {
        cout << "Error. You didn't create hero.";
        stopScreen();
        return;
    }
    ofstream file("C:\\Users\\kompanpawel\\Desktop\\PROI\\Heroes\\save&load.txt");
    file << hero->to_string();
    if(!file)
        throw save_error();
}

void menu::load()
{
    ifstream file("C:\\Users\\kompanpawel\\Desktop\\PROI\\Heroes\\save&load.txt");
    string name, class_of_hero;
    int str, agi, intel, curr, stamina, level, weapDMG, weapAcc, armor;
    file >> name >> class_of_hero >> str >> agi >> intel >> curr >> stamina >> weapDMG >> weapAcc >> armor >> level;

    delete hero;
    hero = new Hero( name, class_of_hero, str, agi, intel, curr, stamina, Weapon(weapDMG, weapAcc), Armor(armor), level,0,0 );
}

void menu::createMonsters()
{
    EarthMonster *easy_earth = new EarthMonster("Kobold",10,10,13,6,6,0,1);
    FireMonster *easy_fire = new FireMonster("Fire Serpent",10,10,13,6,6,0,1);
    WaterMonster *easy_water = new WaterMonster("a",10,10,13,6,6,0,1);
    AirMonster *easy_air = new AirMonster("Small Vortex",10,10,13,6,6,0,1);
    easy_monsters.push_back(easy_earth);
    easy_monsters.push_back(easy_fire);
    easy_monsters.push_back(easy_water);
    easy_monsters.push_back(easy_air);

    EarthMonster *medium_earth = new EarthMonster("Golem",30,15,25,15,16,0,5);
    FireMonster *medium_fire = new FireMonster("Golem",30,15,25,15,16,0,5);
    WaterMonster *medium_water = new WaterMonster("Golem",30,15,25,15,16,0,5);
    AirMonster *medium_air = new AirMonster("Golem",30,15,25,15,16,0,5);
    medium_monsters.push_back(medium_earth);
    medium_monsters.push_back(medium_fire);
    medium_monsters.push_back(medium_water);
    medium_monsters.push_back(medium_air);

    EarthMonster *hard_earth = new EarthMonster("Wyvern",45,20,25,20,20,0,10);
    FireMonster *hard_fire = new FireMonster("Wyvern",45,20,25,20,20,0,10);
    WaterMonster *hard_water = new WaterMonster("Wyvern",45,20,25,20,20,0,10);
    AirMonster *hard_air = new AirMonster("Wyvern",45,20,25,20,20,0,10);
    hard_monsters.push_back(hard_earth);
    hard_monsters.push_back(hard_fire);
    hard_monsters.push_back(hard_water);
    hard_monsters.push_back(hard_air);

    EarthMonster *earth_boss = new EarthMonster("Golden Dragon",80,30,30,28,30,0,20);
    FireMonster *fire_boss = new FireMonster("Golden Dragon",80,30,30,28,30,0,20);
    WaterMonster *water_boss = new WaterMonster("Golden Dragon",80,30,30,28,30,0,20);
    AirMonster *air_boss = new AirMonster("Golden Dragon",80,30,30,28,30,0,20);
    bossses.push_back(earth_boss);
    bossses.push_back(fire_boss);
    bossses.push_back(water_boss);
    bossses.push_back(air_boss);
}

void menu::restoreMonstersHP()
{
    for(Monster* monster: easy_monsters)
        monster->restore();
    for(Monster* monster: medium_monsters)
        monster->restore();
    for(Monster* monster: hard_monsters)
        monster->restore();
    for(Monster* monster: bossses)
        monster->restore();
}

void menu::deleteMonsters()
{
    for(Monster* monster: easy_monsters)
        delete monster;
    for(Monster* monster: medium_monsters)
        delete monster;
    for(Monster* monster: hard_monsters)
        delete monster;
    for(Monster* monster: bossses)
        delete monster;
}
