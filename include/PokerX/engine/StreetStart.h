//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_STREETSTART_H
#define POKERX_STREETSTART_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class StreetStart : public State {
    public:

        ~StreetStart() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static StreetStart &getInstance();

    private:
        StreetStart() = default;

    };

}


#endif //POKERX_STREETSTART_H
