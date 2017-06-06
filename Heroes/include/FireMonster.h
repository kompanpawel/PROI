#ifndef FIREMONSTER_H
#define FIREMONSTER_H

#include <iostream>
#include "Hero.h"

class FireMonster: public Monster
{


    public:

        FireMonster(std::string name, int stamina, int attack, int defence, int damage, int armor, int mod, int type)
        :
            Monster(name, stamina, attack, defence, damage, armor, mod, type)
            {
            }
        bool fight(Hero *hero);
        virtual ~FireMonster()
        {

        }

    protected:

    private:
};
#endif // FIREMONSTER_H
