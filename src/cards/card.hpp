#pragma once

namespace blackjack
{

enum class Rank
{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};


struct Card
{
    Rank rank;

    int value() const
    {
        int r = static_cast<int>(rank);

        if (r >= 10 && r <= 13)
            return 10;

        if (r == 14)
            return 11;

        return r;
    }
};

}