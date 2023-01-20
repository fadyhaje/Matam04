#include "Barfight.h"
#include "../Players/Player.h"
#include "../Players/Warrior.h"
#include "../utilities.h"

Barfight :: Barfight(): m_damage( DEFAULT_DAMAGE_BARFIGHT)
{
} 




void Barfight ::applyEncounter(Player& player) const{
    const Warrior* warrior = dynamic_cast<const Warrior*>(&player);
    if (warrior!=nullptr)
    {
        printBarfightMessage(true);
    }
    else
    {
        player.damage(m_damage);
        printBarfightMessage(false);
    }
}

void Barfight::printInfo(std::ostream& os) const
{
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}

Card* Barfight::clone() const
{ 
    return new Barfight(*this);  
}
