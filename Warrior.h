//
// Created by USER on 11/01/2023.
//
#include "Player.h"

#ifndef UNTITLED2_WARRIOR_H
#define UNTITLED2_WARRIOR_H
class Warrior: public Player{
public:
    Warrior(const char* name,int maxHP=100,int force=5) : Player(name,maxHP,force){}

    virtual Player* clone() const;

    int getAttackStrength() const override;

    ~Warrior()=default ;



};
#endif //UNTITLED2_WARRIOR_H
