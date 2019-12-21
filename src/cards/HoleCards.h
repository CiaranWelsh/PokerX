//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HOLECARDS_H
#define POKERSIMULATIONSINCPP_HOLECARDS_H

#include "CardCollection.h"

namespace cards {
    class HoleCards : public cards::CardCollection {
    public:
        HoleCards();

        ~HoleCards();

        explicit HoleCards(vector<Card> &container);

        explicit HoleCards(CardCollection container);

        HoleCards(Card &card1, Card &card2);

        HoleCards(const HoleCards &holeCards);

    };
}
#endif //POKERSIMULATIONSINCPP_HOLECARDS_H
