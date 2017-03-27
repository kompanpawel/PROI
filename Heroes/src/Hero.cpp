#include <iostream>
#include <string>
#include "Hero.h"
#include "Equipment.h"
using namespace std;

double Hero::DIFFICULTY = 1;
ostream& operator<<( std::ostream& out, Hero *g )
{
    out << "name = " << g->getName() << "\nclass = " << g->getClass() << "\nstrength = " << g->getStrength() <<
           "\nagility = " << g->getAgility() << "\nintelligence = " << g->getIntelligence() << "/nHP " << g->getCurrHP() <<"/"<<g->getStamina() <<
           "\nweapon = (" << g->getWeapon() << ")\narmor = (" << g->getArmor() << ")" << "\nlevel = " << g->getLevel();
    return out;
}

void Hero::confAttack()
{
    if(getClass()=="Warrior")
        {
            int attack_=(weapon.accuracy + 0.4*getStrength());
            setAttack(attack_);
        }
}
void Hero::setDefence()
    {
        int defence_ = (getArmor().base_armor + 0.2*getAgility());
        defence = defence_;
    }

void Hero::weaponDmg()
{
    if(getClass()=="Warrior")
        int weapon_dmg = getWeapon().base_damage+ 0.4*getStrength();
}
bool Hero::fight(Monster monster, bool state)
{

    int init = rand()%2;
    //while(getCurrHP() > 0 && monster.getCurrHP() > 0)
    {
        if(state)
            {
                cout << "Hero: " << getCurrHP() << " / " << getStamina()<< " HP"<<endl;
                cout << "Monster: " << monster.getCurrHP() << " / " << monster.getStamina() <<endl;
            }
        if (init==0)
        {
          while(getCurrHP() > 0 && monster.getCurrHP() > 0)
            {
                int heroStrike = rand() % 20 + 1 + getAttack();
                if(heroStrike > monster.getDefence())
                {
                    int dmg_dealt = weapon.dmg() - monster.getArmor();
                    monster.dmg(dmg_dealt);
                    cout << getName() << "uderza za " << dmg_dealt << "Potworowi zostalo " << monster.getCurrHP() << " HP";
                }
                if(monster.getCurrHP()<0)
                    break;
                int monsterStrike = rand() %20 +1 +monster.getAttack();
                if(monsterStrike > getDefence())
                {
                    int dmg_dealt = monster.getDamage() - getArmor().base_armor;
                    dmg(dmg_dealt);
                    cout << monster.getName() << "uderza za " << dmg_dealt << "Bohater ma jeszcze " << getCurrHP() << " HP";
                }
                if(getCurrHP()<0)
                    break;
            }
            return (getCurrHP()>0) ? true : false;
        }
        else
        {
           while(getCurrHP() > 0 && monster.getCurrHP() > 0)
            {
                int monsterStrike = rand() %20 +1 +monster.getAttack();
            if(monsterStrike > getDefence())
            {
                int dmg_dealt = monster.getDamage() - getArmor().base_armor;
                dmg(dmg_dealt);
                cout << monster.getName() << "uderza za " << dmg_dealt << "Bohater ma jeszcze " << getCurrHP() << " HP";
            }
            if(getCurrHP()<0)
                break;
            int heroStrike = rand() % 20 + 1 + getAttack();
            if(heroStrike > monster.getDefence())
            {
                int dmg_dealt = weapon.dmg() - monster.getArmor();
                monster.dmg(dmg_dealt);
                cout << getName() << "uderza za " << dmg_dealt << "Potworowi zostalo " << monster.getCurrHP() << " HP";
            }
            if(monster.getCurrHP()<0)
                break;
        }
        return (getCurrHP()>0) ? true : false;
    }
}
}

