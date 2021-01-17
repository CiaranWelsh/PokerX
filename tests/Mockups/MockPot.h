//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_MOCKPOT_H
#define POKERX_MOCKPOT_H

#include "gmock/gmock.h"
#include "PokerX/engine/Pot.h"

using namespace pokerx;
using namespace testing;

class MockPot : public Pot {
public:

    MockPot() = default;

    MOCK_METHOD(float, getValue, (), (const));
    MOCK_METHOD(void, reset, (), ());

};


#endif //POKERX_MOCKPOT_H
