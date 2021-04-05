//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HOLECARDS_H
#define POKERSIMULATIONSINCPP_HOLECARDS_H

#include "RestrictedCardCollection.h"

namespace pokerx {
    class HoleCards : public RestrictedCardCollection {

    public:
        using RestrictedCardCollection::add;

        HoleCards() = default;

        ~HoleCards() override = default;

        HoleCards(ICardPtr  card1, ICardPtr  card2);

    };
}
#endif //POKERSIMULATIONSINCPP_HOLECARDS_H
