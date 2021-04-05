//
// Created by CiaranWelsh on 08/12/2019.
//

#include "PokerX/engine/Deck.h"
#include "PokerX/engine/Card.h"
#include "PokerX/Error.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <sstream>

/**
 *  todo delete this class and just have a method in CardCollection that builds a deck.
 *  This class is unnecessary.
 */

using namespace std;

namespace pokerx {

    Deck::Deck() : RestrictedCardCollection(buildDeck(), 52) {
        if (!isUniqueSet()) {
            LOGIC_ERROR << "Non unique elements found in Deck. A deck must be unique" << std::endl;
        }
    }

    std::vector<ICardPtr> Deck::buildDeck() {
        std::vector<ICardPtr> cards;
        for (int r : pokerx::getRanks()) {
            for (const auto &s : pokerx::getSuits()) {
                cards.push_back(std::make_shared<Card>(r, s));
            }
        }
        return cards;
    }

    Deck::~Deck() = default;

    void Deck::reset() {
        cards_ = buildDeck();
    }


}












