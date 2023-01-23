#include "Barfight.h"
#include "../utilities.h"
#include "../Players/Warrior.h"
#include "../Players/Player.h"



Barfight ::Barfight():m_damage(DEFAULT_DAMAGE_FOR_BARFIGHT)
{
}

void Barfight ::applyEncounter(Player& player) const
{
    const Warrior* warrior = dynamic_cast<const Warrior*>(&player);
    if (warrior!=nullptr)
    {
        printBarfightMessage(true);
        return;
    }
    player.damage(m_damage);
    printBarfightMessage(false);
}

void Barfight::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Barfight");
    printEndOfCardDetails(os);
}

Card* Barfight::clone() const
{
    return new Barfight(*this);
}
