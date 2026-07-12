# Custom Blackjack EV Solver

Exact EV solver for custom blackjack rules.

Rules:
- 6 decks
- ENHC (dealer no hole card)
- Dealer stands on soft 17
- Double any two cards
- Double after split allowed
- Resplit up to 4 hands
- Split aces receive one card only
- Late surrender except vs Ace
- Blackjack pays 3:2
- Any three sevens pays 3:2
- Six card Charlie pays 2:1
- Charlie and 777 apply after splits

Goal:
Generate mathematically optimal strategy tables.