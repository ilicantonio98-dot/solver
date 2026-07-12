#pragma once

#include <map>


namespace blackjack
{


enum class DealerResult
{
    BUST,

    TOTAL17,
    TOTAL18,
    TOTAL19,
    TOTAL20,
    TOTAL21
};



using DealerDistribution =
    std::map<DealerResult,double>;



inline DealerResult resultFromTotal(int value)
{

    switch(value)
    {

        case 17:
            return DealerResult::TOTAL17;

        case 18:
            return DealerResult::TOTAL18;

        case 19:
            return DealerResult::TOTAL19;

        case 20:
            return DealerResult::TOTAL20;

        case 21:
            return DealerResult::TOTAL21;

        default:
            return DealerResult::BUST;

    }

}


}