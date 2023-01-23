#include <fstream>
#include <iostream>
#include "../Mtmchkin.h"
#include "../Exception.h"
using std::endl;
using std::cout;

int main()
{
   
    int counter=0;
    try{
        Mtmchkin game("deck.txt");
        while(game.isGameOver()==false && counter<100)
        {
            game.playRound();
            game.printLeaderBoard();
            counter++;
        }
    }
    catch(const DeckFileNotFound& e){
        cout << e.what() <<endl;
        return 1;
    }
    catch(const DeckFileFormatError& e){
        cout << e.what() <<endl;
        return 1;
    }
    catch(const DeckFileInvalidSize& e){
        cout << e.what() <<endl;
        return 1;
    }
    catch (const std::bad_alloc& e){
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}

