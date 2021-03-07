//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_STREETMACHINE_H
#define POKERX_STREETMACHINE_H

#include "PokerX/engine/StateMachine.h"

namespace pokerx {


    // @Deprecated. Do not use.
    class [[maybe_unused]] StreetMachine : public StateMachine {
        void setState(State &state) override {};

        void action() override {};

        void reset() override {};

    };

}

#endif //POKERX_STREETMACHINE_H
