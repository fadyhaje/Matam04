#include "Merchant.h"


Merchant :: Merchant (){
  m_hp = DEFAULT_HP_MERCHANT;
  m_force = DEFAULT_FORCE_MERCHANT;
}

void Merchant :: applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int input;
    bool valid = false;
    while(!valid)
    {
      std::string number;
      std::getline( std::cin,number );
      try{
        input = std::stoi(number);
      }
      catch(...){
        printInvalidInput();
        continue;
      }
        if(input !=0 && input!=1 && input!= 2 ){
          printInvalidInput();
        }
        else{
          valid = true;
        }
    }
    if(input == 1){
      if(player.getCoins()>=HP_PRICE_MERCHANT){
        // paying for hp 
        player.pay(HP_PRICE_MERCHANT);
        player.heal(m_hp);
      }
      else{
        // the player does not have enough money
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(),1,0);
        return;
      }
    }
    else if (input == 2){
        if(player.getCoins()>=FORCE_PRICE_MERCHANT){
          // paying for force 
          player.pay(FORCE_PRICE_MERCHANT);
          player.buff(m_force); 
        }
        else{
          // the player does not have enough money
          printMerchantInsufficientCoins(std::cout);
          printMerchantSummary(std::cout,player.getName(),2,0);
          return;
        }
    }
    printMerchantSummary(std::cout,player.getName(),input,input*5);
}

void Merchant::printInfo(std::ostream& os ) const{
  printCardDetails(os, "Merchant");
  printEndOfCardDetails(os);
}

Card* Merchant::clone() const
{ 
  return new Merchant(*this); 
}

