#ifndef Merchant_H
#define Merchant_H

#include "Card.h" 
#include <iostream>
#include <stdbool.h>
#include "../utilities.h"

#define HP_PRICE_FOR_MERCHANT 5
#define FORCE_PRICE_FOR_MERCHANT 10
#define DEFAULT_HP_FOR_MERCHANT 1
#define DEFAULT_FORCE_FOR_MERCHANT 1

class Merchant : public Card{
    public:
    /*
    * Constructor of Merchant class
    *
    * 
    * 
    */
    Merchant();

    /*
    * Destructor of Merchant class
    *
    * 
    */
    ~Merchant()=default;

    void applyEncounter(Player& player) const override;

    /*
    * create a new copy of Merchant using the copy c’tor
    *
    * return:
    *   pointer to a copy of Merchant
    */
    Card* clone() const override;

    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;

    private:
    int m_hp;
    int m_force;
};

#endif //Merchant_H
