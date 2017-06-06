#ifndef WATERMONSTER_H
#define WATERMONSTER_H

#include <iostream>
#include "Hero.h"

class WaterMonster: public Monster
{


    public:

        WaterMonster(std::string name, int stamina, int attack, int defence, int damage, int armor, int mod, int type)
        :
            Monster(name, stamina, attack, defence, damage, armor, mod, type)
            {
            }
        bool fight(Hero *hero);
        virtual ~WaterMonster()
        {

        }

    protected:

    private:
};
#endif // WATERMONSTER_H
