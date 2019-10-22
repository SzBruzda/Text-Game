#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class Character
{
private:
    float exp, expNextLvl, hp, hpMax, strength, intellect, stamina,
    agility, luck, attackMin, attackMax, blockMin, blockMax,
    weapon, shield, armor, boots, amulet, gold;
    string name, klasa, rasa;
    int tempSwitch, lvl;
public:
    Character();
    //Functions
    void lvlUp();
    void printStats();
    //Modifiers
    void setString(string name, string klasa, string rasa);
    void setStat(int strength, int intellect, int stamina, int agility, int luck);
    void setStrength(int num){this -> strength += num;}
    void setIntellect(int num){this -> intellect += num;}
    void setStamina(int num){this -> stamina += num;}
    void setAgility(int num){this -> agility += num;}
    void setLuck(int num){this -> luck += num;}
    void setWeapon(int num){this -> weapon = num;}
    void setShield(int num){this -> shield = num;}
    void setArmor(int num){this -> armor = num;}
    void setBoots(int num){this -> boots = num;}
    void setAmulet(int num);
    void setAttack();
    void setHp();
    void takeHp(int num){this -> hp -= num;}
    void restoreHp(float num){this->hp += num;}
    void setBlock();
    void battleUpgrade();
    void addGold(float num){this->gold += num;}
    void takeGold(float num){this->gold -= num;}
    void addExp(int num){this->exp+=num;}
    //Accessors
    float getGold(){return this->gold;}
    int getLvl(){return this->lvl;}
    float getWeapon(){return this->weapon;}
    float getArmor(){return this->armor;}
    float getShield(){return this->shield;}
    float getBoots(){return this->boots;}
    float getAmulet(){return this->amulet;}
    float getHp(){return this->hp;}
    float getHpMax(){return this->hpMax;}
    float getAttackMax(){return this->attackMax;}
    float getAttackMin(){return this->attackMin;}
    float getBlockMax(){return this->blockMax;}
    float getBlockMin(){return this->blockMin;}
};

#endif // CHARACTER_H
