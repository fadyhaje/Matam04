#ifndef Merchant_H
#define Merchant_H

#include "Card.h"
#include <iostream>
#include <stdbool.h>
#include "../utilities.h"

#define HP_PRICE 5
#define FORCE_PRICE 10
#define DEFAULT_HP 1
#define DEFAULT_FORCE 1

class Merchant : public Card{
public:
    /*
    * C'tor of Mtmchkin class
    *
    * @return
    *      A new Merchant object.
    */
    Merchant();


    void applyEncounter(Player& player) const override;
    /*
    *
    *prints the card's information- according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printInfo(std::ostream& os ) const override;

    /*
    * create a new copy of Merchant by using the copy constructor
    *
    * return:
    *   pointer to a copy of Merchant
    */
    Card* clone() const override;

    /*
   * Destructor of Merchant class
   *
   *
   */
    ~Merchant()=default;

private:
    void checker_1(Player& player) const;
    void checker_2(Player& player) const;
    int m_hp;
    int m_force;
};

#endif //Merchant_H
