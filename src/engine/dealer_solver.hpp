#pragma once

#include "dealer_result.hpp"
#include "../cards/hand.hpp"
#include "../cards/shoe.hpp"
#include "../rules/rules.hpp"


namespace blackjack
{


class DealerSolver
{

public:

    DealerSolver(
        const Rules& rules
    );


    DealerDistribution solve(
        const Hand& dealer,
        const Shoe& shoe
    );


private:

    Rules rules;


    void recurse(
        Hand hand,
        Shoe shoe,
        DealerDistribution& result
    );


};


}