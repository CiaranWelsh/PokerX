//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_FLOP_H
#define POKERX_FLOP_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Flop : public State {
    public:

        ~Flop() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Flop &getInstance();

    private:
        Flop() = default;

    };

}

#endif //POKERX_FLOP_H
