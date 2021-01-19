//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_ALLIN_H
#define POKERX_ALLIN_H

#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    class AllIn : public State {
    public:

        ~AllIn() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static AllIn& getInstance();

    private:
        AllIn() = default;

    };

}



#endif //POKERX_ALLIN_H
