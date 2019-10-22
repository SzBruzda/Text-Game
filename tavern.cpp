#include "tavern.h"

Tavern::Tavern(Character& player)
{
    this->hpMissing = player.getHpMax() - player.getHp();
    this->playerScore = 0;
    this->computerScore = 0;
}

void Tavern::menu(Character &player){
    int action = 0;
    system("cls");
    while(action != 3){

        cout << "Witaj w tawernie!\n";
        cout << "Wybierz co chcesz robi\206\n";
        cout << "#########################\n";
        cout << "[1]Napij si\251 piwa(5 szt. z\210ota)\n"
                "[2]Zagraj w ko\230ci\n"
                "[3]Powr\242t\n";
        cout << "#########################\n";
        cin >> action;
        switch (action) {
        case 1:
            system("cls");
            drink(player);
            break;
        case 2:
            system("cls");
            dice(player);
            break;
        case 3:
            break;
        default:
            cout << "Prosze dokona\206 w\210a\230ciwego wyboru\n";
            break;
        }
    }
}

void Tavern::drink(Character &player){
    float restoreHp = 0;

    if(player.getGold() > 4){
        if(hpMissing > 0){
            if(hpMissing < 20){restoreHp = player.getHpMax() - player.getHp();}
            else{restoreHp = 20;}
            player.restoreHp(restoreHp);
            cout << "#########################\n";
            cout << "Napi\210e\230 si\251 zimnego piwka i odzyska\210e\230 " << restoreHp <<
                 " pkt. \276ycia.\n";
            cout << "Masz teraz " << player.getHp() << "/" << player.getHpMax()<<
                 " pkt. \276ycia.\n";
            cout << "#########################\n";
            this->hpMissing = player.getHpMax() - player.getHp();
        }else{
            cout << "Jeste\230 w pe\210ni zdrowy ale piwko i tak smakowa\210o wybornie\n";
        }
        player.takeGold(5);
    }else{
        cout << "#########################\n";
        cout << "Nie sta\206 Ci\251 na piwo:(\n";
        cout << "#########################\n\n";
    }


}

void Tavern::dice(Character& player){
    cout << "Zagraj w ko\230ci!\n";
    cout << "#########################\n";
    cout << "Wygrywasz: podwajamy wk\210ad\n"
            "Przegrywasz: tracisz wszystko\n";
    cout << "#########################\n";
    while(true){
        int action;
        cout << "[1] Zagraj\n"
                "[2] Powr\242t\n";
        cin >> action;
        if(action == 1 ){
            cout << "##################################\n";
            cout << "Podaj kwot\251 jak\245 chcesz postawi\206\n";
            cin >> this -> gold;
            diceGame(player);
        }else if(action == 2){
            break;
        }else{
            cout << "Prosz\251 dokona\206 poprawnego wyboru.\n";
        }
    }
}

void Tavern::diceGame(Character &player){
    system("cls");
    if(player.getGold() >= gold){
        this -> playerScore = (rand() % 18) + 3;
        this -> computerScore = (rand() % 18) + 3;
        cout << "Tw\242j wynik: " << this -> playerScore << endl;
        cout << "Wynik przeciwnika: " << this -> computerScore << endl;
        if (this -> playerScore == this -> computerScore){
            cout << "Remis! Nic nie tracisz!\n";
        }else if(diceResult()){
            cout << "Wygrywasz! " << gold * 2 << " szt. z\210ota\n";
            player.addGold(gold*2);
        }else{
            cout << "Przegrywasz!\n";
            player.takeGold(gold);
        }
    }
}
