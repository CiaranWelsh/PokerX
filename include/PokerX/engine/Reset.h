#ifndef POKERSIMULATIONSINCPP_RESETSTATE_H
#define POKERSIMULATIONSINCPP_RESETSTATE_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    class Reset : public State {
    public:

        ~Reset() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static Reset &getInstance();

    private:
        Reset() = default;

    };

}


#endif //POKERSIMULATIONSINCPP_RESETSTATE_H
