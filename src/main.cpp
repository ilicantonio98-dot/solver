#include <iostream>

#include "cards/shoe.hpp"
#include "cards/hand.hpp"
#include "engine/dealer_solver.hpp"
#include "rules/rules.hpp"


using namespace blackjack;


int main()
{

    Rules rules;


    Shoe shoe(
        rules.decks
    );
    std::cout 
        << "Cards in shoe: "
        << shoe.remaining()
        << "\n";

    std::cout
        << "Tens: "
        << shoe.remaining(Rank::TEN)
        << "\n";

    std::cout
        << "Aces: "
        << shoe.remaining(Rank::ACE)
        << "\n";

   Hand dealer;


    dealer.add(
        Card{Rank::SIX}
    );


    shoe.remove(
        Rank::SIX
    );



    DealerSolver solver(
        rules
    );


    auto result =
        solver.solve(
            dealer,
            shoe
        );




    std::cout
        << "Dealer distribution\n";


    for(auto& item : result)
    {

        switch(item.first)
{
    case DealerResult::BUST:
        std::cout << "Bust";
        break;

    case DealerResult::TOTAL17:
        std::cout << "17";
        break;

    case DealerResult::TOTAL18:
        std::cout << "18";
        break;

    case DealerResult::TOTAL19:
        std::cout << "19";
        break;

    case DealerResult::TOTAL20:
        std::cout << "20";
        break;

    case DealerResult::TOTAL21:
        std::cout << "21";
        break;
}

std::cout
    << " : "
    << item.second
    << "\n";

    }



    return 0;

}