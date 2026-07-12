#pragma once

#include <map>


namespace blackjack
{


enum class DealerResult
{
    BUST = 0,
    TOTAL17 = 17,
    TOTAL18 = 18,
    TOTAL19 = 19,
    TOTAL20 = 20,
    TOTAL21 = 21
};



using DealerDistribution =
    std::map<DealerResult,double>;


}