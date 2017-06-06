#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include "Hero.h"

class Hero;
class Monster
{
    std::string name;
    int stamina;
    int currHP;
    int attack, defence;
    int damage, armor;
    int modifier; /*every rest makes monsters stronger*/
    int type; /**1 for easy, 10 for medium, 100 for hard and 1000 for bosses*/

public:
    Monster() /**default constructor*/
    :
        name{""},
        stamina{0},
        currHP{0},
        attack{0},
        defence{0},
        damage{0},
        armor{0},
        modifier{0},
        type{1}
        {

        }
    Monster(std::string name, int stamina, int attack, int defence, int damage, int armor, int mod, int type) /**main constructor of monsters*/
    :
        name{name},
        stamina{stamina+2*mod},
        currHP{stamina+2*mod},
        attack{attack+mod},
        defence{defence+mod},
        damage{damage+mod},
        armor{armor+mod},
        modifier{mod},
        type{type}
        {

        }
    Monster(const Monster& another) /**copying constructor*/
    :
        name{another.name},
        stamina{another.stamina},
        currHP{another.stamina},
        attack{another.attack},
        defence{another.defence},
        damage{another.damage},
        armor{another.armor},
        modifier{another.modifier},
        type{another.type}
    {

    }
    virtual ~Monster()
        {

        }
    void dmg (int dmg) {currHP -= dmg;} /**amount of damage taken by hero or monster*/
    void restore();
    virtual bool fight(Hero *hero) = 0;

    void setName(std::string name_) {name = name_;}
    std::string getName() const {return name;}
    void setStamina(int stamina_) {stamina = stamina_+ modifier;}
    int getStamina() const {return stamina;}
    void setCurrHP(int currHP_) {currHP = currHP_;}
    int getCurrHP() const {return currHP;}
    void setAttack(int attack_) {attack=attack_ + modifier;}
    int getAttack() const {return attack;}
    void setDefence(int defence_) {defence=defence_ + modifier;}
    int getDefence() const {return defence;}
    void setDamage(int damage_) {damage=damage_ + modifier;}
    int getDamage() const {return damage;}
    void setArmor(int armor_) {armor=armor_ + modifier;}
    int getArmor() const {return armor;}
    void setModifier(int modifier_) {modifier=modifier_;}
    int getModifier() const {return modifier;}
    void setType(int type_) {type=type_;}
    int getType() const {return type;}
    void setAllStats();
    private:
};

std::ostream& operator<<( std::ostream& out, const Monster& g );
#endif // MONSTER_H
