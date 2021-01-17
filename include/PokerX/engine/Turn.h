//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_TURN_H
#define POKERX_TURN_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Turn : public State {
    public:

        ~Turn() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Turn& getInstance();

    private:
        Turn() = default;

    };

}


#endif //POKERX_TURN_H
