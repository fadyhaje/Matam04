#include "Merchant.h"


Merchant ::Merchant ()
{
    m_force = DEFAULT_FORCE_FOR_MERCHANT;
    m_hp = DEFAULT_HP;
}

void Merchant::checker_1(Player& player) const{
    if(player.getCoins()<HP_PRICE)
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(),1,0);
        return;
    }
    else
    {
        player.pay(HP_PRICE);
        player.heal(m_hp);
    }
}

void Merchant ::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Merchant");
    printEndOfCardDetails(os);
}

 void Merchant::checker_2(Player& player) const{
    if(player.getCoins()<FORCE_PRICE)
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(),2,0);
        return;
    }
    else
    {
        player.pay(FORCE_PRICE);
        player.buff(m_force);
    }
}

Card* Merchant ::clone() const
{
    return new Merchant(*this);
}

void Merchant ::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    bool available = false;
    int temp_input;
    while(available==false)
    {
        std::string number;
        std::getline( std::cin,number);
        try
        {
            temp_input = std::stoi(number);
        }
        catch(...)
        {
            printInvalidInput();
            continue;
        }
        if(temp_input>=0 && temp_input<=2)
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
           checker_2(player);
            break;
        case 1:
            checker_1(player);
            break;
    }
    printMerchantSummary(std::cout,player.getName(),temp_input,temp_input*5);
}

