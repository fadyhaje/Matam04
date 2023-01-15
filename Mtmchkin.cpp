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
        ///////////////not completed
        if(  isValidPlayerName(tempName))
        {
            addPlayer(m_players, tempName, tempType);
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
