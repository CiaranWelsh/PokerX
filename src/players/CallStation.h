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
    ActionType play() override;

    CallStation();

    ~CallStation();

    CallStation(CallStation &callStation);

    explicit CallStation(Player player);

    explicit CallStation(std::string name);

};

#endif //_CALLSTATION_H