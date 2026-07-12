#include "dealer_solver.hpp"


namespace blackjack
{


DealerSolver::DealerSolver(
    const Rules& r
)
:
rules(r)
{
}



DealerDistribution DealerSolver::solve(
    const Hand& dealer,
    const Shoe& shoe
)
{

    DealerDistribution result;


    recurse(
        dealer,
        shoe,
        result
    );


    return result;

}




void DealerSolver::recurse(
    Hand hand,
    Shoe shoe,
    DealerDistribution& result
)
{

    int value =
        hand.value();



    if(hand.bust())
    {
        result[DealerResult::BUST] += 1.0;
        return;
    }



    bool stop = false;


    if(value > 17)
        stop = true;



    if(value == 17)
    {
        // S17
        stop = true;
    }



    if(stop)
    {

        DealerResult r =
            static_cast<DealerResult>(
                value
            );


        result[r] += 1.0;

        return;

    }



    int remaining =
        shoe.remaining();



    for(int i = 0; i < remaining; i++)
    {

        Shoe next =
            shoe;


        Card c =
            next.draw();



        Hand nextHand =
            hand;


        nextHand.add(c);



        recurse(
            nextHand,
            next,
            result
        );

    }

}



}