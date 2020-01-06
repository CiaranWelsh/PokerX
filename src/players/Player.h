/**
 * Project PokerSimulationsInCpp
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <eval/Hand.h>
#include <game/Pot.h>
#include "ActionType.h"

class Player {
private:
    std::string type = "Player";
protected:
    std::string _name;
public:

    Pot pot;

    Player();

    ~Player();

    Player(Player &player);

    cards::HoleCards holeCards;

    double stack = 0;

    explicit Player(std::string name);

    bool inplay = false;

    std::string getName();

    void setName(std::string name);

    virtual void play(ActionType action, double amount=0.0);

    friend ostream &operator<<(ostream &os, Player &player);

    std::string getType();

};

#endif //_PLAYER_H