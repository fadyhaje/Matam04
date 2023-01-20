//
// Created by USER on 14/01/2023.
//

#include "Warrior.h"


int Warrior::getAttackStrength() const
{
    return (2*m_force+m_level);
}

void Warrior::printInfo(std::ostream& os ) const
{
    printPlayerDetails(os,m_name,"Warrior",m_level,m_force,m_HP,m_coins);
}

Player* Warrior::clone() const
{
    Warrior temp=new Warrior(*this);
    return temp;
}
