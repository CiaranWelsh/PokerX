//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_LIGHTHIGH_H
#define POKERX_LIGHTHIGH_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "eState.h"

using namespace pokerx;
class LightHigh : public State {
public:

        void enter(StateMachine* machine) override {};
        void action(StateMachine *machine) override ;
        void exit(StateMachine* machine) override {};
        static LightHigh& getInstance();
        [[nodiscard]] unsigned int getType() const override;

private:
    LightHigh() = default;
    unsigned int type_ = LIGHT_HIGH;

};


#endif //POKERX_LIGHTHIGH_H
