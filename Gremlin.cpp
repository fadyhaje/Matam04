#include "Gremlin.h"


Gremlin :: Gremlin() : BattleCard(DEFAULT_FORCE_Gremlin,DEAFULT_LOOT_Gremlin,DEFAULT_DAMAGE_Gremlin){
    
}

void Gremlin :: applyEncounter(Player& player) const {
    if(m_force > player.getAttackStrength() ){
       // loser
       player.damage(m_damage);
       printLossBattle(player.getName(),"Gremlin");
    }
    else {
        //winner
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), "Gremlin");
    }

}

Card* Gremlin::clone() const { 
    return new Gremlin(*this);  
}


void Gremlin::printInfo(std::ostream& os ) const{
    printCardDetails(os, "Gremlin");
    printMonsterDetails(os,m_force,m_damage,m_loot);
}
