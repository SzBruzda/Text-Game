#ifndef BLACKSMITH_H
#define BLACKSMITH_H

#include "character.h"

class Blacksmith
{
private:
    int weaponArr[5];
public:
    Blacksmith(int lvl);
    //Functions
    void buy(Character& player);
    void noMoney();
    bool doYouHave(int one, float two){return one > two;}

    //Modifiers
    void buyWeapon(Character& player);
    void buyArmor(Character& player);
    void buyShield(Character& player);
    void buyBoots(Character& player);
    void buyAmulet(Character& player);
    //Accessors
    float getGold(Character& player){return player.getGold();}

//    void buy(Character& player);
};

#endif // BLACKSMITH_H
