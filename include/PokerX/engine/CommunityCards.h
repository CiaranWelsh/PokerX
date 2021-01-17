//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
#define POKERSIMULATIONSINCPP_COMMUNITYCARDS_H

#include "PokerX/engine/RestrictedCardCollection.h"
#include "PokerX/engine/Card.h"

namespace pokerx {
    class CommunityCards : public RestrictedCardCollection {
    public:
        using RestrictedCardCollection::add;

        CommunityCards() = default;

        ~CommunityCards() override = default;

        explicit CommunityCards(vector<ICard*> &cards);

        CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3);

        CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3, ICard*turn);

        CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3, ICard*turn, ICard*river);


    };
}

#endif //POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
