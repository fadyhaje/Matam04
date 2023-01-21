//
// Created by USER on 14/01/2023.
//

#include "Healer.h"
void Healer::heal(int addtional_HP)
{
    Player::heal(2*addtional_HP);
}


void Healer ::printInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Healer",m_level,m_force,m_HP,m_coins);
}

Player* Healer::clone() const
{
    return new Healer(*this);
}
