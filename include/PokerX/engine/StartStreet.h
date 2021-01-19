//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_STARTSTREET_H
#define POKERX_STARTSTREET_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class StartStreet : public State {
    public:

        ~StartStreet() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static StartStreet& getInstance();

    private:
        StartStreet() = default;

    };

}



#endif //POKERX_STARTSTREET_H
