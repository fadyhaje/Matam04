#include "Mana.h"


Mana :: Mana(){
    m_heal = DEFAULT_HEAL_MANA;  
}

Card* Mana::clone() const { 
    return new Mana(*this);  
}

void Mana :: applyEncounter(Player& player) const{
    const  Healer* healer = dynamic_cast<const  Healer*>(&player);
    if (healer !=nullptr) {
        player.heal(m_heal);
        printManaMessage(true);
    }
    else{
       printManaMessage(false);
    }
}

void Mana::printInfo(std::ostream& os ) const{
   printCardDetails(os, "Mana");
   printEndOfCardDetails(os);
}

