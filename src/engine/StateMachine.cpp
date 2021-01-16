//
// Created by Ciaran on 10/01/2021.
//

#include "PokerX/engine/StateMachine.h"

namespace pokerx {

    StateMachine::StateMachine(State *starting_state)
            : state_(starting_state) {}


    State *StateMachine::getState() const {
        return state_;
    }

}





