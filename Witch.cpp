#include "Witch.h"


Witch :: Witch() :BattleCard(DEFAULT_FORCE_Witch,DEFAULT_LOOT_Witch,DEFAULT_DAMAGE_Witch)
{
}


void Witch :: applyEncounter(Player& player) const{
    if(m_force <= player.getAttackStrength())
    {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(),"Witch");
        return;
    }
    player.damage(m_damage);
    player.force_damage();
    printLossBattle(player.getName(),"Witch");
}

void Witch::printInfo(std::ostream& os ) const{
    check_players_everthing(os,"Witch");
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);

}

Card* Witch::clone() const
{
    return new Witch(*this);
}
