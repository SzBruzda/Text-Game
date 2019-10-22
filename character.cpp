#include "character.h"

Character::Character()
{
    this->name = "";
    this->klasa = "";
    this->rasa = "";
    this->lvl = 0;
    this->exp = 0;
    this->expNextLvl = 0;
    this->hpMax = 0;
    this->hp = 0;
    this->strength = 0;
    this->intellect = 0;
    this->stamina = 0;
    this->agility = 0;
    this->luck = 0;
    this->attackMin = 0;
    this->attackMax = 0;
    this->blockMin = 0;
    this->blockMax = 0;
    this->weapon = 1;
    this->shield = 1;
    this->armor = 1;
    this->boots = 1;
    this->amulet = 1;
    this->gold = 100;
}

//Functions
void Character::lvlUp(){
    int count = 0;
    if(this -> exp >= this -> expNextLvl){
        this -> lvl++;
        this -> exp -= this -> expNextLvl;
        this -> expNextLvl = lvl * 12;
        cout << "Uda\210o Ci sie zdoby\206 poziom,\nulepsz statystyki swojej postaci!\n";
        while(count < 4){
            cout << "################\n";
            cout << "[1] Si\210a \n"
                    "[2] Intelekt \n"
                    "[3] Wytrzyma\210o\230\206 \n"
                    "[4] Zwinno\230\206 \n"
                    "[5] Szcz\251\230cie \n";
            cout << "################\n";
            for (int i = 0; i < 5; i++){
                cout << "Pozosta\210o " << 5 - i << " pkt. do rozdysponowania.\n";
                cin >> this-> tempSwitch;
                switch(tempSwitch){
                case 1:
                    setStrength(1);
                break;
                case 2:
                    setIntellect(1);
                break;
                case 3:
                    setStamina(1);
                break;
                case 4:
                    setAgility(1);
                break;
                case 5:
                    setLuck(1);
                break;
                default:
                    cout << "Prosz\251 poda\206 liczb\251 od 1 do 5\n";
                    i--;
                }
                count = i;
            }
        }

    }
    system("cls");
}


void Character::printStats(){
    cout << "#######################################\n";
    cout << "Nazwa: " << this -> name << endl;
    cout << "Rasa: " << this -> rasa << endl;
    cout << "Klasa: " << this -> klasa << endl;
    cout << "Twoje statystyki: \n"
            "Poziom: " << this -> lvl << "\n" <<
            "Pkt. do\230wiadczenia: " << this -> exp << "/" << this -> expNextLvl << "\n" <<
            "\276ycie: " << this -> hp << "/" << this-> hpMax << "\n" <<
            "Si\210a: " << this -> strength << "\n" <<
            "Inteligencja: " << this -> intellect << "\n" <<
            "Wytrzyma\210o\230\206: " << this -> stamina << "\n" <<
            "Zwinno\230\206: " << this-> agility << "\n" <<
            "Szcz\251\230\206: " << this-> luck << "\n" <<
            "Poziom broni: " << this-> weapon << "\n" <<
            "Poziom tarczy: " << this-> shield << "\n" <<
            "Poziom pancerza: " << this-> armor << "\n" <<
            "Poziom but\242w: " << this-> boots << "\n" <<
            "Poziom amuletu: " << this-> amulet << "\n" <<
            "Atak: " << this-> attackMin << ":" << this->attackMax << "\n"
            "Blok: " << this-> blockMin << ":" << this->blockMax << "\n"
            "Z\210oto: " << this-> gold << "\n";
    cout << "#######################################\n\n";
    system("pause");
}

//Modifiers
void Character::setString(string name, string klasa, string rasa){
    this -> name = name;
    this -> klasa = klasa;
    this -> rasa = rasa;
}

void Character::setAttack(){
    float stat = 0;
    if(this -> klasa == "Wojownik") stat = floor((weapon * 10 + strength + intellect + stamina + agility) / 2);
    else if(this -> klasa == "\210ucznik") stat = floor((weapon + strength * 0.8 + intellect + agility * 1.3 + stamina) / 2);
    else if(this -> klasa == "Czarodziej") stat = floor((weapon + strength * 0.5 + intellect * 1.6 + agility * 1 + stamina) / 2);
    else if(this -> klasa == "Barbarzy\344ca") stat = floor((weapon + strength * 1.4 + intellect * 1 + agility * 0.6 + stamina) / 2);
    else stat = floor((weapon + luck * 1.2 + intellect * 0.4 + agility * 1.4 + stamina) / 2);
    this -> attackMax = stat;
    this -> attackMin = floor(attackMax - sqrt(attackMax));
}

void Character::setHp(){
    this -> hpMax = this->lvl * 50 + this->strength + this->intellect + this->stamina + this->agility + this->luck;
    this -> hp = this->hpMax;
}

void Character::setBlock(){
    this -> blockMax = 2 * (this->armor+this->boots+this->shield) + this->lvl;
    this -> blockMin = floor(this->blockMax - sqrt(this->blockMax));
}
void Character::setStat(int strength, int intellect, int stamina, int agility, int luck){
    this->strength = strength;
    this->intellect = intellect;
    this->stamina = stamina;
    this->agility = agility;
    this->luck = luck + this->amulet;
}

void Character::battleUpgrade(){
    setHp();
    setAttack();
    setBlock();
}

void Character::setAmulet(int num){
    this -> amulet = num;
    setLuck(this->amulet);
}
