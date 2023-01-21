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
//handle_players_name
bool isValidPlayerName(string& playerName){
     if(playerName.size()>15|| !islegalchars(playerName))
     {
         printInvalidName();
         return false;
     }
     return true;
 }


#include "Mtmchkin.h"
#include <map>
#include "utilities.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Exception.h" 

#define UPPER 1
#define LOWER -1
#define MAX_NUM_OF_LETTERS 15
#define MAX_LEVEL 10
#define MIN_CARDS_NUM 5

using std::find;
using std::cin;
using std::ifstream;

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
	return 0;
}


/*
static bool handle_players_name(std::string *playerName){	
	if(playerName->length()>MAX_NUM_OF_LETTERS) {
		printInvalidName();
		return false;
	}
	for(std::size_t i=0;i<playerName->length();i++){
		char letter=playerName->at(i);
		if ((letter >= 'A' && letter <= 'Z' ) || ( letter >= 'a' && letter <= 'z' ))
		{
			continue; 
		}  
		else{
			printInvalidName();  
			return false;
		}
	}
	return true;
}*/


static bool handle_players_class(std::string playerClass,std::string name, std::unique_ptr<Player> players[],int place){
	std::map<std::string, int> play;
	play["Ninja"] = 0;
	play["Healer"] = 1;
	play["Warrior"] = 2;
	if(!play.count(playerClass)){
		printInvalidClass();
		return false;
	}
	switch (play[playerClass]){
		case 0:
			players[place]=std::unique_ptr<Rogue>(new Ninja(name));
			break;
		case 1:
			players[place]=std::unique_ptr<Wizard>(new Healer(name));
			break;
		case 2:
			players[place]=std::unique_ptr<Fighter>(new Warrior(name));
			break;
		default:
			printInvalidClass();
			return false;
	}
	return true;
}

static bool islegalchars(string& name)
{
    for (int i = 0; i < name.size(); ++i) {
        if(!(name[i]<='z'||name[i]>='a')||!(name[i]<='Z'&&name[i]>='A')&&name[i]==' ')
            return false;
    }
    return true;
}
//handle_players_name
static bool isValidPlayerName(string& playerName){
     if(playerName.size()>MAX_NUM_OF_LETTERS|| !islegalchars(playerName))
     {
         printInvalidName();
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
				valid_name=isValidPlayerName(current_name);
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
	cards["Mana"] = 0;
	cards["Dragon"] = 1;
	cards["Witch"] = 2;
	cards["Gremlin"] = 3;
	cards["Well"] = 4;
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
				m_cards.push(std::unique_ptr<Fairy>(new Mana()));
				break; 
			case 1:   
				m_cards.push(std::unique_ptr<Dragon>(new Dragon()));
				break; 
			case 2:
				m_cards.push(std::unique_ptr<Vampire>(new Witch()));
				break; 
			case 3:
				m_cards.push(std::unique_ptr<Goblin>(new Gremlin()));
				break; 
			case 4:
				m_cards.push(std::unique_ptr<Pitfall>(new Well()));
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
		}
	}
	if (countNumOfCards< MIN_CARDS_NUM){
		throw DeckFileInvalidSize();
	}
	m_playersNumber=handle_players_number();
	handle_players_details(m_players,m_playersNumber);
	for(int i=0;i<m_playersNumber;i++){
		m_ranking[i]=i;
	}
}
   
/*static bool is_playing(const Player& player)
{
	return ((player.isKnockedOut()==false) &&(player.getLevel()<MAX_LEVEL));
}

static void swap(int ranking[],int src,int dest)
{
	int curren_rank=ranking[src];
	ranking[src]=ranking[dest];
	ranking[dest]=curren_rank; 
}*/


static int get_sorted_index(int sorted[],int number_of_players,int index)
{
	for(int i=0;i<numer_of_players;i++)
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

static void players_new_sort(std::unique_ptr<Player> players[],int sorted[],int number_of_players,int index)
{
	int way;
	if((players[index]->isKnockedOut()==false) &&(players[index]->getLevel()<MAX_LEVEL))
	{
		return; 
	}
	int sorted_index=get_sorted_index(sorted,number_of_players,index)
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
		if(!((players[sorted[i+way]]->isKnockedOut()==false) && (players[sorted[i+way]]->getLevel()<MAX_LEVEL)))
		{
			break;
		}
		curren_rank=sorted[sorted_index];
	        sorted[sorted_index]=sorted[sorted_index+way];
	        sorted[sorted+index]=curren_rank; 
		sorted_index=get_sorted_index(sorted,number_of_players,index);
		temp_index=sorted_index+way;
		flag=temp_index<number_of_players && temp_index>=0;
	}
	return;
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
			std::unique_ptr<Card> firstCard= m_cards.front();
			printTurnStartMessage(std::string(*m_players[i]).getName())); 
			firstCard->applyEncounter(*m_players[i]);
			m_cards.push(first_card); 
			m_cards.pop();
			players_new_sort(m_players,m_ranking,m_playersNumber,i);
			i++;
		}
	}
	game_final=isGameOver();
	if(game_final)
	{
		printGameEndMessage();
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
	printGameEndMessage();
	return true;
}

void Mtmchkin::printLeaderBoard() const
{
	int i=1;
	std::unique_ptr<Player> current_player;
	printLeaderBoardStartMessage();
	while(i<m_playersNumber)
	{
		current_player=m_players[m_sorted[i-1]];
		printPlayerLeaderBoard(i, *current_player);
		i++;
	}
}

int Mtmchkin ::getNumerOfRounds() const
{
	return m_roundsNumber;
}


