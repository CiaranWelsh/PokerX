//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_STREETMACHINE_H
#define POKERX_STREETMACHINE_H

#include "PokerX/engine/StateMachine.h"

namespace pokerx {


    class StreetMachine : public StreetMachine {
        void setState(State &state) override;

        void action(Action action) override;

        void reset() override;

    };

}

#endif //POKERX_STREETMACHINE_H
