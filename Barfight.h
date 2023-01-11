#ifndef Barfight_H
#define Barfight_H



#define DEFAULT_DAMAGE_BARFIGHT 10
#include "Card.h"


class Barfight : public Card{
    public:
    /*
    * Constructor of Barfight class
    *
    *
    * 
    */
    Barfight();

    /*
    *
    *
    *
    */
    void applyEncounter(Player& player) const override; 

    /*
    * create a new copy of barfight using the copy c’tor
    *
    * return:
    *   pointer to a copy of barfight
    */
    Card* clone() const override;

    /*
    *
    *prints the information of the card
    *
    */
    void printInfo(std::ostream& os ) const override;

    /*
    *destructor
    */
    ~Barfight()=default;

    private:
    int m_damage;
};

#endif //Barfight_H
