#pragma once

#include <array>
#include <functional>


namespace blackjack
{


struct StateKey
{

    int total;
    bool soft;
    int cards;

    std::array<int,13> shoe;


    bool operator==(const StateKey& other) const
    {
        return total == other.total &&
               soft == other.soft &&
               cards == other.cards &&
               shoe == other.shoe;
    }

};



struct StateHash
{

    std::size_t operator()(const StateKey& s) const
    {

        size_t h =
            std::hash<int>{}(s.total);


        h ^=
            std::hash<bool>{}(s.soft)
            +
            (h << 1);


        h ^=
            std::hash<int>{}(s.cards)
            +
            (h << 2);



        for(auto c : s.shoe)
        {

            h ^=
                std::hash<int>{}(c)
                +
                0x9e3779b9
                +
                (h << 6)
                +
                (h >> 2);

        }


        return h;
    }

};


}