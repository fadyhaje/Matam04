//
// Created by USER on 14/01/2023.
//

#include "Healer.h"
void Healer::heal(int addtional_HP)
{
    Player::heal(2*addtional_HP);
}

Player* Healer::clone() const
{
    return new Healer(*this);
}
