//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_STATE_H
#define POKERSIMULATIONSINCPP_STATE_H

#include "NoLimitHoldem.h"
#include "StateMachine.h"

namespace engine {

    class StateMachine;

    class State {
    public:
        virtual void enter(StateMachine *entity) = 0;

        virtual void action(StateMachine *entity) = 0;

        virtual void exit(StateMachine *entity) = 0;

        virtual ~State() = default;
    };
}

#endif //POKERSIMULATIONSINCPP_STATE_H
