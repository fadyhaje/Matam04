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
