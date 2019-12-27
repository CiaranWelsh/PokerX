#ifndef _DEALER_H
#define _DEALER_H

#include "cards/HoleCards.h"
#include "cards/CommunityCards.h"
#include "cards/CardCollection.h"
#include "cards/Card.h"
#include "players/Player.h"

class Dealer {
public:
    Dealer(Dealer &dealer);

    Dealer();

    cards::HoleCards dealHoleCards();

    cards::Card dealCard();

    void discardTopCard();

    cards::CardCollection dealFlop();

    cards::Card dealTurn();

    cards::Card dealRiver();

    void presentOptions(void Player & player);

    class Class1 {
    };

};

#endif //_DEALER_H