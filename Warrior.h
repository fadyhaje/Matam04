//
// Created by USER on 11/01/2023.
//
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include <stdbool.h>
#include "../utilities.h"
#include <string>
#include "../Players/Player.h"

using std:string;

class Warrior: public Player{
public:
    Warrior(string name) : Player(name){}

    virtual Player* clone() const;

    int getAttackStrength() const override;

    ~Warrior()=default ;

};
#endif //UNTITLED2_WARRIOR_H
