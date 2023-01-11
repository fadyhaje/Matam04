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

