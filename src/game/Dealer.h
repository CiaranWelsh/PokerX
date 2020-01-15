#ifndef _DEALER_H
#define _DEALER_H

#include <cards/Deck.h>
#include "cards/HoleCards.h"
#include "cards/CommunityCards.h"
#include "cards/CardCollection.h"
#include "cards/Card.h"
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

    };
}
#endif //_DEALER_H