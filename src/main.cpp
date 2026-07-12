#include <iostream>

#include "cards/shoe.hpp"
#include "cards/hand.hpp"
#include "engine/dealer.hpp"
#include "rules/rules.hpp"


using namespace blackjack;


int main()
{

    Rules rules;

    Shoe shoe(
        rules.decks
    );


    Hand dealer;

    dealer.add(
        shoe.draw()
    );

    dealer.add(
        shoe.draw()
    );


    Dealer dealerEngine(rules);


    Hand result =
        dealerEngine.play(
            dealer,
            shoe
        );


    std::cout
        << "Dealer final value: "
        << result.value()
        << "\n";


    std::cout
        << "Dealer cards: "
        << result.size()
        << "\n";


    return 0;
}