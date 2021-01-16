#ifndef _DEALER_H
#define _DEALER_H

#include <card/Deck.h>
#include "card/HoleCards.h"
#include "card/CommunityCards.h"
#include "card/CardCollection.h"
#include "card/Card.h"
#include "players/Player.h"
#include "Players.h"

namespace game {
    class Dealer {
    private:
        Deck deck;
    public:
        Dealer(Dealer &dealer);

        Dealer();

        Deck getDeck();

        void shuffle();

        int deckSize();

        void dealHoleCards(Players &players);

        cards::Card dealCard();

        cards::CardCollection dealFlop();

        cards::Card dealTurn();

        cards::Card dealRiver();

        void resetDeck();
    };
}
#endif //_DEALER_H