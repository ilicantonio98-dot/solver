#pragma once

#include "card.hpp"
#include <array>


namespace blackjack
{


class Shoe
{

private:

    // index:
    // 0 = TWO
    // 1 = THREE
    // ...
    // 8 = TEN
    // 9 = JACK
    // 10 = QUEEN
    // 11 = KING
    // 12 = ACE

    std::array<int,13> counts;


public:


    Shoe(int decks = 6)
    {
        reset(decks);
    }



    void reset(int decks = 6)
    {

        counts.fill(0);


        // 2-9
        for(int i = 0; i < 8; i++)
        {
            counts[i] = 4 * decks;
        }


        // 10,J,Q,K
        counts[8]  = 4 * decks;
        counts[9]  = 4 * decks;
        counts[10] = 4 * decks;
        counts[11] = 4 * decks;


        // Ace
        counts[12] = 4 * decks;

    }




    int remaining() const
    {
        int total = 0;

        for(int c : counts)
            total += c;

        return total;
    }




    int remaining(Rank rank) const
    {
        return counts[index(rank)];
    }




    void remove(Rank rank)
    {
        counts[index(rank)]--;
    }




    void add(Rank rank)
    {
        counts[index(rank)]++;
    }




    bool canDraw(Rank rank) const
    {
        return counts[index(rank)] > 0;
    }




    Card draw()
    {

        for(int i = 0; i < 13; i++)
        {

            if(counts[i] > 0)
            {

                counts[i]--;


                return Card{
                    rankFromIndex(i)
                };

            }

        }


        return Card{
            Rank::TWO
        };

    }




    std::array<int,13> state() const
    {
        return counts;
    }




    static int index(Rank rank)
    {
        return static_cast<int>(rank) - 2;
    }




    static Rank rankFromIndex(int i)
    {
        return static_cast<Rank>(i + 2);
    }


};


}