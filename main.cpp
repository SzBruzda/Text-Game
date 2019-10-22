#include "game.h"

int main()
{
    srand(time(NULL));
    Game game;
    game.initCharacter();
    while(game.getGameOn()){
        system("cls");
        game.menu();
    }
    return 0;
}
