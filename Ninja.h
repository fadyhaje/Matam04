//
// Created by USER on 11/01/2023.
//

#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja: public Player{
public:
    Ninja(const char* name,int maxHP=100,int force=5) : Player(name,maxHP,force){
            m_coins=10;
}

    virtual Player* clone() const;

    void addCoins(int money) override;

    ~Ninja() =default;



};
#endif //UNTITLED2_NINJA_H
