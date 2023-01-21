//
// Created by USER on 11/01/2023.
//

#ifndef HEALER_H
#define HEALER_H

#include <stdbool.h>
#include <string>
#include "../utilities.h"
#include "Player.h"

using std:string;
class Healer: public Player{
public:
    Healer(string name) : Player(name){}

    virtual Player* clone() const;

    void heal(int addedHP) override;

    ~Healer()=default ;

};

#endif //UNTITLED2_HEALER_H
