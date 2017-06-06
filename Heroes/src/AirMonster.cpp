#include "AirMonster.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Hero.h"
#include "Equipment.h"

bool AirMonster::fight(Hero *hero)
{
int init = rand()%2;
    while(hero->getCurrHP() > 0 && getCurrHP() > 0)
    {
                cout << hero->getName() << ": " << hero->getCurrHP() << " / " << hero->getStamina()<< " HP"<<endl;
                cout << getName() << ": " << getCurrHP() << " / " << getStamina() << " HP" <<endl;
        if (init==0)
        {
          while(hero->getCurrHP() > 0 && getCurrHP() > 0)
            {
                int heroStrike = rand() %20 + 1 + hero->getAttack();
                if(heroStrike > getDefence())
                {
                    int dmg_dealt = hero->weaponDmg() - (getArmor());
                    int dodge_chance = rand() %101;
                    if (dmg_dealt<1)
                        dmg_dealt=0;
                    if (dodge_chance < 2*getType()+1)
                    {
                        dmg_dealt = 0;
                        cout << getName() << " dodged attack." << endl;
                    }
                    dmg(dmg_dealt);
                    cout << hero->getName() << " hits for " << dmg_dealt << " -> " << getName() << " has "<< getCurrHP() << " HP left\n";
                }
                if(getCurrHP()<1)
                    break;
                int monsterStrike = rand() %20 +1 +getAttack();
                if(monsterStrike > hero->getDefence())
                {
                    int dmg_dealt = getDamage() - hero->getArmor().base_armor;
                    if (dmg_dealt<1)
                        dmg_dealt=0;
                    hero->dmg(dmg_dealt);
                    cout << getName() << " hits for " << dmg_dealt << " -> " << hero->getName() << " has " << hero->getCurrHP() << " HP left\n";
                }
                if(hero->getCurrHP()<0)
                    break;
            }
            return (hero->getCurrHP()>0) ? true : false;
        }
        else
        {
           while(hero->getCurrHP() > 0 && getCurrHP() > 0)
            {
                int monsterStrike = rand() %20 +1 +getAttack();
            if(monsterStrike > hero->getDefence())
            {
                int dmg_dealt = getDamage() - hero->getArmor().base_armor;
                if (dmg_dealt<1)
                    dmg_dealt=0;
                hero->dmg(dmg_dealt);
                cout << getName() << " hits for " << dmg_dealt << " -> " << hero->getName() << " has " << hero->getCurrHP() << " HP left\n";
            }
            if(hero->getCurrHP()<1)
                break;
            int heroStrike = rand() % 20 + 1 + hero->getAttack();
            if(heroStrike > getDefence())
            {
                int dmg_dealt = hero->weaponDmg() - (getArmor());
                int dodge_chance = rand() %101;
                if (dmg_dealt<1)
                    dmg_dealt=0;
                if (dodge_chance < 2*getType()+1)
                {
                    dmg_dealt = 0;
                    cout << getName() << " dodged attack." << endl;
                }
                dmg(dmg_dealt);
                cout << hero->getName() << " hits for " << dmg_dealt << " -> " << getName() << " has "<< getCurrHP() << " HP left\n";
            }
            if(getCurrHP()<1)
                break;
        }
        return (hero->getCurrHP()>0) ? true : false;
    }
}
}

