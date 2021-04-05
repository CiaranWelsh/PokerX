//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_SHOWDOWN_H
#define POKERX_SHOWDOWN_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Showdown : public State {
    public:

        ~Showdown() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Showdown &getInstance();

    private:
        Showdown() = default;

    };

}

#endif //POKERX_SHOWDOWN_H
