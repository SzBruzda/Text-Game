#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
//#include "enemy.h"
#include <cstdlib>
#include <algorithm>
#include <math.h>

class Battle
{
private:
    int pAttackMax, pAttackMin, pBlockMax, pBlockMin, pHp, monsterHp, monsterAttack;
    int lvl, exp, gold, current;
    string monsterName, names[7];
public:
    Battle(Character& player);
    void menu(Character& player);
    bool fight();
    void result(Character& player);
    //Modifiers
    void setExp(int num){this -> exp = num;}
    void setGold(int num){this -> gold = num;}
    void setMonsterHp(int num){this -> monsterHp = num;}
    void setMonsterAttack(int num){this -> monsterAttack = num;}
    void setMonsterLvl(int num){this -> lvl = num;}
    void setMonsterName(string name){this -> monsterName = name;}

};

#endif // BATTLE_H
