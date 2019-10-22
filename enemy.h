#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <math.h>
#include <battle.h>
using namespace std;

class Enemy
{
private:
    int lvl, gold, exp;
    float attackMax, hp;
    string names[7], name;
public:
    Enemy(int lvl, Battle& battle);
    ~Enemy(){cout << "booom";}
    //Accessors
    int getAtack(){return this-> attackMax;}
    float getHp(){return this-> hp;}
    string getName(){return this-> name;}
    int getGold(){return this->gold;}
    int getExp(){return this-> exp;}
    int getLvl(){return this-> lvl;}
};

#endif // ENEMY_H
