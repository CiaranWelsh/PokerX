//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_PLAYERTOACT_H
#define POKERX_PLAYERTOACT_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class PlayerToAct : public State {
    public:

        ~PlayerToAct() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static PlayerToAct &getInstance();

    private:
        PlayerToAct() = default;

    };

}


#endif //POKERX_PLAYERTOACT_H
