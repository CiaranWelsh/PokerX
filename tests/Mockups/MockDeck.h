//
// Created by Ciaran Welsh on 07/03/2021.
//

#ifndef POKERX_MOCKDECK_H
#define POKERX_MOCKDECK_H

#include "gmock/gmock.h"
#include "PokerX/engine/RestrictedCardCollection.h"

using namespace pokerx;

class MockDeck : public RestrictedCardCollection {
public:
    MockDeck() = default;
    ~MockDeck() override = default;
    MOCK_METHOD(std::vector<ICardPtr >, buildDeck, (), ());
    MOCK_METHOD(CardCollection, shuffle, (), ());
};










#endif //POKERX_MOCKDECK_H
