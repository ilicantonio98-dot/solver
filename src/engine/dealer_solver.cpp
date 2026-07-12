#include "dealer_solver.hpp"
#include <iostream>


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

    cache.clear();


    return recurse(
        dealer,
        shoe
    );

}




DealerDistribution DealerSolver::recurse(
    Hand hand,
    Shoe shoe
)
{

    StateKey key;

    key.total = hand.value();
    key.soft = hand.soft();
    key.cards = hand.size();
    key.shoe = shoe.state();



    auto found =
        cache.find(key);



    if(found != cache.end())
    {
        return found->second;
    }




    DealerDistribution result;



    int value =
        hand.value();



    if(hand.bust())
    {
        result[DealerResult::BUST] = 1.0;

        cache[key] = result;

        return result;
    }




    // Dealer S17
    if(value >= 17)
    {

        DealerResult r =
            resultFromTotal(value);


        result[r] = 1.0;


        cache[key] = result;


        return result;

    }





    int totalCards =
        shoe.remaining();
    
        static int depth = 0;

    if(depth < 2)
    {
        std::cout 
            << "Depth "
            << depth
            << " cards left "
            << totalCards
            << " hand "
            << hand.value()
            << "\n";
    }



    for(int i = 0; i < 13; i++)
    {
        std::cout 
            << i
            << " count "
            << shoe.remaining(
                Shoe::rankFromIndex(i)
            )
            << "\n";

        Rank rank =
            Shoe::rankFromIndex(i);



        int amount =
            shoe.remaining(rank);



        if(amount == 0)
            continue;



        double probability =
            (double)amount /
            totalCards;



        Shoe next =
            shoe;


        next.remove(rank);



        Hand nextHand =
            hand;


        nextHand.add(
            Card{rank}
        );

        std::cout
            << i
            << " new hand "
            << nextHand.value()
            << "\n";  


        auto child =
            recurse(
                nextHand,
                next
            );



        for(auto& item : child)
        {
            result[item.first] +=
                probability *
                item.second;
        }

    }



    cache[key] = result;


    return result;

}



}