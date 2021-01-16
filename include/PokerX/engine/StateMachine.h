//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_STATEMACHINE_H
#define POKERSIMULATIONSINCPP_STATEMACHINE_H

#include "State.h"
#include "eState.h"

namespace pokerx {
    class State;

    class StateMachine {
    public:

        /**
         * @brief Default constructor
         */
        StateMachine() = default;

        /**
         * @brief constructor that takes a
         * state to start the state machine in
         */
        StateMachine(State *starting_state);

        /**
         * @brief abstract method to change the current
         * state of the state machine.
         */
        virtual void setState(State &state) = 0;

        /**
         * @brief returns the current state of the
         * state machine
         */
        [[nodiscard]] State *getState() const;

        /**
         * @brief abstract method for invoking the
         * action of the current state. This
         * is the main entry point for "turning" the
         * game cycle
         */
        virtual void action() = 0;

        /**
         * @brief Abstract method to return the StateMachine back to the
         * starting state.
         */
        virtual void reset() = 0;

    protected:
        State *state_ = nullptr;

    };


}

#endif //POKERSIMULATIONSINCPP_STATEMACHINE_H
