//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_BIGBLIND_H
#define POKERX_BIGBLIND_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class BigBlind : public State {
    public:

        ~BigBlind() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static BigBlind &getInstance();

    private:
        BigBlind() = default;

    };

}


#endif //POKERX_BIGBLIND_H
