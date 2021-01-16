#ifndef POKERSIMULATIONSINCPP_RESETSTATE_H
#define POKERSIMULATIONSINCPP_RESETSTATE_H

#include "PokerX/engine/State.h"
#include "PokerX/engine/eState.h"

namespace pokerx {

    class ResetState : public State {
    public:

        ~ResetState() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static ResetState& getInstance();

    private:
        ResetState() = default;

    };

}


#endif //POKERSIMULATIONSINCPP_RESETSTATE_H
