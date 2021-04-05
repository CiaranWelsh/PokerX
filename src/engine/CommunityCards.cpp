//
// Created by CiaranWelsh on 18/12/2019.
//

#include "PokerX/engine/CommunityCards.h"


namespace pokerx {


    CommunityCards::CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3)
            : RestrictedCardCollection({flop1, flop2, flop3}, 5) {};

    CommunityCards::CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3, ICardPtr turn)
            : RestrictedCardCollection({flop1, flop2, flop3, turn}, 5) {}

    CommunityCards::CommunityCards(ICardPtr flop1, ICardPtr flop2, ICardPtr flop3, ICardPtr turn, ICardPtr river)
            : RestrictedCardCollection({flop1, flop2, flop3, turn}, 5) {}

    CommunityCards::CommunityCards(std::vector<ICardPtr> &cards) : RestrictedCardCollection(cards, 5) {}


}