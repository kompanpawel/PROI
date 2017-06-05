#ifndef EARTHMONSTER_H
#define EARTHMONSTER_H

#include <iostream>
#include "Hero.h"

class EarthMonster: public Monster
{


    public:

        EarthMonster(std::string name, int stamina, int attack, int defence, int damage, int armor, int mod, int type)
        :
            Monster(name, stamina, attack, defence, damage, armor, mod, type)
            {
            }
        bool fight(Hero *hero);
        virtual ~EarthMonster()
        {

        }

    protected:

    private:
};

#endif // EARTHMONSTER_H
