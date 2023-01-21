//
// Created by USER on 14/01/2023.
//

#include "Warrior.h"


int Warrior::getAttackStrength() const
{
    return (getLevel()+2*m_force);
}


Player* Warrior::clone() const
{
    return new Warrior(*this);
}
