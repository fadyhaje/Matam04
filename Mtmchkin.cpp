#include "Mtmchkin.h"

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
using std:string;
using std::ifstream;



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
		cin >> get_num;
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
    for (int i = 0; i < name.size(); ++i) {
        if(!(name[i]<='z'||name[i]>='a')||!(name[i]<='Z'&&name[i]>='A')&&name[i]==' ')
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
			valid_class = check_players_class(current_job,current_name,players,i);
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
	m_roundsNumber=0,countNumOfCards=0
	ifstream source(fileName);
	if (!source) {
		throw DeckFileNotFound();
	}
	std::string cardName;
	while(getline(source,cardName)){	
            if (cardName == "Gremlin") {
                m_cards.push(std::unique_ptr<Goblin>(new Gremlin()));
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
	m_playersNumber=check_players_amount();
	handle_players_everthing(m_players,m_playersNumber);
	for(int i=0;i<m_playersNumber;i++){
		m_sorted[i]=i;
	}
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
	std::unique_ptr<Player> current_player;
	printLeaderBoardStartMessage();
	while(i<m_playersNumber)
	{
		current_player=m_players[m_sorted[i-1]];
		printPlayerLeaderBoard(i, *current_player);
		i++;
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


int Mtmchkin ::getNumerOfRounds() const
{
	return m_roundsNumber;
}


