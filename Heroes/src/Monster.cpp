#include <iostream>
#include <cstdlib>
#include "Monster.h"

std::ostream& operator<<( std::ostream& out, const Monster& g )
{
    out << "name = " << g.getName() << "\nattack = " << g.getAttack() << "\nadefence = " <<
            g.getDefence() << "\nHP " << g.getCurrHP() <<"/"<<g.getStamina() <<
           "\ndamage = " << g.getDamage() << "\narmor = " << g.getArmor();

    /*out << "name = " << g.getName(); << "\nclass = " << g.getClass() << "\nstrength = " << g.getStrength() << "\nnagility = " <<
        g.getAgility() << "\nintelligence = " << g.getIntelligence() << "\nHP = " << g.getCurrHP() << "/" << g.getStamina() <<
        "\nweapon = (" << g.getWeapon() << "\narmor = " << g.getArmor() << ")" << "\nlevel = " << g.getLevel();*/
    return out;
}
