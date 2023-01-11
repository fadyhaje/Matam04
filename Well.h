#ifndef Well_H
#define Well_H

#include "Card.h"
#include "../utilities.h"
#include "../Players/Rogue.h"

#define DEFAULT_DAMAGE_Well 10


class Well : public Card{
    public:
    /*
    * Constructor of Well class
    *
    *
    */
    Well();

    /*
    * Destructor of Well class
    *
    *
    */
   ~Well()=default;

    void applyEncounter(Player& player) const override; 

    /*
    * create a new copy of Well using the copy c’tor
    *
    * return:
    *   pointer to a copy of Well
    */
    Card* clone() const override;

    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;

    private:
    int m_damage;
};

#endif //Well_H