//
// Created by USER on 11/01/2023.
//

#include "Warrior.h"
Player* Warrior::clone() const
{
    return new Warrior(*this);

}

int Warrior::getAttackStrength() const{
    return (m_level+(m_force*2));
}

void Warrior::printInfo(std::ostream& os ) const{
    printPlayerDetails(os,m_name,"Warrior",m_level,m_force,m_HP,m_coins);
}
