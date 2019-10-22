#include "enemy.h"

Enemy::Enemy(int lvl, Battle& battle)
{
    this -> lvl = (lvl>0)?lvl:1;
    this -> attackMax = floor(lvl * 8 + sqrt(lvl) * 2);
    this -> hp = floor(lvl * 100 + sqrt(lvl) * 10);
    this -> gold = (rand() % (lvl*10)) + 10;
    this -> names[0] = "Wilka";
    this -> names[1] = "Utopca";
    this -> names[2] = "Upiora";
    this -> names[3] = "Smoka";
    this -> names[4] = "Demona";
    this -> names[5] = "Ghula";
    this -> names[6] = "Wampira";
    this -> name = this -> names[rand()%6];
    this -> exp = this-> lvl*10;
    battle.setExp(this->exp);
    battle.setGold(this->gold);
    battle.setMonsterHp(this->hp);
    battle.setMonsterLvl(this->lvl);
    battle.setMonsterName(this->name);
    battle.setMonsterAttack(this->attackMax);
}

