#include <iostream>

#include "cards/shoe.hpp"
#include "cards/hand.hpp"
#include "engine/ev.hpp"
#include "rules/rules.hpp"


using namespace blackjack;



int main()
{

    Rules rules;


    Shoe shoe(
        rules.decks
    );


    Hand player;
    Hand dealer;


    player.add(
        shoe.draw()
    );

    player.add(
        shoe.draw()
    );


    dealer.add(
        shoe.draw()
    );

    dealer.add(
        shoe.draw()
    );



    EVEngine engine(rules);


    double ev =
        engine.standEV(
            player,
            dealer,
            shoe
        );


    std::cout
        << "Stand EV: "
        << ev
        << "\n";


}