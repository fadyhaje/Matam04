#ifndef Witch_H
#define Witch_H

#include "BattleCard.h"
#include <iostream>
#include "../utilities.h"

#define DEFAULT_FORCE_Witch 10
#define DEFAULT_LOOT_Witch 2
#define DEFAULT_DAMAGE_WItch 10

class Witch : public BattleCard{ 
    public:
    /*
    * Constructor of Witch class
    *creates a Witch with:
    *         force:10 , loot:2,  damage ability:10.
    * 
    */
    Witch();

    /*
    * Destructor of Witch class
    *
    * 
    */
    ~Witch() =default;

    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;


    void applyEncounter(Player& player) const override; 

    /*
    *
    *create a new Witch using the copy c’tor
    * return:
    *    pointer to the new copy
    *
    */
    Card* clone() const override;

};

#endif //Witch_H
