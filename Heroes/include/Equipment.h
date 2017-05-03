#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>
#include <string>
using namespace std;

struct Weapon
{
    int base_damage;/**bazowy dmg, jaki atrybut daje bonus*/
    int accuracy;
    Weapon (int dmg,int accuracy)
    :
        base_damage {dmg},
        accuracy{accuracy}
        {

        }
    friend ostream& operator<<( ostream& out, const Weapon& weapon )
    {
        out << "(dmg: " << weapon.base_damage << ",accuracy: " << weapon.accuracy << ")";
        return out;
    }
};

struct Armor
{
    int base_armor; /**armor of hero*/

    Armor (int armor)
    :
        base_armor {armor}
        {

        }

    friend ostream& operator<<( ostream& out, const Armor& armor ) /**operator for showing stats of armor*/
    {
        out << "(" << armor.base_armor << ")";
        return out;
    }

};


#endif // EQUIPMENT_H
