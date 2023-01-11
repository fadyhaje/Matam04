#ifndef BattleCard_H
#define BattleCard_H

#include "Card.h" 
#include "../utilities.h"

//Abstract class
class BattleCard : public Card{
    public:
    /*
    * Constructor of BattleCard
    *
    */
    BattleCard(int force, int loot, int damage);
    
    /*
    * Destructor of BattleCard
    *
    */
    virtual ~BattleCard()=default;

    /*
    *
    *prints the information of the card
    *
    */
    virtual void printInfo(std::ostream& os ) const=0;


    virtual void applyEncounter(Player& player) const=0; 


    virtual Card* clone() const=0;


    protected:
    int m_force ;
    int m_loot ; 
    int m_damage ;
};

#endif //BattleCard_H
