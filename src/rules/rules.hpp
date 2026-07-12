#pragma once


namespace blackjack
{


struct Rules
{

    // Shoe
    int decks = 6;


    // Dealer
    bool dealerHitsSoft17 = false;
    bool dealerHasHoleCard = false;


    // Player actions
    bool doubleAnyTwoCards = true;
    bool doubleAfterSplit = true;


    // Split
    int maxSplitHands = 4;
    bool splitAcesOneCardOnly = true;


    // Surrender
    bool surrenderAllowed = true;
    bool surrenderAgainstAce = false;


    // Special wins

    double blackjackPayout = 1.5;

    double sixCardCharliePayout = 2.0;

    double threeSevenPayout = 1.5;


};


}