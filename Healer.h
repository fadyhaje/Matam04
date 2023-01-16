//
// Created by USER on 11/01/2023.
//
#include "Player.h"
#ifndef HEALER_H
#define HEALER_H
class Healer: public Player{
public:
    Healer(const char* name,int maxHP=100,int force=5) : Player(name,maxHP,force){
        m_coins=10;

    }

    virtual Player* clone() const;

    void heal(int addedHP) override;

    ~Healer()=default ;

        void printInfo(std::ostream& os ) const override;



};

#endif //UNTITLED2_HEALER_H
