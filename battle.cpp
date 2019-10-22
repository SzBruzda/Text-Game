#include "battle.h"

Battle::Battle(Character& player)
{
    this -> pAttackMax = player.getAttackMax();
    this -> pAttackMin = player.getAttackMin();
    this -> pBlockMax = player.getBlockMax();
    this -> pBlockMin = player.getBlockMin();
    this -> current =(rand()%4) + (player.getLvl() - 2);
    this -> pHp = player.getHp();
    this -> lvl = (this -> current > 0) ? this -> current:1;
    this -> monsterAttack = floor(this->lvl * 8 + sqrt(this->lvl) * 2);
    this -> monsterHp = floor(this->lvl * 100 + sqrt(this->lvl) * 10);
    this -> exp = this-> lvl*10;
    this -> gold = (rand() % (this->lvl*10)) + 10;
    this -> names[0] = "Wilka";
    this -> names[1] = "Utopca";
    this -> names[2] = "Upiora";
    this -> names[3] = "Smoka";
    this -> names[4] = "Demona";
    this -> names[5] = "Ghula";
    this -> names[6] = "Wampira";
    this -> monsterName = this -> names[rand()%6];
}

void Battle::menu(Character &player){
    int action = 0;
    cout << "#####################\n";
    cout << "Uda\210e\230 si\251 na polowanie i spotka\210e\230:\n\n";
    cout << this->monsterName << " na " << this->lvl << " poziomie.\n";
    cout << "#####################\n";
    cout << "[1]Walcz\n"
            "[2]Uciekaj(-1oHP)\n";
    cin >> action;
    switch (action) {
    case 1:
        result(player);
        break;
    case 2:
        player.takeHp(10);
        break;
    default:
        cout << "Prosze dokona\206 poprawnego wyboru.\n";
        break;
    }


}

bool Battle::fight(){
    float pAd, pBlock;
    int mAd;
    while(true){
        pBlock = (rand() % (this-> pBlockMax - this -> pBlockMin)) + this -> pBlockMin;
        pAd = (rand() % (this-> pAttackMax - this -> pAttackMin)) + this -> pAttackMin;
        mAd = (rand() % this-> monsterAttack) - pBlock;
        mAd = max(0,mAd);
        cout << "Atakujesz za " << pAd << endl;
        this -> monsterHp -= pAd;
        if(this-> monsterHp < 1){return true;}
        cout << "Zablokowano " << pBlock << " obra\276e\344.\n";
        cout << "Otrzymujesz " << mAd << " obra\276e\344.\n";
        this -> pHp -= mAd;
        if(this-> pHp < 1){return false;}
    }
}

void Battle::result(Character& player){
    if(fight()){
        cout << "Uda\210o Ci sie pokona\206 wroga!\n";
        cout << "Otrzymujesz:\n";
        cout << this->exp << " pkt. do\230wiadczenia.\n";
        cout << this->gold << " szt. z\210ota.\n";
        player.addGold(this->gold);
        player.addExp(this->exp);
        player.takeHp(this->pHp);
        system("pause");
    }else{
        cout << "Niestety zosta\210e\230 pokonany:(\n";
        cout << "Uda\210o Ci si\251 osi\245gn\245\206 " << player.getLvl() << " poziom.\n";
        cout << "Dzi\251kujemy za gr\251!\n";
        system("pause");
        exit(123);
    }
}
