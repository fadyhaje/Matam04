#include "Barfight.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include "../utilities.h"

Barfight :: Barfight(): m_damage( DEFAULT_DAMAGE_BARFIGHT) {} 



Card* Barfight::clone() const { 
    return new Barfight(*this);  
}


void Barfight :: applyEncounter(Player& player) const{
    const Fighter* fighter = dynamic_cast<const Fighter*>(&player);
    if (fighter == nullptr) {
        player.damage(m_damage);
        printBarfightMessage(false);
    }
    else{
        printBarfightMessage(true);
    }
}

void Barfight::printInfo(std::ostream& os ) const{
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}
