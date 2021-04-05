//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_DealTurn_H
#define POKERX_DealTurn_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    class DealTurn : public State {
    public:

        ~DealTurn() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static DealTurn &getInstance();

    private:
        DealTurn() = default;

    };

}


#endif //POKERX_DealTurn_H
