#ifndef Mana_H
#define Mana_H

#define DEFAULT_HEAL_Mana 10

#include "Card.h" 
#include "../Players/Healer.h"
#include "../utilities.h"

class Mana : public Card{
    public:
    /*
    * Constructor of Mana class
    *
    * 
    */
    Mana();

    /*
    * Destructor of Mana class
    *
    * 
    */

    ~Mana()=default;

    void applyEncounter(Player& player) const override; 

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

    private:
    int m_heal;
};

#endif //Mana_H
