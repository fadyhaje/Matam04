//
// Created by USER on 11/01/2023.
//
#include "Player.h"
#ifndef UNTITLED2_HEALER_H
#define UNTITLED2_HEALER_H
class Healer: public Player{
public:
    Healer(const char* name,int maxHP=100,int force=5) : Player(name,maxHP,force){
        m_coins=10;

    }

    virtual Player* clone() const;

    void heal(int addedHP) override;

    ~Healer()=default ;



};

#endif //UNTITLED2_HEALER_H
