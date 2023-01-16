//
// Created by USER on 11/01/2023.
//

#include "Ninja.h"
void Ninja::addCoins(int money) {
    Player::addCoins(money*2);
}

Player* Ninja::clone() const
{
    return new Ninja(*this);

}

void Ninja::printInfo(std::ostream& os ) const{
    printPlayerDetails(os,m_name,"Ninja",m_level,m_force,m_HP,m_coins);
}

