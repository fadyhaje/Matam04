//
// Created by USER on 15/01/2023.
//

#include "Ninja.h"
void Ninja::addCoins(int coins)
{
    Player::addCoins(2*coins);
}


Player* Ninja::clone() const
{
    return new Ninja(*this);
}

