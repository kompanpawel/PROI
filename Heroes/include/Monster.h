#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

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
    Monster(std::string name, int stamina, int attack, int defence, int damage, int armor)
    :
        name{name},
        stamina{stamina},
        currHP{stamina},
        attack{attack},
        defence{defence},
        damage{damage},
        armor{armor},
        modifier{0}
        {

        }

    void dmg (int dmg) {currHP -= dmg;}

    void setName(std::string name_) {name = name_;}
    std::string getName() const {return name;}
    void setStamina(int stamina_) {stamina = stamina_;}
    int getStamina() const {return stamina;}
    void setCurrHP(int currHP_) {currHP = currHP_;}
    int getCurrHP() const {return currHP;}
    void setAttack(int attack_) {attack=attack_+ 2*modifier;}
    int getAttack() const {return attack;}
    void setDefence(int defence_) {defence=defence_ + 2*modifier;}
    int getDefence() const {return defence;}
    void setDamage(int damage_) {damage=damage_ + 1*modifier;}
    int getDamage() const {return damage;}
    void setArmor(int armor_) {armor=armor_ + 1*modifier;}
    int getArmor() const {return armor;}
    void setModifier(int modifier_) {modifier=modifier_;}
    int getModifier() const {return modifier;}
    private:
};

#endif // MONSTER_H
