//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_CALL_H
#define POKERX_CALL_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Call : public State {
    public:

        ~Call() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Call& getInstance();

    private:
        Call() = default;

    };

}


#endif //POKERX_CALL_H
