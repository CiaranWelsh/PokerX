//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_MOCKENGINE_H
#define POKERSIMULATIONSINCPP_MOCKENGINE_H

#include "gmock/gmock.h"
#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"

using namespace pokerx;
using namespace testing;

class MockPokerEngine : public StateMachine {
public:

    MockPokerEngine() = default;

    explicit MockPokerEngine(State &state)
            : StateMachine(&state) {};

    MOCK_METHOD(void, setState, (State & ), ());
    MOCK_METHOD(State*, getState, (), (const));
    MOCK_METHOD(void, action, (), ());
    MOCK_METHOD(void, reset, (), ());

};


#endif //POKERSIMULATIONSINCPP_MOCKENGINE_H
