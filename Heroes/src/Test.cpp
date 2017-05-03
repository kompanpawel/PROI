#include <iostream>
#include "Test.h"
#include "Hero.h"
#include "Monster.h"
#include "Vector.h"
void test1()
{
    Hero hero1("Varian", "Warrior",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    hero1.setLevel(10);
    Monster monster1("Dragon",40,25,25,20,20,5);
    hero1.fight(monster1);
    hero1.restore();
    cout << hero1 << endl;

}
void test2()
{
    Vector<Hero> v;
    for(int i=0; i<20; i++)
    {
    Hero hero2("Varian", "Warrior",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    hero2.levelUp();
    v.pushback(hero2);
    Hero hero3("Anduin", "Sorcerer",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    v.pushback(hero3);
    }
    cout << v[30] << endl;
    cout << v[5] << endl;

}

void test3()
    {
    Vector<Hero> v;
    for(int i=0; i<50000; i++)
    {
    Hero hero2("Varian", "Warrior",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    hero2.levelUp();
    v.pushback(hero2);
    Hero hero3("Anduin", "Sorcerer",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    v.pushback(hero3);
    }
    v.remove(3);
    cout << v[3];
    Hero hero3("Anduin", "Sorcerer",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    Hero hero4("Banduin", "Sorcerer",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    v+hero3;
    v+hero4;
     //   for(Vector<Hero>::iterator it = v.begin(); it!= v.end(); it++)
    //{
    //    cout << *it << endl;
    //}
    }
