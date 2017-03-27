#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>
#include "Equipment.h"
#include "Monster.h"

class Hero
{
   std::string name, class_of_hero;
   int strength, agility, intelligence;
   int level;
   int stamina;
   int currHP;
   Weapon weapon;
   Armor armor;
   int attack;
   int defence;
   static double DIFFICULTY; //mno¿nik od którego bêdzie zale¿eæ iloœæ naszych statystyk, wiêkszy oznacza lepsze staty, latwiej pokonaæ potwory :D

public:

    Hero()
    :
        name{""},
        class_of_hero{""},
        strength{0},
        agility{0},
        intelligence{0},
        level{1},
        stamina{0},
        currHP{0},
        weapon{Weapon(0,0)},
        armor{Armor(0)},
        attack{0},
        defence{0}
        {

        }

    Hero(std::string name, std::string class_of_hero, int strength, int agility, int intelligence, int stamina, Weapon weapon, Armor armor, int attack, int defence)
    :
        name{name},
        class_of_hero{class_of_hero},
        strength{strength},
        agility{agility},
        intelligence{intelligence},
        level{1},
        stamina{stamina},
        currHP{stamina},
        weapon{weapon},
        armor{armor},
        attack{attack},
        defence{defence}
        {
            let_him_be();
        }
    ~Hero()
        {
          cout << name << "zginal walczac o spokoj w krainie nawiedzanej przez potwory";
        }

    bool fight(Monster monster, bool state = false);

    void dmg(int dmg) {currHP -= dmg;}
    void restore(Monster monster);
    void levelUp();

    static void setDifficulty (double diff) {DIFFICULTY = diff;}

    void setName (std::string name_) {name = name_;}
    std::string getName() const {return name;}
    void setClass (std::string class_) {class_of_hero = class_;}
    std::string getClass() const {return class_of_hero;}
    void setStrength(int strength_) {strength= std::max(strength_,1);}
    int getStrength() const {return strength;}
    void setAgility(int agility_) {agility= std::max(agility_,1);}
    int getAgility() const {return agility;}
    void setIntelligence(int intelligence_) {intelligence= std::max(intelligence_,1);}
    int getIntelligence() const {return intelligence;}
    void setStamina(int stamina_) {stamina= std::max(stamina_, 1);}
    int getStamina() const {return stamina;}
    void setCurrHP(int currHP_) {currHP= std::max(currHP_, 1);}
    int getCurrHP() const {return currHP;}
    void setWeapon(Weapon weapon_) {weapon = weapon_;}
    Weapon getWeapon() const {return weapon;}
    void setArmor (Armor armor_) {armor = armor_;}
    Armor getArmor() {return armor;}
    void setAttack(int attack_) {attack = attack_;}
    int getAttack() const {return attack;}
    void confAttack();
    void setDefence();//int defence_) {defence= defence_;}
    int getDefence() const {return defence;}
    int getLevel() {return level;}

private:
    int weaponDmg();
    void let_him_be()
    {
        strength = std::max(strength,1);
        agility = std::max(agility,1);
        intelligence = std::max(intelligence, 1);
        currHP = stamina = std::max(stamina, 1);
    }
};

#endif // HERO_H
