#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Players/Player.h"
#include "Cards/Card.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <stdbool.h>
#include <assert.h>
#include <fstream>
#include <string>

using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ostream;

#define MAX_NUM_OF_PLAYERS 6
#define MIN_NUM_OF_PLAYERS 2

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

    Mtmchkin(const Mtmchkin& other)=delete;
    Mtmchkin& operator=(const Mtmchkin& other)=delete;

private:
    int m_playersNumber;
    int m_roundsNumber;
    std::queue<std::unique_ptr<Card>> m_cards;
    std::unique_ptr<Player> m_players[MAX_NUM_OF_PLAYERS];
    int m_sorted[MAX_NUM_OF_PLAYERS];
};



#endif /* MTMCHKIN_H_ */
