//
// Created by Ciaran on 10/01/2021.
//

#include "ButtonMoves.h"
#include "SmallBlind.h"

namespace engine {

    void ButtonMoves::enter(StateMachine *engine) {
#ifdef DEBUG_MODE
        std::cout << "Entering ButtonMoves state" <<std::endl;
#endif
    }

    void ButtonMoves::action(StateMachine *engine) {
        // 1) reset the game for another game
        engine->reset();

        // 2) call for button to move to the left player
        engine->rotate();

        // 3) set engine state to post small blind 
        engine->setState(SmallBlind::getInstance());
    }

    void ButtonMoves::exit(StateMachine *engine) {

    }

    PokerEngineState &ButtonMoves::getInstance() {
        static ButtonMoves singleton;
        return singleton;
    }
}







