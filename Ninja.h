//
// Created by USER on 11/01/2023.
//

#ifndef NINJA_H
#define NINJA_H

#include "Player.h"
#include <stdbool.h>
#include <string>
#include "../utilities.h"
#include "Player.h"

using std:string;
class Ninja: public Player{
public:
    Ninja(string name) : Player(name){}

    virtual Player* clone() const;

    void addCoins(int money) override;

    ~Ninja() =default;

};
#endif //UNTITLED2_NINJA_H
