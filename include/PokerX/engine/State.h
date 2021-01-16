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
        virtual ~State() = default;

        virtual void enter(StateMachine *machine) = 0;

        virtual void action(StateMachine *machine) = 0;

        virtual void exit(StateMachine *machine) = 0;

        [[nodiscard]] virtual unsigned int getType() const = 0;

    private:
        /**
         * subclasses should also have a type_ that hides this
         * type_.
         *
         * .. note:: this has been depreciated and will be removed
         * Instead of having a subclass hide type_, they just hard code the
         * type as the return value of getType().
         */
        unsigned int type_ = 0;

    };
}

#endif //POKERSIMULATIONSINCPP_POKERSTATE_H
