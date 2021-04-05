//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_BUTTONMOVES_H
#define POKERSIMULATIONSINCPP_BUTTONMOVES_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class ButtonMoves : public State {
    public:

        ~ButtonMoves() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static ButtonMoves &getInstance();

    private:
        ButtonMoves() = default;

    };


}

#endif //POKERSIMULATIONSINCPP_BUTTONMOVES_H
