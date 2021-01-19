//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_CHECK_H
#define POKERX_CHECK_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Check : public State {
    public:

        ~Check() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Check& getInstance();

    private:
        Check() = default;

    };

}



#endif //POKERX_CHECK_H
