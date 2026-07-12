#pragma once

#include "../cards/hand.hpp"
#include "../cards/shoe.hpp"
#include "../rules/rules.hpp"


namespace blackjack
{


class EVEngine
{

public:

    EVEngine(const Rules& rules);


    double standEV(
        const Hand& player,
        const Hand& dealer,
        Shoe shoe
    );


private:

    Rules rules;


};


}