#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "Hero.h"
#include "Equipment.h"
using namespace std;

string Hero::DIFFICULTY = "easy";
ostream& operator<<( ostream& out, const Hero& g )
{
    out << "name = " << g.getName() << "\nclass = " << g.getClass() << "\nstrength = " << g.getStrength() << "\nagility = " <<
            g.getAgility() << "\nintelligence = " << g.getIntelligence() << "\nHP " << g.getCurrHP() <<"/"<<g.getStamina() <<
           "\nweapon = (" << g.getWeapon() << ")\narmor = (" << g.getArmor() << ")" << "\nlevel = " << g.getLevel();

    /*out << "name = " << g.getName(); << "\nclass = " << g.getClass() << "\nstrength = " << g.getStrength() << "\nnagility = " <<
        g.getAgility() << "\nintelligence = " << g.getIntelligence() << "\nHP = " << g.getCurrHP() << "/" << g.getStamina() <<
        "\nweapon = (" << g.getWeapon() << "\narmor = " << g.getArmor() << ")" << "\nlevel = " << g.getLevel();*/
    return out;
}

void Hero::confAttack()
{
    if(getClass()=="Warrior")
    {
        int attack_=(getWeapon().accuracy + 0.3*getStrength());
        setAttack(attack_);
    }
    else if(getClass()=="Hunter")
    {
        int attack_=(getWeapon().accuracy + 0.5*getAgility());
        setAttack(attack_);
    }
    else if(getClass()=="Sorcerer")
    {
        int attack_=(getWeapon().accuracy + 0.4*getIntelligence());
        setAttack(attack_);
    }
}
void Hero::setDefence()
    {
        int defence_ = (getArmor().base_armor + 0.2*getAgility());
        defence = defence_;
    }

int Hero::weaponDmg()
{
    if(getClass()=="Warrior")
        {
            int weapon_dmg = getWeapon().base_damage+ 0.4*getStrength();
            return weapon_dmg;
        }
    else if(getClass()=="Hunter")
        {
            int weapon_dmg = getWeapon().base_damage+ 0.3*getAgility();
            return weapon_dmg;
        }
    else if(getClass()=="Sorcerer")
        {
            int weapon_dmg = getWeapon().base_damage+ 0.5*getIntelligence();
            return weapon_dmg;
        }
}
bool Hero::fight(Monster *monster)
{
    monster->fight(this);
}

void Hero::levelUp()
{
    level++;
    if(getClass()=="Warrior")
    {
        strength+= rand() %6 + 2;
        agility+= rand() %4 + 1;
        intelligence+= rand() %3;
        stamina+= rand() %20 + (0.5*getStrength());
        if (DIFFICULTY=="easy")
            currHP = stamina;
        int a = getWeaponDMG();
        int b = getAccuracy();
        setWeapon(Weapon(a+1,b+1));
        int c = getArmorValue();
        setArmor(Armor(c+1));
    }
    else if(getClass()=="Hunter")
    {
        strength+= rand() %4 + 1;
        agility+= rand() %6 + 2;
        intelligence+= rand() %3 + 1;
        stamina+= rand() %20 + (0.5*getStrength());
        if (DIFFICULTY=="easy")
            currHP = stamina;
        int a = getWeaponDMG();
        int b = getAccuracy();
        setWeapon(Weapon(a+1,b+1));
        int c = getArmorValue();
        setArmor(Armor(c+1));
    }
    else if(getClass()=="Sorcerer")
    {
        strength+= rand() %4;
        agility+= rand() %4 + 1;
        intelligence+= rand() %7 + 2;
        stamina+= rand() %20 + (0.5*getStrength());
        if (DIFFICULTY=="easy")
            currHP = stamina;
        int a = getWeaponDMG();
        int b = getAccuracy();
        setWeapon(Weapon(a+1,b+1));
        int c = getArmorValue();
        setArmor(Armor(c+1));
    }
}
 void Hero::restore()
 {
     currHP = stamina;
     licznik++;
     cout << "Monster level: " << licznik << endl;
 }

void Hero::startingStats()
{
    if(getClass()=="Warrior")
    {
        setStrength(15);
        setAgility(12);
        setIntelligence(9);
        setStamina(20);
        currHP=stamina;
        setWeapon(Weapon(6,15));
        setArmor(Armor(8));
    }
    else if(getClass()=="Hunter")
    {
        setStrength(11);
        setAgility(16);
        setIntelligence(11);
        setStamina(18);
        currHP=stamina;
        setWeapon(Weapon(6,17));
        setArmor(Armor(6));
    }
    else if(getClass()=="Sorcerer")
    {
        setStrength(10);
        setAgility(10);
        setIntelligence(18);
        setStamina(14);
        currHP=stamina;
        setWeapon(Weapon(8,16));
        setArmor(Armor(4));
    }
}
string Hero::to_string()
{
    stringstream ss;
    ss << getName() << endl << getClass() << endl << getStrength() << endl << getAgility() << endl
        << getIntelligence() << endl << getCurrHP() << endl << getStamina() << endl <<
        getWeaponDMG() << endl <<getAccuracy() << endl << getArmorValue() << endl << getLevel() << endl;
    return ss.str();
}
