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

    Deck::Deck() : RestrictedCardCollection(buildDeck(), 52){
        if (!isUniqueSet()) {
            LOGIC_ERROR << "Non unique elements found in Deck. A deck must be unique" << std::endl;
        }
    }

    std::vector<ICard*> Deck::buildDeck() {
        std::vector<ICard*> cards;
        for (int r : pokerx::getRanks()) {
            for (const auto &s : pokerx::getSuits()) {
                ICard *iCard = new Card(r, s);
                cards.push_back(iCard);
            }
        }
        return cards;
    }

    Deck::~Deck() {
        for (auto &it: cards_) {
            delete it;
        }
    }

    Deck::Deck(const Deck &deck) {
        for (auto &it: deck) {
            ICard *card = new Card();
            card->setSuit(it->getSuit());
            card->setRank(it->getRank());
            cards_.push_back(card);
        }
    }

    Deck::Deck(Deck &&deck) noexcept {
        for (auto &it: deck) {
            cards_.push_back(it);
            delete it;
        }
    }

    Deck &Deck::operator=(const Deck &deck) {
        if (this != &deck) {
            for (auto &it: deck) {
                ICard *card = new Card();
                card->setSuit(it->getSuit());
                card->setRank(it->getRank());
                cards_.push_back(card);
            }
        }
        return *this;
    }

    Deck &Deck::operator=(Deck &&deck) noexcept {
        if (this != &deck) {
            for (auto &it: deck) {
                cards_.push_back(it);
                delete it;
            }
        }
        return *this;
    }

}












