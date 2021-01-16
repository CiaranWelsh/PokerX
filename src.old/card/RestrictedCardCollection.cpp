//
// Created by Ciaran on 08/01/2021.
//

#include "RestrictedCardCollection.h"
#include "Error.h"

namespace cards {

    RestrictedCardCollection::RestrictedCardCollection(std::vector<ICard *> cards)
        : CardCollection(std::move(cards)), max_cards_(cards_.size()){
        std::cout << "size: " << size() << std::endl;
        std::cout << "mac_cards: " << max_cards_ << std::endl;

        if (size() > max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
    }

    RestrictedCardCollection::RestrictedCardCollection(const std::vector<ICard *>& cards, unsigned int max_num_cards)
        : CardCollection(cards), max_cards_(max_num_cards) {
        if (size() > max_cards_) {
            LOGIC_ERROR << err_msg_ << std::endl;
        }
    }
    RestrictedCardCollection::RestrictedCardCollection(unsigned int max_num_cards)
        : CardCollection(), max_cards_(max_num_cards){
        if (max_cards_ == 0){
            LOGIC_ERROR << "Can't have a CardCollection containint a maximum of 0 Cards" << std::endl;
        }
    }

    void RestrictedCardCollection::add(const vector<ICard *> &cards) {
        if (size() + cards.size() > max_cards_){
            LOGIC_ERROR << err_msg_ << std::endl;
        }
        CardCollection::add(cards);
    }

    void RestrictedCardCollection::add(ICard *card) {
        if (size() == max_cards_){
            LOGIC_ERROR << err_msg_ << std::endl;
        }
        CardCollection::add(card);
    }



}