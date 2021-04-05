//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_RIVER_H
#define POKERX_RIVER_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class River : public State {
    public:

        ~River() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static River &getInstance();

    private:
        River() = default;

    };

}

#endif //POKERX_RIVER_H
