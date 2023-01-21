using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ostream;


void isvalidsize(int size);///if the size of cards less than 5 throw exception
bool isvalidPlayerNum(int numOfPlayer);///if the number of players between 2 and 6
bool islegalchars(string& name);///if the name consisted of small and capital chars
bool isValidPlayerName(string& playerName);///if the name less than 15 chars and has legal chars
void createCardDeck(const std::string &fileName,queue<unique_ptr<Card>>& cardDeck);///add the card to the deck cards
bool addPlayer(queue<unique_ptr<Player>>& Players,string& playerClass,string& playerName);///add a new player &&checks if the class name is legal


 Mtmchkin:: Mtmchkin(const std::string &fileName)
{
     int  player_num;
     string tempName,tempType;
     bool flag;
    createCardDeck(fileName,m_card_Deck);
    isvalidsize(m_card_Deck.size());

    printStartGameMessage();
    do{
        printEnterTeamSizeMessage();
        cin>>player_num;
        flag= isvalidPlayerNum(player_num);
    }while(!flag);

    do {
        printInsertPlayerMessage();
        cin>>tempName>>tempType;
        ///////////////????????????
        if(  isValidPlayerName(tempName))
        {
            addPlayer(m_players, tempType, tempName);
        }

    }while(player_num!=m_players.size());

}
void isvalidsize(int size)
{
     if(size<5)
     {
         throw DeckFileInvalidSize();
     }
}
void createCardDeck(const std::string &fileName,queue<unique_ptr<Card>>& cardDeck)
{
    string cardName;
     ifstream source(fileName);
     if(!source.is_open())
    {
        throw DeckFileNotFound();
    }
    while(!source.eof())
    {
        if(!getline(source,cardName)) {
            throw DeckFileFormatError(cardDeck.size());
        }

    else {

            if (cardName == "Gremlin") {
                cardDeck.push(unique_ptr<Card>(new Gremlin()));
            } else if (cardName == "Witch") {
                cardDeck.push(unique_ptr<Card>(new Witch()));
            } else if (cardName == "Dragon") {
                cardDeck.push(unique_ptr<Card>(new Dragon()));
            } else if (cardName == "Merchant") {
                cardDeck.push(unique_ptr<Card>(new Merchanr()));
            } else if (cardName == "Treasure") {
                cardDeck.push(unique_ptr<Card>(new Treasure()));
            } else if (cardName == "Well") {
                cardDeck.push(unique_ptr<Card>(new Well()));
            } else if (cardName == "Barfight") {
                cardDeck.push(unique_ptr<Card>(new Barfight()));
            } else if (cardName == "Mana") {
                cardDeck.push(unique_ptr<Card>(new Mana()));
            }
        }
}
}

bool isvalidPlayerNum(int numOfPlayer){


    if(numOfPlayer<2||numOfPlayer>6)
    {
        printInvalidTeamSize();
        return false;
    }
    else
    {
        return true;
    }
 }
bool addPlayer(queue<unique_ptr<Player>>& Players,string& playerClass,string& playerName){
     if(playerClass=="Ninja")
     {
         Players.push(unique_ptr<Player> (new Ninja(playerName)));
         return true;
     }
     else
         if(playerClass=="Healer")
    {
        Players.push(unique_ptr<Player> (new Healer(playerName)));
        return true;
    }
         else
             if(playerClass=="Warrior")
         {
             Players.push(unique_ptr<Player> (new Warrior(playerName)));
             return true;
         }
     else {
         printInvalidClass();
         return false;
     }
 }
bool islegalchars(string& name)
{
    for (int i = 0; i < name.size(); ++i) {
        if(!(name[i]<='z'||name[i]>='a')||!(name[i]<='Z'&&name[i]>='A')&&name[i]==' ')
            return false;
    }
    return true;
}
bool isValidPlayerName(string& playerName){
     if(playerName.size()>15|| !islegalchars(playerName))
     {
         printInvalidName();
         return false;
     }
     return true;
 }


