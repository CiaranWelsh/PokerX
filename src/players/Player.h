/**
 * Project PokerSimulationsInCpp
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <eval/Hand.h>
#include <game/Pot.h>
#include <game/GamePlay.h>
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

    explicit Player(std::string name);

    std::string getName();

    void setName(std::string name);

    void play(game::GamePlay &gamePlay, ActionType action, double amount);

    /*
     * This method should be overriden in Player classes. This
     * Is where an reinforcement learning algorithm could be implemented
     */
    virtual ActionType choose_action(std::shared_ptr<std::vector<ActionType>> actions){
        return NoAction;
    };

    friend ostream &operator<<(ostream &os, Player &player);

    std::string getType();

    double stack = 0;

    bool inplay = true;

    bool played_this_street = false;

    bool all_in;

    eval::Hand getHand(game::GamePlay &gamePlay);
};

#endif //_PLAYER_H