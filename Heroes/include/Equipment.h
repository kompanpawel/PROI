#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>
#include <string>
using namespace std;

struct Weapon
{
    int base_damage;//bazowy dmg//jaki atrybut daje bonus
    int accuracy;
    Weapon (int dmg,int accuracy)
    :
        base_damage {dmg},
        accuracy{accuracy}
        {

        }
int dmg();
};

struct Armor
{
    int base_armor;

    Armor (int armor)
    :
        base_armor {armor}
        {

        }

};


#endif // EQUIPMENT_H
