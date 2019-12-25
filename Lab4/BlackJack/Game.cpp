#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Shoe.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"
#include <ctime>
using namespace std;
Game::Game(){
    initialize();
}

void Game::initialize(){
    dealer = new Dealer();
    player = new Player();
    shoe = new Shoe();
    bank =0;
}

void Game::gameCycle(){
    bool flag = true;
    char key='c';
    player->printBalance();
    while (key!='y'){
        wcout<<L"������ ������??[y/n]:";
        cin>> key;
        if(key== 'n'|| key == 'N'){
            wcout<<L"����"<<endl;
            return ;
        }
    }
    wcout<<L"����� ������!"<<endl;
    while(true){
        if(!Bet())
            break;
        if(player->getBalance()<=0)
        return ;
    }
    wcout<<L"����� ����� ��������\n\n"<<endl;
    fillHand(*player->hand);
    printHand(*player->hand);
    wcout<<L"\n\n"<<std::endl;
    fillHand(*dealer->hand);
    wcout<<L"���� ������"<<std::endl;
    if(printHandDealer(*dealer->hand)){
        lose();
        return;
    }
    if(player->balance>=bank*2){
        wcout<<L"�������??[y/n]";
        bool kek = true;
        cin>> key;
        if(key=='y'){
            if(player->balance>=bank*3){
                wcout<<L"� ����� �������??[y/n]";
                key ='n';
                cin>> key;
                if(key == 'y'){
                    bank*=3;
                    player->balance-= bank;
                    kek = false;
                }
                if(kek){
                    bank*=2;
                    player->balance-=bank;
                }
            }
        
        }
    }


    if(appendHand(*player->hand)){
        lose();
        return;
    }
    if(appendHandDealer(*dealer->hand)){
        win();
        return;
    }
    if(compare()==0){
        win();
        return;
    }
    else if(compare()==1){
        draw();
        return;
    }
    else
    {
        lose();
        return;
    }
    

    
}
int Game::getBalancePlayer(){
    return player->balance;
}
void Game::lose(){
    wcout<<L"������, �� �������� "<<bank<<endl;
    printHand(*dealer->hand);
    player->hand->refresh();
    dealer->hand->refresh();
    bank =0;
}
void Game::win(){
    wcout<<L"�������, ������ ����� ����������"<<bank<<endl;
    printHand(*dealer->hand);
    player->hand->refresh();
    dealer->hand->refresh();
    bool flag = true;
    wchar_t c = player->hand->cards[0]->getSuit();
    for(Card* cc : player->hand->cards){
        if(c !=cc->getSuit())
            flag = false;
    }
    if(!flag)
        player->balance+=bank*2;
    else
        player->balance+=bank*3;
    bank =0;
}
void Game::draw(){
    wcout<<L"�����, ������ �� �����, ������ ��������� "<<bank<<endl;
    printHand(*dealer->hand);
    player->hand->refresh();
    dealer->hand->refresh();
    player->balance+=bank;
    bank =0;
}

int Game::printHandDealer(Hand& d){
    if(d.cards[0]->getPoint() == 10||d.cards[0]->getPoint() ==11){
        d.printHand();
        if(d.points == 21)
            return 1;
    }
    else
        d.printHandDealer();
        return 0;
}
void Game::printHand(Hand& p){
    p.printHand();
    p.printPoints();
}
void Game::fillHand(Hand &h){
    h.setCard(shoe->getCard());
    h.setCard(shoe->getCard());
    
}
int Game::appendHand(Hand &h){
    try{
    char key = 'c';
    while (key!='n'){
        wcout<<L"��� ����???[y/n]:";
        cin>> key;
        if(key== 'y'|| key == 'Y'){
            
            h.setCard(shoe->getCard());
            wcout<<L"���� ����"<<endl;
            h.printHand();
            h.printPoints();
            if(h.points>21)
                 throw exBust();
        }
        
    }
    }
    catch(std::exception& e){
        std::wcout<<e.what();
        h.points = 0;
        return 1;
    }
    return 0;
}

int Game::Bet(){
    if(player->getBalance()<=0)
        return 0;
    int count =0;
    player->printBalance();
    wcout<<L"������� ������: ";
    cin>> count;
    if(count<=player->getBalance()){
        wcout<<L"������ ������� �������"<<endl;
        bank+=count;
        player->balance-=bank;
        return 0;
    }
    else{
        wcout<<L"� ���� ��� �������"<<endl;
        return 1;
    }
}

int Game::compare(){
    if( player->hand->points>dealer->hand->points)
        return 0;
    if(player->hand->points==dealer->hand->points)
        return 1;
    if(player->hand->points<dealer->hand->points)
        return 2;
}

int Game::appendHandDealer(Hand &h){
    try{
        bool flag = true;
    char key;
    while (flag){
            if(h.points>=17)
                return 0;
            if(h.points<=16&&h.points>=13){
                 std::srand(std::time(nullptr));
                 if(rand()%101<=20){
                     wcout<<L"���� ������"<<endl;
                    h.setCard(shoe->getCard());
                    h.printHand();
                    h.printPoints();
                    break;
                 }
            }
            if(h.points==12){
                 std::srand(std::time(nullptr));
                 if(rand()%101<=95){
                     wcout<<L"���� ������"<<endl;
                    h.setCard(shoe->getCard());
                    h.printHand();
                    h.printPoints();
                    break;
                 }
            }
            if(h.points<12){
                 std::srand(std::time(nullptr));
                 if(rand()%101<=100){
                     wcout<<L"���� ������"<<endl;
                    h.setCard(shoe->getCard());
                    h.printHand();
                    h.printPoints();
                 }
            }
            
        }
        if(h.points>21)
                 throw exBust();
    }
    
    catch(std::exception& e){
        std::wcout<<e.what();
        h.points = 0;
        return 1;
    }
    return 0;
}