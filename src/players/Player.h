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
    std::string name;
public:

    Player();

    ~Player();

    Player(Player &player);

    Player& operator=(Player &player);

    explicit Player(std::string name);

    Player(std::string name, HoleCards holeCards);

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

    virtual std::string getType();

    eval::Hand getHand(game::GamePlay &gamePlay);

    void reset();

    cards::HoleCards holeCards;

    double pot;

    double stack = 0;

    bool inplay = true;

    bool played_this_street = false;

    bool all_in = false;

    friend ostream &operator<<(ostream &os, Player &player);

};

#endif //_PLAYER_H