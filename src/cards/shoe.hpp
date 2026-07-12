#pragma once

#include "card.hpp"
#include <vector>
#include <random>
#include <algorithm>

namespace blackjack
{

class Shoe
{
private:

    std::vector<Card> cards;


public:

    Shoe(int decks = 6)
    {
        reset(decks);
    }


    void reset(int decks = 6)
    {
        cards.clear();

        for(int d = 0; d < decks; d++)
        {
            for(int r = 2; r <= 14; r++)
            {
                Rank rank = static_cast<Rank>(r);

                int amount = 1;

                if(r >= 10 && r <= 13)
                    amount = 4;

                for(int i = 0; i < amount; i++)
                    cards.push_back({rank});
            }
        }

        shuffle();
    }


    void shuffle()
    {
        static std::mt19937 rng(
            std::random_device{}()
        );

        std::shuffle(
            cards.begin(),
            cards.end(),
            rng
        );
    }


    Card draw()
    {
        Card c = cards.back();
        cards.pop_back();

        return c;
    }


    size_t remaining() const
    {
        return cards.size();
    }

};

}