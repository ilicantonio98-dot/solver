#include "ev.hpp"
#include "dealer.hpp"


namespace blackjack
{


EVEngine::EVEngine(
    const Rules& r
)
:
rules(r)
{
}



double EVEngine::standEV(
    const Hand& player,
    const Hand& dealer,
    Shoe shoe
)
{

    Dealer dealerEngine(rules);


    int wins = 0;
    int losses = 0;
    int pushes = 0;


    int simulations = 0;



    while(shoe.remaining() > 0)
    {

        Shoe copy = shoe;


        Hand finalDealer =
            dealerEngine.play(
                dealer,
                copy
            );


        int p =
            player.value();


        int d =
            finalDealer.value();



        double result;



        if(finalDealer.bust())
        {
            result = 1.0;
        }
        else if(p > d)
        {
            result = 1.0;
        }
        else if(p < d)
        {
            result = -1.0;
        }
        else
        {
            result = 0.0;
        }



        wins += result > 0;
        losses += result < 0;
        pushes += result == 0;


        simulations++;

    }



    if(simulations == 0)
        return 0;


    return 
        (
            wins -
            losses
        )
        /
        (double)simulations;


}


}