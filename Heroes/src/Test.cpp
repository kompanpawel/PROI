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

    }
void test4()
{
    Vector<Monster> m;
    Monster monster("Weakling",10,5,10,10,10,0);
    m+monster;
    for(int i=0; i<100000; i++)
    {
        Monster monster1("Kobold",10,10,10,10,10,0);
        m+monster1;
    }
    cout << m[0] << endl;
}

void test5()
{
   Vector<Hero> v;
    for(int i=0; i<5; i++)
    {
    Hero hero2("Varian", "Warrior",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    hero2.levelUp();
    v.pushback(hero2);
    Hero hero3("Anduin", "Sorcerer",0,0,0,0,Weapon(0,0),Armor(0),0,0);
    v.pushback(hero3);
    }
    v.popback();
    for(Vector<Hero>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout <<*it << endl;
    }
}

void test6()
{
    Vector<int> a;
    for(int i=0; i<1000; i++)
    {
       a.pushback(i);
    }
    cout << a.showSize();
}
