/**
 * Project PokerSimulationsInCpp
 */


#ifndef _CALLSTATION_H
#define _CALLSTATION_H

#include <utility>

#include "Player.h"


class CallStation: public Player {
public:
    ActionType play() override;

    CallStation();

    explicit CallStation(std::string name);

};

#endif //_CALLSTATION_H