#include <fstream>
#include <iostream>
#include "../Mtmchkin.h"
#include "../Exception.h"
using std::endl;
using std::cout;

int main()
{
    try{
        Mtmchkin game("deck.txt");
        while(game.isGameOver()==false)
        {
           game.playRound();
           game.printLeaderBoard();
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

