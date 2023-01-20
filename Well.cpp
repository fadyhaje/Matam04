#include "Well.h"

Well :: Well()
{
    m_damage = DEFAULT_DAMAGE_Well;  
}


void Well :: applyEncounter(Player& player)const 
{
    const Ninja* ninja = dynamic_cast<const Ninja*>(&player);
    if(ninja !=nullptr){
        printWellMessage(true);
    }
    else{
        player.damage(m_damage);
        printWellMessage(false);
    }
}

void Well::printInfo(std::ostream& os ) const
{
    printCardDetails(os,"Well");
    printEndOfCardDetails(os);
}

Card* Well::clone() const
{ 
    Well temp=new Well(*this);
    return Well;  
}

