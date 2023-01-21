#include "Merchant.h"


Merchant :: Merchant (){
  m_hp = DEFAULT_HP_FOR_MERCHANT;
  m_force = DEFAULT_FORCE_FOR_MERCHANT;
}
void Merchant ::printInfo(std::ostream& os) const
{
  printCardDetails(os,"Merchant");
  printEndOfCardDetails(os);
}

void Merchant ::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    bool available = false;
    int temp_input;
    while(available==false)
    {
      std::getline( std::cin,number );
      std::string number;
      try
      {
        temp_input = std::stoi(number);
      }
      catch(...)
      {
        printInvalidInput();
        continue;
      }
      if(temp_input==0 || temp_input==1 || temp_input==2)
      {
        available = true;
      }
      else
      {
        printInvalidInput();
      }
    }
  switch(temp_input){
    case 2:
        if(player.getCoins()<FORCE_PRICE_MERCHANT)
        {
          printMerchantInsufficientCoins(std::cout);
          printMerchantSummary(std::cout,player.getName(),2,0);
          return;
        }
        else
        {
          player.pay(FORCE_PRICE_MERCHANT);
          player.buff(m_force); 
        }
        break;
    case 1:
       if(player.getCoins()<HP_PRICE_MERCHANT)
       {
         printMerchantInsufficientCoins(std::cout);
         printMerchantSummary(std::cout,player.getName(),1,0);
         return;
      }
      else
      {
        player.pay(HP_PRICE_MERCHANT);
        player.heal(m_hp);
      }
      break;
  }
  printMerchantSummary(std::cout,player.getName(),input,input*5);
}

Card* Merchant ::clone() const
{ 
  return new Merchant(*this); 
}

