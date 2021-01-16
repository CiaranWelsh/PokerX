//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_LIGHTLOW_H
#define POKERX_LIGHTLOW_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "enumState.h"

using namespace pokerx;

class LightLow : public State {
public:

        void enter(StateMachine* machine) override {};
        void action(StateMachine *machine) override ;
        void exit(StateMachine* machine) override {};
        static LightLow& getInstance();
        [[nodiscard]] unsigned int getType() const override;

private:
    LightLow() = default;
    unsigned int type_ = LIGHT_LOW;
};


#endif //POKERX_LIGHTLOW_H
