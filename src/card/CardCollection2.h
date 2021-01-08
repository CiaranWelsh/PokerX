//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION2_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION2_H

#include <utility>
#include <vector>
#include "Card.h"

namespace cards {

    class CardCollection1 {

    protected:
        vector<Card> cards_;
    public:
        CardCollection1() = default;

        explicit CardCollection1(std::vector<Card> cards)
            : cards_(std::move(cards)){};

        int size(){
            return cards_.size();
        }

        void add(const Card& card){
            cards_.push_back(card);
        }

    };
    class CardCollection3 {

    protected:
        vector<ICard*> cards_;
    public:
        CardCollection3() = default;

        explicit CardCollection3(std::vector<ICard*> cards)
            : cards_(std::move(cards)){};

        int size(){
            return cards_.size();
        }

        void add(ICard* card){
            cards_.push_back(card);
        }

    };
}


#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
