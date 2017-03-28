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
    friend ostream& operator<<( ostream& out, const Weapon& weapon )
    {
        out << "( " << weapon.base_damage << ", " << weapon.accuracy << " )";
        return out;
    }
};

struct Armor
{
    int base_armor;

    Armor (int armor)
    :
        base_armor {armor}
        {

        }

    friend ostream& operator<<( ostream& out, const Armor& armor )
    {
        out << "( " << armor.base_armor << " )";
        return out;
    }

};


#endif // EQUIPMENT_H
