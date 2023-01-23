#include "Treasure.h"

Treasure ::Treasure():m_loot(DEFAULT_COINS_FOR_TREASURE)
{
}

Card* Treasure::clone() const
{
    return new Treasure(*this);
}


void Treasure ::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Treasure");
    printEndOfCardDetails(os);
}
void Treasure ::applyEncounter(Player& player) const
{
    player.addCoins(m_loot);
    printTreasureMessage();
}
