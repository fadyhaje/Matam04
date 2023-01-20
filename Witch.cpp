#include "Witch.h"


Witch :: Witch() :BattleCard(DEFAULT_FORCE_Witch,DEFAULT_LOOT_Witch,DEFAULT_DAMAGE_Wicth)
{
    
}


void Wictch :: applyEncounter(Player& player) const{
    if(m_force <= player.getAttackStrength())
    {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(),"Wicth");
    }
    else
    {
       player.damage(m_damage);
       player.damageForce();
       printLossBattle(player.getName(),"Wicth");
        
    }
}

void Wicth::printInfo(std::ostream& os ) const{
    printCardDetails(os,"Wicth");
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);

}

Card* Wicth::clone() const
{ 
    Witch temp=new Witch(*this);
    return temp;
}
