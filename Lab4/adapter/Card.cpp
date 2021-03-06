#include <iostream>
#include <fstream>
#include <string>
#include "Card.h"

Card::Card(int point,const wchar_t suit){
    this->point = point;
    this->suit = suit;
    pos = position::DECK;
}

int Card::getPoint(){
    return this->point;
}

wchar_t Card::getSuit(){
    return this->suit;
}
Card::~Card(){

}
void Card::changePos(position pos){
    this->pos = pos;
}

Card::position Card::getPos(){
    return pos;
}

std::wostream& operator<< (std::wostream& o, Card card) {
    std::wstring s;
    char c = '0';
    if(card.point >10){
        if(card.point == 11)
            c = 'J';
        else if(card.point == 12)
            c = 'Q';
        else if(card.point == 13)
            c = 'K';
        else if(card.point == 14)
            c = 'A';
    }
    else
        s.append(std::to_wstring(card.point));
    if(c != '0')
        s.append(1,c);
    s.append(1,card.suit);
    
    
    /* s.append(L" _____ \n");
    s.append(L"|");
    s.append(1,c);
    s.append(1,card.suit);
    s.append(L"   ");;
    s.append(L"|\n");
    s.append(L"|     |\n");
    s.append(L"|     |\n");
    s.append(L"|     |\n");
    s.append(L"|"); 
    s.append(L"   ");
    s.append(1,c);
    s.append(1,card.suit);
    s.append(L"|\n");
    s.append(L" ‾‾‾‾‾ \n"); */
    
    o<<s;
    return o;
}

