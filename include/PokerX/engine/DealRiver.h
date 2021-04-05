//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_DealRiver_H
#define POKERX_DealRiver_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    class DealRiver : public State {
    public:

        ~DealRiver() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static DealRiver &getInstance();

    private:
        DealRiver() = default;

    };

}


#endif //POKERX_DealRiver_H
