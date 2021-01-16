//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_LIGHTOFF_H
#define POKERX_LIGHTOFF_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "eState.h"
using namespace pokerx;


/**
 * A Starting state that switches to low intensity light
 */
class LightOff : public State {
public:

        void enter(StateMachine* machine) override {};
        void action(StateMachine *machine) override ;
        void exit(StateMachine* machine) override {};
        static LightOff& getInstance();
        [[nodiscard]] unsigned int getType() const override;
private:
    LightOff() = default;
    unsigned int type_ = LIGHT_OFF;

};

#endif //POKERX_LIGHTOFF_H
