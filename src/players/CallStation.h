/**
 * Project PokerSimulationsInCpp
 */


#ifndef _CALLSTATION_H
#define _CALLSTATION_H

#include <utility>

#include "Player.h"


class CallStation: public Player {
private:
    std::string type = "CallStation";
public:
    using Player::Player;

    ActionType choose_action(std::vector<ActionType> actions);



};

#endif //_CALLSTATION_H