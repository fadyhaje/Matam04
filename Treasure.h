#ifndef Treasure_H
#define Treasure_H

#include "Card.h" 
#include "../utilities.h"

#define DEFAULT_COINS_TREASURE 10

class Treasure : public Card{
    public:
    /*
    * Constructor of Treasure class
    *
    *
    */
    Treasure();

    /*
    * Destructor of Treasure class
    *
    *
    */
    ~Treasure()=default ;


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
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;

    private:
    int m_loot ;
};

#endif //Treasure_H
