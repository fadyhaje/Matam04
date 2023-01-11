#ifndef Dragon_H
#define Dragon_H
#include "BattleCard.h" 
#include <iostream>
#include "../utilities.h"
#include "../Players/Player.h"

#define DEFAULT_FORCE_DRAGON 25
#define DEAFULT_LOOT_DRAGON 1000
#define DEFAULT_DAMAGE_DRAGON 100

class Dragon : public BattleCard{ 
    public:
    /*
    * Costructor of Dragon class
    *
    * creates a dragon with:
    *          force:25, loot:1000,  damage ability: 100(the maximum amount, the player dies immediately)
    */
    Dragon();

    /*
    * Destructor of Dragon class
    *
    * 
    */
   ~Dragon()=default;
   
    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;


    void applyEncounter(Player& player) const override; 

    /*
    * create a new Dragon using the copy c’tor
    * return 
    *     :a pointer to the new Dragon
    *
    */
    Card* clone() const override;

};

#endif //Dragon_H
