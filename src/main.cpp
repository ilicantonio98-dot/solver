#include <iostream>

#include "cards/shoe.hpp"


using namespace blackjack;


int main()
{

    Shoe shoe(6);


    std::cout
        << "Cards: "
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


}