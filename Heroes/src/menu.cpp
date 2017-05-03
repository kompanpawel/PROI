#include <iostream>
#include <string>
#include <sstream>
#include "Hero.h"
#include "menu.h"
#include "Monster.h"
using namespace std;

Hero *menu::hero = nullptr;

int menu::showMenu()
{
    setDifficulty();

    while(1)
    {
        cleanScreen();
        cout << "1. Create your hero\n";
        cout << "2. Show your hero\n";
        cout << "3. Fight with monsters\n";
        cout << "4. Take a rest and restore your HP (but monsters are getting stronger)\n";
        cout << "5. Quit and end your adventure\n";

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
                if( hero != nullptr )
                    delete hero;
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
                bool result = hero->fight(Monster("Kobold",10,10,13,6,6,hero->licznik));
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
                bool result = hero->fight(Monster("Golem",30,15,25,15,16,hero->licznik));
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
                bool result = hero->fight(Monster("Wyvern",45,20,25,20,20,hero->licznik));
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
                bool result = hero->fight(Monster("Golden Dragon",80,30,30,28,30,hero->licznik));
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

    stopScreen();
}

void menu::rest()
{
    cleanScreen();
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

