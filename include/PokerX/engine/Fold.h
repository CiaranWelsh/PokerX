//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_FOLD_H
#define POKERX_FOLD_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Fold : public State {
    public:

        ~Fold() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Fold& getInstance();

    private:
        Fold() = default;

    };

}



#endif //POKERX_FOLD_H