#include "Mtmchkin.h"
#include "utilities.h"
#include <map>

#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Exception.h" 

#define MAX_LETTERS_NUMBER 15
#define MAX_LEVEL 10
#define MOVE_RIGHT 1
#define MOVE_LEFT -1
#define MINIMUM_NUMBER_OF_CARDS 5

using std::ifstream;
using std::cin;
using std::find;

//return a valid number that represents the players's number
static int handle_players_number(){
   int players_number;
   printEnterTeamSizeMessage();
   bool valid=false;
   while(!valid){
      std::string number;
      std::getline( std::cin,number );
      try{
         players_number = std::stoi(number);
      }
      catch(...){
         printInvalidTeamSize();
         printEnterTeamSizeMessage();
         continue;
      }
   
      if((players_number >= MIN_NUM_OF_PLAYERS) && (players_number <= MAX_NUM_OF_PLAYERS)){
         return players_number;
      }
      else{
         printInvalidTeamSize();
         printEnterTeamSizeMessage();
      }
   }
   return 0;// won't get here
}

// checks if the name is OK   
static bool handle_players_name(std::string *playerName){
   if(playerName->length()>MAX_LETTERS_NUMBER) {
      printInvalidName();
      return false;
   }
   for(std::size_t i=0;i<playerName->length();i++){
      char letter=playerName->at(i);
      if ((letter >= 'A' && letter <= 'Z' ) || ( letter >= 'a' && letter <= 'z' ))
      {
      continue;  // cheking valid letters
      }  
      else{
         printInvalidName();  
         return false;
      }
   }
   return true;
}

//adds the player to the game if the player's class is OK 
static bool handle_players_class(std::string playerClass,std::string name, std::unique_ptr<Player> players[],int place){
   std::map<std::string, int> play;
   play["Rogue"] = 0;
   play["Wizard"] = 1;
   play["Fighter"] = 2;
   if(!play.count(playerClass)){
      printInvalidClass();
      return false;
   }
   switch (play[playerClass]){
      case 0:
         players[place]=std::unique_ptr<Rogue>(new Rogue(name));
         break;
      case 1:
         players[place]=std::unique_ptr<Wizard>(new Wizard(name));
         break;
      case 2:
         players[place]=std::unique_ptr<Fighter>(new Fighter(name));
         break;
      default:
         printInvalidClass();
         return false;
      }
      return true;
}


static void handle_players_details(std::unique_ptr<Player> players[],int players_num ){
   std::string player_Details;
   std::string current_name;
   std::string current_job;
   bool valid_class= false,valid_name=false;
   for(int i=0;i<players_num;i++){
      printInsertPlayerMessage();
      while(!valid_class){
         while(!valid_name){
           std::getline(std::cin, player_Details);
           std::size_t ch=player_Details.find(" ",0);
           current_name= player_Details.substr(0,ch);
           current_job=player_Details.substr(ch+1);
           valid_name=handle_players_name(&current_name);
         }
         valid_class = handle_players_class(current_job,current_name,players,i);
         if(!valid_class){
           valid_name=false;
         }
      }
      valid_class=false;
      valid_name=false;
   }
}


