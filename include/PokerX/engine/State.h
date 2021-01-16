//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_STATE_H
#define POKERSIMULATIONSINCPP_STATE_H

#include "StateMachine.h"

namespace pokerx {

    // fwd declaration
    class StateMachine;

    /**
     * An abstract State interface. Subclasses
     * should be singletons but this can't be effectively
     * enforced by way of OOP so implementers of State
     * must remember to create a static getInstance method
     * which returns itself. It should look like this:
     *
     * static State& getInstance() {
     *      static DerivedState singleton;
     *      return singleton;
     * }
     */
    class State {
    public:
        virtual void enter(StateMachine *machine) = 0;

        virtual void action(StateMachine *machine) = 0;

        virtual void exit(StateMachine *machine) = 0;

        virtual ~State() = default;

        [[nodiscard]] virtual unsigned int getType() const = 0;

    private:
        unsigned int type_ = 0; // hidden by subclasses

    };
}

#endif //POKERSIMULATIONSINCPP_POKERSTATE_H
