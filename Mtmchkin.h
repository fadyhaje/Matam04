#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <iostream>
#include <cstring>
#include <sstream>
#include <functional>
#include <map>
#include "Card.h"
#include <memory>
#include <queue>
using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ostream;
class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    ~Mtmchkin()=delete;
    Mtmchkin(const Mtmchkin& other)=delete;
    Mtmchkin& operator=(const Mtmchkin& other)=delete;

private:
    queue<unique_ptr<Card>> m_card_Deck;
    queue<unique_ptr<Player>> m_players;
};



#endif /* MTMCHKIN_H_ */
