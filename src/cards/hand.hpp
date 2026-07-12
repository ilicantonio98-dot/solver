#pragma once

#include "card.hpp"
#include <vector>


namespace blackjack
{


class Hand
{

private:

    std::vector<Card> cards;


public:


    void add(Card c)
    {
        cards.push_back(c);
    }


    const std::vector<Card>& getCards() const
    {
        return cards;
    }


    int size() const
    {
        return static_cast<int>(cards.size());
    }



    int value() const
    {
        int total = 0;
        int aces = 0;


        for(const auto& c : cards)
        {
            total += c.value();

            if(c.rank == Rank::ACE)
                aces++;
        }


        while(total > 21 && aces > 0)
        {
            total -= 10;
            aces--;
        }


        return total;
    }




    bool soft() const
    {
        int total = 0;
        int aces = 0;


        for(const auto& c : cards)
        {
            total += c.value();

            if(c.rank == Rank::ACE)
                aces++;
        }


        while(total > 21 && aces > 0)
        {
            total -= 10;
            aces--;
        }


        return aces > 0;
    }




    bool bust() const
    {
        return value() > 21;
    }




    bool blackjack() const
    {
        return cards.size() == 2 &&
               value() == 21;
    }




    bool sixCardCharlie() const
    {
        return cards.size() >= 6 &&
               !bust();
    }




    bool threeSevens() const
    {
        if(cards.size() != 3)
            return false;


        for(const auto& c : cards)
        {
            if(c.rank != Rank::SEVEN)
                return false;
        }


        return true;
    }


};


}