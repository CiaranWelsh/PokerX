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

//        explicit CommunityCards(std::vector<ICardPtr > &cards);
//
//        CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3);
//
//        CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3, ICardPtr turn);
//
//        CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3, ICardPtr turn, ICardPtr river);


    };
}

#endif //POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
