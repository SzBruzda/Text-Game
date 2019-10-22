#include "game.h"

Game::Game()
{
    gameOn = true;
    action = 0;
}
//Functions

void Game::initCharacter(){



    cout << "Zagrajmy w gr\251! \n"
            "Podaj imi\251 postaci: \n";
    cin >> this -> tempName;

    cout << "Wybierz ras\251: \n"
            "[1] Cz\210owiek \n"
            "[2] Elf \n"
            "[3] Wilko\210ak \n"
            "[4] Krasnolud \n"
            "[5] Ork \n";
    cin >> this -> tempSwitch;
    system( "cls" );

    switch(this -> tempSwitch){
        case 1:{
            this -> tempRasa = "Cz\210owiek";
            }break;
        case 2:{
            this -> tempRasa = "Elf";
            }break;
        case 3:{
            this -> tempRasa = "Krasnolud";
            }break;
        case 4:{
            this -> tempRasa = "Wilko\210ak";
            }break;
        case 5:{
            this -> tempRasa = "Ork";
            }break;
        default:
            cout << "Klasa nie rozpoznana!";
    }

    cout << "Wybierz klas\251: \n"
            "[1] Wojownik \n"
            "[2] \210ucznik \n"
            "[3] Czarodziej \n"
            "[4] Barbarzy\344ca \n"
            "[5] Z\210odziej \n";
    cin >> this -> tempSwitch;
    system( "cls" );

    switch(this -> tempSwitch){
        case 1:{
            player.setString(this->tempName,"Wojownik", this -> tempRasa);
            player.setStat(9,11,7,10,6);
            }break;
        case 2:{
           player.setString(this->tempName,"\210ucznik", this -> tempRasa);
            player.setStat(2,14,12,11,5);
            }break;
        case 3:{
            player.setString(this->tempName,"Czarodziej", this -> tempRasa);
            player.setStat(16,4,1,15,6);
            }break;
        case 4:{
            player.setString(this->tempName,"Barbarzy\344ca", this -> tempRasa);
            player.setStat(14,10,8,5,4);
            }break;
        case 5:{
            player.setString(this->tempName,"Z\210odziej", this -> tempRasa);
            player.setStat(20,3,4,9,10);
            }break;
        default:
            cout << "Klasa nie rozpoznana!";
    }
    system( "cls" );
    player.lvlUp();
    player.battleUpgrade();
}
void Game::menu(){

    cout << "#############################\n";
    cout << "Wybierz co chcesz zrobi\206:\n"
            "[1]Poluj\n"
            "[2]Id\253 do tawerny\n"
            "[3]Id\253 do kowala i kup lepszy ekwipunek\n"
            "[4]Sprawd\253 statystyki.\n"
            "[5]Zako\344cz rozgrywk\251." << endl;
    cout << "#############################\n";
    cin >> this -> action;
    switch (action){
    case 1:{
        Battle battle(player);
//        Enemy monster((rand()%4) + (player.getLvl() - 2), battle);
        battle.menu(player);
        system( "cls" );
        player.lvlUp();
        if(player.getHp() < 0){
            cout << "Niestety zostałeś zabity uciekając\n"
                    "Dziekujemy za grę\n";
            system("pause");
            this -> gameOn = false;
        }
        }break;
    case 2:{
        Tavern tavern(player);
        tavern.menu(player);
        }break;
    case 3:{
        Blacksmith blacksmith(player.getLvl());
        system( "cls" );
        blacksmith.buy(player);
        }break;
    case 4:
        system( "cls" );
        printStats();
        break;
    case 5:
        this -> gameOn = false;
    }
}

void Game::printStats(){
    player.printStats();
}

//Accessors


//Modifiers
