#include "Treasure.h"

Treasure :: Treasure() : m_loot(DEFAULT_COINS_TREASURE){
}


void Treasure :: applyEncounter (Player& player) const{
   player.addCoins(m_loot);
   printTreasureMessage();
}

Card* Treasure::clone() const { 
   return new Treasure(*this);
}

void Treasure::printInfo(std::ostream& os ) const{
   printCardDetails(os, "Treasure");
   printEndOfCardDetails(os);
}

