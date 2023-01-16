#include <iostream>
#include "Player.h"
#include <cstring>

Player :: Player(const char* name,int maxHP,int force){
    int length = strlen(name);
    this->m_name = new char[length+1];
    strcpy(this->m_name,name);
    this->m_level=1;
    if(force>0){
        this->m_force=force;
    }
    else
    {
        this->m_force=DEFAULT_FORCE;
    }
    if(maxHP<=0)
    {
        this->m_maxHP=DEFAULT_MAX_HP;
        this->m_HP=DEFAULT_MAX_HP;
    }
    else
    {
        this->m_maxHP=maxHP;
        this->m_HP=maxHP;
    }
    this->m_coins=0;
}



void Player::levelUp(){
    if(m_level<10){
        m_level++;
    }
}
int Player::getLevel() const{
    return m_level;
}

Player::~Player(){}

void Player::buff(int addedForce){
    if(addedForce>=0)
    {
        m_force+=addedForce;
    }
}

Player :: Player (const Player& other)
{    
    this->m_name=other.m_name;
    m_level = other.m_level ;
    m_force = other.m_force ;
    m_maxHP = other.m_maxHP ;
    m_HP = other.m_HP ;
    m_coins = other.m_coins ;
}

Player& Player::operator=(const Player& other) {
    if (this == &other)
    {
        return *this;
    }
    m_name=other.m_name;
    m_level = other.m_level ;
    m_force = other.m_force ;
    m_maxHP = other.m_maxHP ;
    m_HP = other.m_HP ;
    m_coins = other.m_coins ;
    return *this;
}

void Player::heal(int addedHP){
    if(addedHP>=0)
    {
        if((m_HP+addedHP)>m_maxHP)
        {
            m_HP=m_maxHP;
        }
        else
        {
            m_HP+=addedHP;
        }
    }
}

void Player::damage(int lowHP){
    if(lowHP>=0)
    {
        if((m_HP-lowHP)>=0)
        {
            m_HP-=lowHP;
        }
        else
        {
            m_HP=0;
        }
    }
}

bool Player::isKnockedOut() const{
    if(m_HP==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money>=0)
    {
        m_coins+=money;
    }
}

bool Player::pay(int money){
    if(money>0)
    {
        if(m_coins>=money)
        {
            m_coins-=money;
            return true;
        }
    }
    else
    {
        return true;
    }
    return false;
}

int Player::getAttackStrength() const{
    return (m_level+m_force);
}

std::ostream& operator<<(std::ostream& os,const Player& player){
    player.printInfo(os);
    return os;
}

