//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PREFLOP_H
#define POKERX_PREFLOP_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Preflop : public State {
    public:

        ~Preflop() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Preflop& getInstance();

    private:
        Preflop() = default;

    };

}

#endif //POKERX_PREFLOP_H
