#include <iostream>

#include "cards/shoe.hpp"
#include "cards/hand.hpp"


using namespace blackjack;



int main()
{

    Shoe shoe(6);


    Hand hand;


    hand.add(shoe.draw());
    hand.add(shoe.draw());


    std::cout 
        << "Hand value: "
        << hand.value()
        << "\n";


    std::cout
        << "Cards: "
        << hand.size()
        << "\n";


    std::cout
        << "Soft: "
        << hand.soft()
        << "\n";


    std::cout
        << "Bust: "
        << hand.bust()
        << "\n";


    std::cout
        << "Blackjack: "
        << hand.blackjack()
        << "\n";


    return 0;
}