#ifndef AIRMONSTER_H
#define AIRMONSTER_H

#include <iostream>
#include "Hero.h"

class AirMonster: public Monster
{


    public:

        AirMonster(std::string name, int stamina, int attack, int defence, int damage, int armor, int mod, int type)
        :
            Monster(name, stamina, attack, defence, damage, armor, mod, type)
            {
            }
        bool fight(Hero *hero);
        virtual ~AirMonster()
        {

        }

    protected:

    private:
};

#endif // AIRMONSTER_H
