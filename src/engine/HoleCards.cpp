//
// Created by CiaranWelsh on 18/12/2019.
//

#include "PokerX/engine/HoleCards.h"
#include <iostream>


namespace pokerx {


    HoleCards::HoleCards(const ICardPtr& card1, const ICardPtr& card2)
            : RestrictedCardCollection({card1, card2}, 2) {
    }

    HoleCards::HoleCards(const std::string&  card1, const std::string&  card2)
        : RestrictedCardCollection({card1, card2}, 2){}

    HoleCards::HoleCards()
        : RestrictedCardCollection(std::vector<ICardPtr>() , 2){};

}
