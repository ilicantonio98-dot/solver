#pragma once

#include "dealer_result.hpp"
#include "state.hpp"

#include "../cards/hand.hpp"
#include "../cards/shoe.hpp"
#include "../rules/rules.hpp"

#include <unordered_map>


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


    std::unordered_map<
        StateKey,
        DealerDistribution,
        StateHash
    > cache;



    DealerDistribution recurse(
        Hand hand,
        Shoe shoe
    );


};


}