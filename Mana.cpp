#include "Mana.h"


Mana :: Mana()
{
    m_heal=DEFAULT_HEAL_MANA;
}

void Mana :: applyEncounter(Player& player) const
{
    const  Healer* healer = dynamic_cast<const  Healer*>(&player);
    if (healer !=nullptr) {
        player.heal(m_heal);
        printManaMessage(true);
        return;
    }
    printManaMessage(false);
}

void Mana::printInfo(std::ostream& os ) const
{
    printCardDetails(os,"Mana");
    printEndOfCardDetails(os);
}

Card* Mana::clone() const
{
    return new Mana(*this);
}
