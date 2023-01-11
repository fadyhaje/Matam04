

Well :: Well(){
    m_damage = DEFAULT_DAMAGE_Well;  
}


void Well :: applyEncounter(Player& player)const {
    const Rogue* rogue = dynamic_cast<const Rogue*>(&player);
    if (rogue == nullptr) {
        player.damage(m_damage);
        printWellMessage(false);
    }
    else{
        printWellMessage(true);
    }
}

Card* Well::clone() const { 
    return new Well(*this);  
}

void Well::printInfo(std::ostream& os ) const{
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
}

