//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_STATEMACHINE_H
#define POKERSIMULATIONSINCPP_STATEMACHINE_H

#include "State.h"
#include "StateType.h"

namespace pokerx {
    class State;

    class StateMachine {
    public:
        StateMachine() = default;

        StateMachine(State *starting_state);

        virtual void setState(State &state) = 0;

        [[nodiscard]] virtual State *getState() const;

        virtual void action() = 0;

    protected:
        State *state_ = nullptr;

    };


}

#endif //POKERSIMULATIONSINCPP_STATEMACHINE_H
