#include "Card.h"

std::ostream& operator<<(std::ostream& os,const Card& card){
    card.printInfo(os);
    return os;
}

Card::~ Card(){}
