/**
 * Project PokerSimulationsInCpp
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <eval/Hand.h>
#include "ActionType.h"

class Player {
private:
    std::string type = "Player";
protected:
    std::string _name;
public:
    Player();

    ~Player();

    Player(Player &player);

    double stack = 0;

    explicit Player(std::string name);

    bool inplay = false;

    eval::Hand *hand{};

    std::string getName();

    void setName(std::string name);

    virtual ActionType play();

    friend ostream& operator<<(ostream& os, Player& player);

    std::string getType();
};

#endif //_PLAYER_H