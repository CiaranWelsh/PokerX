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

        using RestrictedCardCollection::operator[];

        HoleCards();

        ~HoleCards() override = default;

        HoleCards(const ICardPtr&  card1, const ICardPtr&  card2);

        HoleCards(const std::string&  card1, const std::string&  card2);

    };
}
#endif //POKERSIMULATIONSINCPP_HOLECARDS_H
