#ifndef Treasure_H
#define Treasure_H

#include "Card.h"
#include "../utilities.h"

#define DEFAULT_COINS_FOR_TREASURE 10

class Treasure : public Card{
public:
    /*
    * Constructor of Treasure class
    *
     @return
  *      A new Treasure object
    *
     * */
    Treasure();

    /*
    * Destructor of Treasure class
    *
    *
    */
    ~Treasure()=default ;

    /*
   *
   *prints the information of the card
   *
   */
    void printInfo(std::ostream& os ) const override;


    void applyEncounter(Player& player) const override;

    /*
    *
    *create a new Treasure using the copy c’tor
    * return:
    *    pointer to the new copy
    *
    */
    Card* clone() const override;


    /*
  * Destructor of Treasure class
  *
  *
  */
    ~Treasure()=default ;

private:
    int m_loot ;
};

#endif //Treasure_H
