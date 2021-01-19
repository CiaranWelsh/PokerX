//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_REMOVECHECKFROMOPTIONS_H
#define POKERX_REMOVECHECKFROMOPTIONS_H



#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class RemoveCheckFromOptions : public State {
    public:

        ~RemoveCheckFromOptions() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static RemoveCheckFromOptions& getInstance();

    private:
        RemoveCheckFromOptions() = default;

    };

}


#endif //POKERX_REMOVECHECKFROMOPTIONS_H
