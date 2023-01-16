//
// Created by USER on 11/01/2023.
//

#include "Healer.h"
void Healer::heal(int addedHP) {

    Player::heal(addedHP*2);

}

Player* Healer::clone() const
{
    return new Healer(*this);

}

void Healer::printInfo(std::ostream& os ) const{
    printPlayerDetails(os,m_name,"Healer",m_level,m_force,m_HP,m_coins);
}
