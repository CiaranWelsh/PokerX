//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_DealFlop_H
#define POKERX_DealFlop_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    class DealFlop : public State {
    public:

        ~DealFlop() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static DealFlop& getInstance();

    private:
        DealFlop() = default;

    };

}



#endif //POKERX_DealFlop_H
