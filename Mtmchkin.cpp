#include "Mtmchkin.h"

#include "utilities.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Exception.h"

#define UPPER 1
#define LOWER -1
#define MAX_NUM_OF_LETTERS 15
#define MAX_LEVEL 10
#define MIN_CARDS_NUM 5

using std::find;
using std::cin;
using std::string;
using std::ifstream;
static int get_sorted_index(int sorted[],int number_of_players,int index);
static void enterPlayerDetails(string& players_everything,string& player_name,string& player_class);
static int  check_players_amount();
static void check_players_everthing(std::unique_ptr<Player> players[],int players_num);
static bool check_players_class(string player_class,string name, std::unique_ptr<Player> players[],int index);

Mtmchkin:: Mtmchkin(const std::string &fileName){
    m_roundsNumber=0;
    //  int  countNumOfCards=0;
    printStartGameMessage();

    /*   ifstream source(fileName);
       if (!source) {
           throw DeckFileNotFound();
       }
       std::string cardName;
       while(getline(source,cardName)){
           if (cardName == "Gremlin") {
               m_cards.push(std::unique_ptr<Gremlin>(new Gremlin()));
           } else if (cardName == "Witch") {
               m_cards.push(std::unique_ptr<Witch>(new Witch()));
           } else if (cardName == "Dragon") {
               m_cards.push(std::unique_ptr<Dragon>(new Dragon()));
           } else if (cardName == "Merchant") {
               m_cards.push(std::unique_ptr<Merchant>(new Merchant()));
           } else if (cardName == "Treasure") {
               m_cards.push(std::unique_ptr<Treasure>(new Treasure()));
           } else if (cardName == "Well") {
               m_cards.push(std::unique_ptr<Well>(new Well()));
           } else if (cardName == "Barfight") {
               m_cards.push(std::unique_ptr<Barfight>(new Barfight()));
           } else if (cardName == "Mana") {
               m_cards.push(std::unique_ptr<Mana>(new Mana()));
           }else{
               throw DeckFileFormatError(countNumOfCards);
           }
           countNumOfCards++;
       }
       if (countNumOfCards<MIN_CARDS_NUM){
           throw DeckFileInvalidSize();
       }
   */

    m_cards.push(std::unique_ptr<Gremlin>(new Gremlin()));  m_cards.push(std::unique_ptr<Gremlin>(new Gremlin()));  m_cards.push(std::unique_ptr<Merchant>(new Merchant()));  m_cards.push(std::unique_ptr<Merchant>(new Merchant()));  m_cards.push(std::unique_ptr<Dragon>(new Dragon()));
    m_playersNumber=check_players_amount();
    check_players_everthing(m_players,m_playersNumber);
    for(int i=0;i<m_playersNumber;i++){
        m_sorted[i]=i;
    }
}

int Mtmchkin ::getNumberOfRounds() const
{
    return m_roundsNumber;
}
static bool check_players_class(string player_class,string name, std::unique_ptr<Player> players[],int index){
    if(player_class=="Ninja")
    {
        players[index]=std::unique_ptr<Ninja>(new Ninja(name));
    }
    else if(player_class=="Healer")
    {
        players[index]=std::unique_ptr<Healer>(new Healer(name));
    }
    else if(player_class=="Warrior")
    {
        players[index]=std::unique_ptr<Warrior>(new Warrior(name));
    }
    else
    {
        printInvalidClass();
        return false;
    }
    return true;
}


static bool isvalidPlayerNum(int numOfPlayers){
    if(numOfPlayers<MIN_NUM_OF_PLAYERS || numOfPlayers>MAX_NUM_OF_PLAYERS)
    {
        printInvalidTeamSize();
        return false;
    }
    else
    {
        return true;
    }
}


static int  check_players_amount(){
    string get_num;
    int numOfPlayers;
    for(int i=1;i>0;i++){
        printEnterTeamSizeMessage();
        std::getline(std::cin, get_num);
try{
            numOfPlayers=std::stoi(get_num);
        }
        catch(...){
            printInvalidTeamSize();
            continue;
        }
        if(isvalidPlayerNum(numOfPlayers)){
            return numOfPlayers;
        }
    }
    return 0;
}



