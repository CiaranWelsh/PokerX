/**
 * Project PokerSimulationsInCpp
 */


#include "CallStation.h"

#include <utility>
#include "ActionType.h"

/**
 * CallStation implementation
 */
CallStation::CallStation() : Player(){};

CallStation::CallStation(std::string name) : Player(std::move(name)){}

ActionType CallStation::play() {
    return Call;
}

CallStation::~CallStation() = default;


CallStation::CallStation(Player player) {
    _name = player.getName();
    stack = player.stack;
}

CallStation::CallStation(CallStation &callStation)  : Player(callStation) {
    _name = callStation.getName();
    stack = callStation.stack;
}
