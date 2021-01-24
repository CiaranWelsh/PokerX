//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_ENTERSTREET_H
#define POKERX_ENTERSTREET_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class EnterStreet : public State {
    public:

        ~EnterStreet() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static EnterStreet& getInstance();

    private:
        EnterStreet() = default;

    };

}



#endif //POKERX_ENTERSTREET_H
