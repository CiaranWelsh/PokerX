//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HOLECARDS_H
#define POKERSIMULATIONSINCPP_HOLECARDS_H

#include "CardCollection.h"
namespace Game {
    class HoleCards : public Game::CardCollection {
    public:
        HoleCards();
        ~HoleCards();

        HoleCards(Card &card1, Card &card2);

        HoleCards(const HoleCards &holeCards);

    };
}
#endif //POKERSIMULATIONSINCPP_HOLECARDS_H