static bool islegalchars(string& name)
{
    for (int i = 0; (unsigned)i < name.size(); ++i) {
        if(!(name[i]<='z'&&name[i]>='a')&&!(name[i]<='Z'&&name[i]>='A'))
            return false;
    }
    return true;
}


static bool isValidPlayerName(string& playerName){
    if(playerName.size()>MAX_NUM_OF_LETTERS|| !islegalchars(playerName))
    {
        printInvalidName();
        return false;
    }
    return true;
}

static void check_players_everthing(std::unique_ptr<Player> players[],int players_num){
     std::string players_everything;
    string player_name;
    string player_class;
    bool available_class= false,available_name=false;
    int temp=0;
    while(temp<players_num)
    {
        printInsertPlayerMessage();
        while(!available_class){
            while(!available_name){
                enterPlayerDetails(players_everything,player_name,player_class);
                available_name=isValidPlayerName(player_name);
            }
            available_class = check_players_class(player_class,player_name,players,temp);
            if(!available_class){
                available_name=false;
            }
        }
        available_class=false;
        available_name=false;
        temp++;
    }
}



bool Mtmchkin ::isGameOver() const
{
    int i=0;
    bool flag=false;
    while(i<m_playersNumber)
    {
        if((m_players[i]->isKnockedOut()==false) &&(m_players[i]->getLevel()<MAX_LEVEL))
        {
            flag=true;
            break;
        }
        else
        {
            i++;
            continue;
        }
    }
    if(flag==true)
    {
        return false;
    }
    // printGameEndMessage();
    return true;
}



static void players_new_sort(std::unique_ptr<Player> players[],int sorted[],int number_of_players,int index)
{
    int way;
    if((players[index]->isKnockedOut()==false) &&(players[index]->getLevel()<MAX_LEVEL))
    {
        return;
    }
    int sorted_index=get_sorted_index(sorted,number_of_players,index);
    if(players[index]->getLevel()!=MAX_LEVEL)
    {
        way=UPPER;
    }
    else
    {
        way=LOWER;
    }
    int temp_index=sorted_index+way,current_rank;
    bool flag=temp_index<number_of_players && temp_index>=0;
    while(flag){
        if(!((players[sorted[temp_index]]->isKnockedOut()==false) && (players[sorted[temp_index]]->getLevel()<MAX_LEVEL)))
        {
            break;
        }
        current_rank=sorted[sorted_index];
        sorted[sorted_index]=sorted[sorted_index+way];
        sorted[sorted_index+way]=current_rank;
        sorted_index=get_sorted_index(sorted,number_of_players,index);
        temp_index=sorted_index+way;
        flag=temp_index<number_of_players && temp_index>=0;
    }
    return;
}


static int get_sorted_index(int sorted[],int number_of_players,int index)
{
    for(int i=0;i<number_of_players;i++)
    {
        if(sorted[i]!=index)
        {
            continue;
        }
        else
        {
            return i;
        }
    }
    return 0;
}



void Mtmchkin ::playRound()
{
    printRoundStartMessage(++m_roundsNumber);
    int i=0;
    bool game_final;
    while(i<m_playersNumber)
    {
        if(!((m_players[i]->isKnockedOut()==false) &&(m_players[i]->getLevel()<MAX_LEVEL)))
        {
            i++;
            continue;
        }
        else
        {
            std::unique_ptr<Card> firstCard=std::move( m_cards.front());
            printTurnStartMessage(std::string(m_players[i]->getName()));
            firstCard->applyEncounter(*m_players[i]);
            m_cards.push(std::move(firstCard));
            m_cards.pop();
            players_new_sort(m_players,m_sorted,m_playersNumber,i);
            i++;
        }
    }
    game_final=isGameOver();
    if(game_final)
    {
        printGameEndMessage();
    }
}


void Mtmchkin::printLeaderBoard() const
{
    int i=1;

    printLeaderBoardStartMessage();
    while(i<=m_playersNumber)
    {
        printPlayerLeaderBoard(i, *(m_players[m_sorted[i-1]]));
        i++;
    }
}



static void enterPlayerDetails(string& players_everything,string& player_name,string& player_class)
{

    std::getline(std::cin, players_everything);
    std::size_t ch=players_everything.find(" ",0);
    player_name= players_everything.substr(0,ch);
    player_class=players_everything.substr(ch+1);

}

