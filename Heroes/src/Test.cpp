#include <iostream>
#include "Test.h"
#include "Hero.h"
#include "Monster.h"
void test1()
{
    Hero hero1("Varian", "Warrior",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    hero1.setLevel(10);
    Monster monster1("Dragon",40,25,25,20,20,5);
    hero1.fight(monster1);
    hero1.restore();
    cout << hero1 << endl;

}
