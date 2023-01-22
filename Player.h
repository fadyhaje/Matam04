#ifndef Player_h
#define Player_h

#include <stdbool.h>
#include <string>
#include <iostream> 
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5
#define DEFAULT_MAX_HP 10
using namespace std;

class Player{
private:
    
    int m_maxHP;
protected:
     int m_HP;
    string m_name;
    int m_coins;
    int m_level;
    int m_force;
public:
    /**
     * @brief Construct a new Player object
     *
     * @param name - the name of the player
     * @param maxHP - the max hp of the player (default = 100)
     * @param force - the force of the player(default = 5)
     */
    Player(const string name);

    /**
     * @brief Copy constructor of the Player
     *
     * @param player - the player theat will be copied
     */
    Player(const Player& other);

    /**
     * @brief Destroy the Player
     *
     */
   virtual ~Player();

    /**
     * @brief assignment operator
     *
     * @param other - the other is a player that will be equedled to another player
     *
     * @return Player& - player that we want to make it equal to other
     */
    Player& operator=(const Player& other);


    /**
     * @brief make the level up of the player
     *
     */
    void levelUp();

    /**
     * @brief Get the Level of player
     *
     * @return int returns the level of the player
     */
    int getLevel() const;

    /**
     * @brief buff the players force by additional force
     *
     * @param additionalForce - the amount of force that will be added to the player
     */
    void buff(int addedForce);

    /**
     * @brief heal the player by additional hp
     *
     * @param additionalHP - the amount of hp that will be added to player
     */
  virtual void heal(int addedHP);

    /**
     * @brief damage player by damageHP
     *
     * @param damageHP - the amount of damage that will be deduced from the player
     */
    void damage(int lowHP);

    /**
     * @brief returns if player is knocked out
     *
     * @return true - player is knocked out
     * @return false - player isn't knocked out
     */
    bool isKnockedOut() const;

    /**
     * @brief adds coins to the player by additional coins
     *
     * @param additionalCoins - the amount of gold that willl be added to the player
     */
   virtual void addCoins(int money);

    /**
     * @brief the player pay amount of money equals to damageConis
     *
     * @param damageCoins - the amount of gold that will be deduced from the player
     * @return true - if the player can afford the amount of gold
     * @return false - if the player can not afford the amount of gold
     */
    bool pay(int money);

    /**
     * @brief Get the Attack Strength of the player
     *
     * @return int returns the Attack strength of the player
     */
   virtual int getAttackStrength() const;
    //Player()  {}

    virtual Player* clone() const=0;
    
    void printInfo(std::ostream& os ) const;

    friend std::ostream& operator<<(std::ostream& os,const Player& player);
    
     int getCoins() const;

    string getName() const;
    
    void force_damage();

};




#endif /* Player_h */
