#include "blacksmith.h"

Blacksmith::Blacksmith(int lvl)
{
    for(int i = 0; i < 5; i++){
        if(lvl > 3){
           this->weaponArr[i] = (rand() % 5) - (lvl - 3);
        }else{
           this->weaponArr[i] = (rand() % (lvl + 2)) + 1;
        }
    }
}

void Blacksmith::buy(Character& player){
    int tempSwitch = 0;
    cout << "Witaj u kowala:\n";
    cout << "Wybierz co chcia\210 by\230 kupi\206\n";
    cout << "############################\n";
    while(tempSwitch != 6){
        cout << "W nawiasach akutalne poziomy przedmiot\242w!\n";
        cout << "Twoje złoto: " << player.getGold() << endl;
        cout << "#########################################\n";
        cout << "[1] Bro\344 lvl: " << this->weaponArr[0] <<
                 " (" << player.getWeapon() << ") cena: " <<
                this->weaponArr[0] * 85 << " sztuk z\210ota.\n";
        cout << "[2] Pancerz lvl: " << this->weaponArr[1] <<
                 " (" << player.getArmor() << ") cena: " <<
                this->weaponArr[0] * 60 << " sztuk z\210ota.\n";
        cout << "[3] Tarcz\251 lvl: " << this->weaponArr[2] <<
                 " (" << player.getShield() << ") cena: " <<
                this->weaponArr[0] * 55 << " sztuk z\210ota.\n";
        cout << "[4] Buty lvl: " << this->weaponArr[3] <<
                 " (" << player.getBoots() << ") cena: " <<
                this->weaponArr[0] * 30 << " sztuk z\210ota.\n";
        cout << "[5] Amulet lvl: " << this->weaponArr[4] <<
                 " (" << player.getAmulet() << ") cena: " <<
                this->weaponArr[0] * 35 << " sztuk z\210ota.\n";
        cout << "[6] Dziekuj\251 ale to ju\276 wszystko.\n";

        cin >> tempSwitch;
        system("cls");
        switch (tempSwitch) {
        case 6:
            break;
        case 1:
            if(doYouHave(weaponArr[0],player.getWeapon())){
                if(getGold(player) >= this->weaponArr[0] * 85){
                    buyWeapon(player);
                }else{
                    noMoney();
                }
            }else{
                cout << "\nPosiadasz ju\276 taki lub lepszy przedmiot!\n\n";
            }

            break;
        case 2:
            if(doYouHave(weaponArr[1],player.getArmor())){
                if(getGold(player) >= this->weaponArr[1] * 60){
                    buyArmor(player);
                }else{
                    noMoney();
                }
            }else{
                cout << "\nPosiadasz ju\276 taki lub lepszy przedmiot!\n\n";
            }
            break;
        case 3:
            if(doYouHave(weaponArr[2],player.getShield())){
                if(getGold(player) >= this->weaponArr[2] * 55){
                    buyShield(player);
                }else{
                    noMoney();
                }
            }else{
                cout << "\nPosiadasz ju\276 taki lub lepszy przedmiot!\n\n";
            }
            break;
        case 4:
            if(doYouHave(weaponArr[3],player.getBoots())){
                if(getGold(player) >= this->weaponArr[3] * 30){
                    buyBoots(player);
                }else{
                    noMoney();
                }
            }else{
                cout << "\nPosiadasz ju\276 taki lub lepszy przedmiot!\n\n";
            }

            break;
        case 5:
            if(doYouHave(weaponArr[4],player.getAmulet())){
                if(getGold(player) >= this->weaponArr[4] * 35){
                    buyAmulet(player);
                }else{
                    noMoney();
                }
            }else{
                cout << "\nPosiadasz ju\276 taki lub lepszy przedmiot!\n\n";
            }
            break;
        }
    }

}

void Blacksmith::buyWeapon(Character &player){
    player.setWeapon(this ->weaponArr[0]);
    player.takeGold(this->weaponArr[0] * 85);
    cout << "\nZakup udany!\n\n";
}

void Blacksmith::buyArmor(Character &player){
    player.setArmor(this ->weaponArr[1]);
    player.takeGold(this->weaponArr[1] * 60);
    cout << "\nZakup udany!\n\n";
}

void Blacksmith::buyShield(Character &player){
    player.setShield(this ->weaponArr[2]);
    player.takeGold(this->weaponArr[2] * 55);
    cout << "\nZakup udany!\n\n";
}

void Blacksmith::buyBoots(Character &player){
    player.setBoots(this ->weaponArr[3]);
    player.takeGold(this->weaponArr[3] * 30);
    cout << "\nZakup udany!\n\n";
}

void Blacksmith::buyAmulet(Character &player){
    player.setAmulet(this ->weaponArr[4]);
    player.takeGold(this->weaponArr[4] * 35);
    cout << "\nZakup udany!\n\n";
}

void Blacksmith::noMoney(){
    cout << "############################\n";
    cout << "Niestety nie masz wystarczaj\245co du\276o z\210ota.\n";
    cout << "############################\n";
}
