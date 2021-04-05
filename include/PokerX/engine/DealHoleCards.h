//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_DealHoleCards_H
#define POKERX_DealHoleCards_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    class DealHoleCards : public State {
    public:

        ~DealHoleCards() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static DealHoleCards &getInstance();

    private:
        DealHoleCards() = default;

    };

}


#endif //POKERX_DealHoleCards_H
