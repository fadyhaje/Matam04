//
// Created by USER on 15/01/2023.
//

#include "Ninja.h"
void Ninja::addCoins(int coins)
{
    Player::addCoins(2*coins);
}

void Ninja::printInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Ninja",m_level,m_force,m_HP,m_coins);
}

Player* Ninja::clone() const
{
    Ninja temp=new Ninja(*this);
    return temp;
}

