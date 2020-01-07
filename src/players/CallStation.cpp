/**
 * Project PokerSimulationsInCpp
 */


#include "CallStation.h"

#include <utility>
#include "ActionType.h"
#include "Errors.h"

/*
 * CallStation implementation
 */

ActionType CallStation::choose_action(std::shared_ptr<std::vector<ActionType>> actions) {
    ActionType action = Call;
    bool valid = std::find(actions->begin(), actions->end(), action) != actions->end();
    if (!valid){
        throw errors::InvalidActionError();
    }
    return action;
}


