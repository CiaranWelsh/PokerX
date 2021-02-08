//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_ALLPLAYERSEQUAL_H
#define POKERX_ALLPLAYERSEQUAL_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    // todo rename this class something more appropriate

    class AllPlayersEqual : public State {
    public:

        ~AllPlayersEqual() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static AllPlayersEqual& getInstance();

    private:
        AllPlayersEqual() = default;

    };

}

#endif //POKERX_ALLPLAYERSEQUAL_H
