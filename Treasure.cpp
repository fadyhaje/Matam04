#include "Treasure.h"

Treasure :: Treasure():m_loot(DEFAULT_COINS_TREASURE)
{
}

void Treasure :: applyEncounter (Player& player) const
{
   player.addCoins(m_loot);
   printTreasureMessage();
}

void Treasure::printInfo(std::ostream& os) const
{
   printCardDetails(os,"Treasure");
   printEndOfCardDetails(os);
}

Card* Treasure::clone() const 
{ 
   Treasure temp=new Treasure(*this);
   return temp;
}

