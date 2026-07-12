#pragma once

#include "../cards/hand.hpp"
#include "../cards/shoe.hpp"
#include "../rules/rules.hpp"


namespace blackjack
{


class Dealer
{

public:

    Dealer(const Rules& rules);


    Hand play(
        Hand dealerHand,
        Shoe& shoe
    );


private:

    Rules rules;


};


}