#include "Player.h"
#include "../utilities.h"
#include "Ninja.h"
#include "Healer.h"
#include "Warrior.h"

using std::string;

Player :: Player(const string name){
    this->m_name = name;
    this->m_level=1;
    this->m_force=DEFAULT_FORCE;
    this->m_maxHP=DEFAULT_MAX_HP;
    this->m_HP=DEFAULT_MAX_HP;
    this->m_coins=DEFAULT_COINS;
}

void Player::levelUp(){
    if(m_level<10){
        m_level++;
    }
}
int Player::getLevel() const{
    return m_level;
}

int Player::getCoins() const{
    return m_coins;
}
string Player::getName() const{
    return m_name;
}
Player::~Player(){}

void Player::buff(int addedForce){
    if(addedForce>=0)
    {
        m_force+=addedForce;
    }
}

std::ostream& operator<<(std::ostream& os,const Player& player){

    const Ninja* temp_ninja=dynamic_cast<const Ninja*>(&player);
    const Healer* temp_Healer = dynamic_cast<const Healer*>(&player);
    const Warrior* temp_warrior = dynamic_cast<const Warrior*>(&player);
    if(temp_ninja != nullptr)
    {
        printPlayerDetails(os,player.m_name,"Ninja",player.m_level,player.m_force,player.m_HP,player.m_coins);
    }
    else if(temp_warrior != nullptr)
    {
        printPlayerDetails(os,player.m_name,"Warrior",player.m_level,player.m_force,player.m_HP,player.m_coins);
    }
    else if(temp_Healer != nullptr){
        printPlayerDetails(os,player.m_name,"Healer",player.m_level,player.m_force,player.m_HP,player.m_coins);
    }
    return os;
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

void Player ::force_damage(){
    if(m_force<=0){
        m_force=0;
    }
    else{
        m_force--;
    }
}

