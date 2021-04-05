//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PREFLOPBETTING_H
#define POKERX_PREFLOPBETTING_H


#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class PreflopBetting : public State {
    public:

        ~PreflopBetting() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static PreflopBetting &getInstance();

    private:
        PreflopBetting() = default;

    };

}

#endif //POKERX_PREFLOPBETTING_H
