//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_NEXTPLAYER_H
#define POKERX_NEXTPLAYER_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class NextPlayer : public State {
    public:

        ~NextPlayer() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static NextPlayer& getInstance();

    private:
        NextPlayer() = default;

    };

}



#endif //POKERX_NEXTPLAYER_H
