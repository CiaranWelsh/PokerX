/**
 * Project PokerSimulationsInCpp
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <eval/Hand.h>
#include "ActionType.h"

class Player {
    std::string _name;
public:
    Player();

    double stack = 0;

    explicit Player(std::string name);

    bool inplay = false;

    eval::Hand *hand{};

    std::string getName();

    void setName(std::string name);

    virtual ActionType play();

    friend ostream& operator<<(ostream os, Player player);
};

#endif //_PLAYER_H