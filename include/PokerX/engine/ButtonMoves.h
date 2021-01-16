//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_BUTTONMOVES_H
#define POKERSIMULATIONSINCPP_BUTTONMOVES_H

#include "State.h"
#include "PokerEngine.h"

namespace engine {

    class ButtonMoves : public State {
    public:

        void enter(StateMachine *engine) override;

        void action(StateMachine *engine) override;

        void exit(StateMachine *engine) override;

        static State &getInstance();

    private:

        ButtonMoves() = default;

    };

}
#endif //POKERSIMULATIONSINCPP_BUTTONMOVES_H
