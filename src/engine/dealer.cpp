#include "dealer.hpp"


namespace blackjack
{


Dealer::Dealer(const Rules& r)
    : rules(r)
{
}



Hand Dealer::play(
    Hand dealerHand,
    Shoe& shoe
)
{

    while(true)
    {

        int value = dealerHand.value();


        // Dealer mora stati na 17+
        if(value >= 17)
        {

            // S17:
            // ako je soft 17 također stoji

            return dealerHand;
        }




    }

}


}
