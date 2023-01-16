//
// Created by USER on 11/01/2023.
//
#include "Player.h"

#ifndef WARRIOR_H
#define WARRIOR_H
class Warrior: public Player{
public:
    Warrior(const char* name,int maxHP=100,int force=5) : Player(name,maxHP,force){
            m_coins=10;
}

    virtual Player* clone() const;

    int getAttackStrength() const override;

    ~Warrior()=default ;

     void printInfo(std::ostream& os ) const override;


};
#endif //UNTITLED2_WARRIOR_H
