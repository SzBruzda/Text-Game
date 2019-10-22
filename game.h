#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "blacksmith.h"
#include "tavern.h"
#include "enemy.h"
//#include "battle.h"
class Game
{
private:
    bool gameOn;
    int action, tempSwitch;
    string tempName,tempRasa;
public:
    Game();
    Character player;
    //Functions
    void initCharacter();
    void menu();
    void hunt();
    void printStats();
    //Accessors
    inline bool getGameOn(){return this-> gameOn;}

    //Modifiers

};

#endif // GAME_H
