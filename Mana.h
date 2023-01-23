#ifndef Mana_H
#define Mana_H

#define DEFAULT_HEAL_MANA 10

#include "Card.h"
#include "../Players/Healer.h"
#include "../utilities.h"

class Mana : public Card{
public:
    /*
    * Constructor of Mana class
     @return
 * *      A new Mana object
    * 
    */
    Mana();

    /*
    * Destructor of Mana class
    *
    * 
    */

    ~Mana()=default;


    /*
    *
    *create a new Mana using the copy c’tor
    * return:
    * pointer to the new copy
    *
    */
    Card* clone() const override;

    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;

    void applyEncounter(Player& player) const override;


private:
    int m_heal;
};

#endif //Mana_H
