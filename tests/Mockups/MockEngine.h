//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_MOCKENGINE_H
#define POKERSIMULATIONSINCPP_MOCKENGINE_H

#include "gmock/gmock.h"
#include "NoLimitHoldem.h"

using namespace engine;
using namespace testing;

class MockEngine : public StateMachine {
public:
    using StateMachine::StateMachine;
    MOCK_METHOD(void, setState, (EngineState&), ());

};



#endif //POKERSIMULATIONSINCPP_MOCKENGINE_H
