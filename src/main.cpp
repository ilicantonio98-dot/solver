#include <iostream>

#include "cards/shoe.hpp"


using namespace blackjack;


int main()
{
    Shoe shoe(6);


    std::cout 
        << "Cards remaining: "
        << shoe.remaining()
        << "\n";


    Card c = shoe.draw();


    std::cout
        << "Drawn value: "
        << c.value()
        << "\n";


    std::cout
        << "Cards remaining: "
        << shoe.remaining()
        << "\n";


    return 0;
}