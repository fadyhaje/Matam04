#ifndef Gremlin_H
#define Gremlin_H

#include "BattleCard.h"
#include <iostream>
#include "../utilities.h"

#define DEFAULT_FORCE_Gremlin 5
#define DEAFULT_LOOT_Gremlin 2
#define DEFAULT_DAMAGE_Gremlin 10

class Gremlin : public BattleCard{
public:

    /*
    * Constructor of Gremlin class
    *
    *creates a new Gremlin with:
    *     force:6, loot:2, damage ability:10
    *      @return
    *      A new Gremlin object
    */
    Gremlin();





    void applyEncounter(Player& player) const override;


    /*
    * create a new copy of Gremlin using the copy c’tor
    *
    * return:
    *   pointer to a copy of Gremlin
    */
    Card* clone() const override;

    /*
   *
   *prints the information of the card
   *
   */
    void printInfo(std::ostream& os ) const override;

    /*
  * Destructor of Gremlin class
  *
  *
  */
    ~Gremlin()=default;

};

#endif //Gremlin_H
