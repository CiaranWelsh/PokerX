//
// Created by CiaranWelsh on 18/12/2019.
//

#include <stdexcept>
#include "CommunityCards.h"


namespace cards {


    CommunityCards::CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3) 
        : RestrictedCardCollection({flop1, flop2, flop3}, 5) {};

    CommunityCards::CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3, ICard*turn)
            : RestrictedCardCollection({flop1, flop2, flop3, turn}, 5){}

    CommunityCards::CommunityCards(ICard*flop1, ICard*flop2, ICard*flop3, ICard*turn, ICard*river)
            : RestrictedCardCollection({flop1, flop2, flop3, turn}, 5){}

    CommunityCards::CommunityCards(std::vector<ICard*> &cards) : RestrictedCardCollection(cards, 5){}


}