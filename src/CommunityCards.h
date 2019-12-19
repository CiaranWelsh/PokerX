//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
#define POKERSIMULATIONSINCPP_COMMUNITYCARDS_H

#include "CardCollection.h"
#include "Card.h"

namespace cards {
    class CommunityCards : public cards::CardCollection {
    public:
        CommunityCards();

        explicit CommunityCards(vector<Card> &container);

        explicit CommunityCards(CardCollection container);

        ~CommunityCards();

        CommunityCards(cards::Card &flop1, cards::Card &flop2, cards::Card &flop3);

        CommunityCards(cards::Card &flop1, cards::Card &flop2, cards::Card &flop3, cards::Card &turn);

        CommunityCards(cards::Card &flop1, cards::Card &flop2, cards::Card &flop3, cards::Card &turn, cards::Card &river);

    };
}

#endif //POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
