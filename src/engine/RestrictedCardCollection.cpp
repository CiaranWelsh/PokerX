//
// Created by Ciaran on 08/01/2021.
//

#include "PokerX/engine/RestrictedCardCollection.h"
#include "PokerX/Error.h"

namespace pokerx {

    RestrictedCardCollection::RestrictedCardCollection(std::vector<ICardPtr> cards)
            : CardCollection(std::move(cards)), max_cards_(cards_.size()) {
        if (size() > max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
    }

    RestrictedCardCollection::RestrictedCardCollection(const std::vector<ICardPtr> &cards, unsigned int max_num_cards)
            : CardCollection(cards), max_cards_(max_num_cards) {
        if (size() > max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
    }

    RestrictedCardCollection::RestrictedCardCollection(unsigned int max_num_cards)
            : CardCollection(), max_cards_(max_num_cards) {
        if (max_cards_ == 0) {
            LOGIC_ERROR << "Can't have a CardCollection containint a maximum of 0 Cards" << std::endl;
        }
    }

    void RestrictedCardCollection::add(const std::vector<ICardPtr> &cards) {
        if (size() + cards.size() > max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
        CardCollection::add(cards);
    }

    void RestrictedCardCollection::add(ICardPtr card) {
        if (size() == max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
        CardCollection::add(card);
    }

    void RestrictedCardCollection::add(const CardCollection &cardCollection) {
        if (size() == max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
        CardCollection::add(cardCollection);
    }


}