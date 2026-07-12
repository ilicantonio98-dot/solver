#include <iostream>

#include "rules/rules.hpp"


using namespace blackjack;


int main()
{

    Rules rules;


    std::cout
        << "Decks: "
        << rules.decks
        << "\n";


    std::cout
        << "Dealer hole card: "
        << rules.dealerHasHoleCard
        << "\n";


    std::cout
        << "Charlie payout: "
        << rules.sixCardCharliePayout
        << "\n";


    std::cout
        << "777 payout: "
        << rules.threeSevenPayout
        << "\n";


    return 0;
}