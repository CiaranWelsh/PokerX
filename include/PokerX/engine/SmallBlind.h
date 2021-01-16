//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_SMALLBLIND_H
#define POKERSIMULATIONSINCPP_SMALLBLIND_H


#include "PokerX/engine/State.h"

namespace pokerx {

    class SmallBlind : public State {
    public:

        ~SmallBlind() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static SmallBlind& getInstance();

    private:
        SmallBlind() = default;

    };

}

#endif //POKERSIMULATIONSINCPP_SMALLBLIND_H
