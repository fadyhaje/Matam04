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