Mtmchkin:: Mtmchkin(const std::string &fileName){
   printStartGameMessage();
   m_roundsNumber=0;
   ifstream source(fileName);
   if (!source) {
	   throw DeckFileNotFound();
   }
   std::map<std::string, int> cards;
   cards["Fairy"] = 0;
   cards["Dragon"] = 1;
   cards["Vampire"] = 2;
   cards["Goblin"] = 3;
   cards["Pitfall"] = 4;
   cards["Barfight"] = 5;
   cards["Treasure"] = 6;
   cards["Merchant"] = 7;
   std::string line;
   int countNumOfCards=0;
   while(getline(source,line)){
      countNumOfCards++;
      if(!cards.count(line)){
         throw DeckFileFormatError(countNumOfCards);
      }
      switch(cards[line]){
         case 0:
            m_cards.push(std::unique_ptr<Fairy>(new Fairy()));
            break; 
         case 1:   
            m_cards.push(std::unique_ptr<Dragon>(new Dragon()));
            break; 
         case 2:
            m_cards.push(std::unique_ptr<Vampire>(new Vampire()));
            break; 
         case 3:
            m_cards.push(std::unique_ptr<Goblin>(new Goblin()));
            break; 
         case 4:
            m_cards.push(std::unique_ptr<Pitfall>(new Pitfall()));
            break; 
         case 5:
            m_cards.push(std::unique_ptr<Barfight>(new Barfight()));
            break; 
         case 6:
            m_cards.push(std::unique_ptr<Treasure>(new Treasure()));
            break; 
         case 7:
            m_cards.push(std::unique_ptr<Merchant>(new Merchant()));
            break; 
         default:
            throw DeckFileFormatError(countNumOfCards);
            //catch in main and break;*/
         }
      }
      if (countNumOfCards<MINIMUM_NUMBER_OF_CARDS){
         throw DeckFileInvalidSize();
      }
      m_playersNumber=handle_players_number();
      handle_players_details(m_players,m_playersNumber);
      for(int i=0;i<m_playersNumber;i++){
         m_ranking[i]=i;
      }
   }
   
static bool is_playing(const Player& player){
   return ((player.getLevel() < MAX_LEVEL) && (!player.isKnockedOut()));
}

static void swap(int ranking[],int src,int dest){
  int temp=ranking[src];
  ranking[src]=ranking[dest];
  ranking[dest]=temp; 
}


static int getindex(int ranking[],int index,int playersNum){
   for(int i=0;i<playersNum;i++){
      if(ranking[i]==index){
         return i;
      }
   }
   return 0;//won't get here
}

static void rearrange_the_players(std::unique_ptr<Player> players[],int ranking[],int index,int playersNum)
{
   if(is_playing(*(players[index]))){
      return; // the player is still playing
   }
   int direction;
   if((*(players[index])).getLevel()==MAX_LEVEL){
      direction =MOVE_LEFT;
   }
   else{
      assert((*(players[index])).isKnockedOut());
      direction =MOVE_RIGHT;
   }
   int i=getindex(ranking,index,playersNum);
   while((i+direction)>=0 && (i+direction)<playersNum){
      if(is_playing(*(players[ranking[i+direction]]))){
         swap(ranking,i,i+direction);
         i=getindex(ranking,index,playersNum);
      }
      else {
         break;
      }
   }
   return;
}


void Mtmchkin:: playRound(){
   m_roundsNumber++;
   printRoundStartMessage( m_roundsNumber);
   for(int i = 0 ; i < m_playersNumber ; i++)
     {
      if(is_playing(*(m_players[i]))){
         printTurnStartMessage((*(m_players[i])).getName()); 
         (*(m_cards.front())).applyEncounter(*(m_players[i]));
         m_cards.push(std::move(m_cards.front())); // add the first card to the end of the deck
         m_cards.pop(); // remove the first card from the start of the deck
         rearrange_the_players(m_players,m_ranking,i,m_playersNumber);
        }
    }
      if(isGameOver()){
         printGameEndMessage();
      }
}


bool Mtmchkin :: isGameOver() const{
    for (int i = 0; i < m_playersNumber ; i++)
    {
        if(is_playing(*(m_players[i])))
        {
            // there is a player who is still playing 
            // --> the game is not over 
            return false;
        }
    }
    // all the players are not playing 
    // --> the game is over
    return true;
 }

int Mtmchkin::getNumberOfRounds() const{
   return m_roundsNumber;
}

void Mtmchkin::printLeaderBoard() const{
   printLeaderBoardStartMessage();
   for(int i=0;i<m_playersNumber;i++){
      printPlayerLeaderBoard(i+1, *(m_players[m_ranking[i]]));
   }
}

