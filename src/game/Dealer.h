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

        void shuffle();

        int deckSize();

        void dealHoleCards(Players &players);

        cards::Card dealCard();

        cards::CardCollection dealFlop();

        cards::Card dealTurn();

        cards::Card dealRiver();

        void presentOptions(Player &player);
    };
}
#endif //_DEALER_H