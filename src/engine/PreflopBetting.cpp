//
// Created by Ciaran on 17/01/2021.
//

#include <iostream>
#include "PokerX/engine/PreflopBetting.h"
#include "PokerX/engine/Flop.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void PreflopBetting::enter(StateMachine *machine) {
        std::cout << "Entering Preflop Betting" << std::endl;

    }

    void PreflopBetting::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(PlayerToAct::getInstance());
    }

    void PreflopBetting::exit(StateMachine *machine) {}

    PreflopBetting &PreflopBetting::getInstance() {
        static PreflopBetting singleton;
        return singleton;
    }

    unsigned int PreflopBetting::getType() const {
        return PREFLOP_STATE;
    }
}

