#include "Dragon.h"


Dragon ::Dragon():BattleCard(DEFAULT_FORCE_FOR_DRAGON,DEAFULT_LOOT_FOR_DRAGON,DEFAULT_DAMAGE_FOR_DRAGON)
{
}

void Dragon :: applyEncounter(Player& player) const {
    if(m_force<=player.getAttackStrength())
    {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(),"Dragon");
        return;
    }
    player.damage(m_damage);
    printLossBattle(player.getName(),"Dragon");
}

void Dragon::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Dragon");
    printMonsterDetails(os,m_force,m_damage,m_loot,true);
    printEndOfCardDetails(os);
}

Card* Dragon::clone() const
{
    return new Dragon(*this);
}
