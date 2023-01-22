#ifndef Card_H
#define Card_H
#include "../Players/Player.h"
#include <string>

//Abstract class
class Card {
public:
/*
* Constructor of Card class
*
*
*/
Card() = default ;

/*
* Destructor of Card class
*
*
*/
virtual ~Card(){}
  
virtual void applyEncounter(Player& player) const=0;


virtual Card* clone() const = 0; 

/*
*
*prints the information of the card
*
*/
virtual void printInfo(std::ostream& os ) const=0;


friend std::ostream& operator<<(std::ostream& os,const Card& card); 



};

#endif //Card_H
