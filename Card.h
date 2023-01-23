#ifndef Card_H
#define Card_H
#include "../Players/Player.h"
#include <string>

//Abstract class
class Card {
public:
/*
* Default constructor of Card class
 * @return
 * *      A new Card object
*/
    Card() = default ;

/*
* Destructor of Card class
*
*
*/
    virtual ~Card() ;


    friend std::ostream& operator<<(std::ostream& os,const Card& card);
    
    virtual void applyEncounter(Player& player) const=0;

    

    virtual Card* clone() const = 0;

/*
*
*prints the information of the card
*
*/
    virtual void printInfo(std::ostream& os ) const=0;


    



};

#endif //Card_H
