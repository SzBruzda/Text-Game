#ifndef TAVERN_H
#define TAVERN_H

#include "character.h"

class Tavern
{
private:
    float  hpMissing, gold;
    int playerScore, computerScore;
public:
    Tavern(Character& player);
    void menu(Character& player);
    void drink(Character& player);
    void dice(Character& player);
    void diceGame(Character& player);
    bool diceResult(){return this->playerScore >= this -> computerScore;}
};

#endif // TAVERN_H
