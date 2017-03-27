#ifndef MONSTER_H
#define MONSTER_H
#include "Hero.h"

class Monster
{
    std::string name;
    int stamina;
    int currHP;
    int attack, defence;
    int damage, armor;
    int modifier; //ka¿dy odpoczynek sprawia, ¿e potwory s¹ potê¿niejsze
public:
    Monster()
    :
        name{""},
        stamina{0},
        currHP{0},
        attack{0},
        defence{0},
        damage{0},
        armor{0},
        modifier{0}
        {

        }
    Monster(std::string name, int stamina, int attack, int defence, int damage, int armor, int modifier)
    :
        name{name},
        stamina{stamina},
        currHP{stamina},
        attack{attack},
        defence{defence},
        modifier{modifier}
        {

        }

    void dmg (int dmg) {currHP -= dmg;}

    void setName(std::string name_) {name = name_;}
    std::string getName() const {return name;}
    void setStamina(int stamina_) {stamina = stamina_;}
    int getStamina() const {return stamina;}
    void setCurrHP(int currHP_) {currHP = currHP_;}
    int getCurrHP() const {return currHP;}
    void setAttack(int attack_) {attack= std::max(attack_, 1);}
    int getAttack() const {return attack;}
    void setDefence(int defence_) {defence= std::max(defence_, 1);}
    int getDefence() const {return defence;}
    void setDamage(int damage_) {damage= std::max(damage_, 1);}
    int getDamage() const {return damage;}
    void setArmor(int armor_) {armor= std::max(armor_, 1);}
    int getArmor() const {return armor;}
    void setModifier(int modifier_) {modifier= std::max(modifier_, 1);}
    int getModifier() const {return modifier;}
    private:
};

#endif // MONSTER_H
