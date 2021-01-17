//
// Created by Ciaran on 10/01/2021.
//

#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/ResetState.h"
//#include <iostream>
//#include <vector>
//#include <cassert>
//#include "CallStationPlayer.h"

namespace pokerx {

    PokerEngine::PokerEngine()
        : StateMachine(&ResetState::getInstance()){}

    PokerEngine::PokerEngine(State* starting_state)
        : StateMachine(starting_state){}

    void PokerEngine::setState(State &state) {
        // When we initially enter the setState method we
        // can use the enter method to do stuff
        // with our existing state
        state_->enter(this);

        // we then set the new state
        state_ = &state;

        // And we get a chance to do stuff to this new state immediately after switching
        state_->exit(this);

        // enter and exit are by default empty
    }

    void PokerEngine::action() {
        state_->action(this);
    }

    void PokerEngine::action(unsigned int times) {
        for (int i=0; i<times; i++){
            state_->action(this);
        }
    }

    void PokerEngine::reset() {
        gameVariables_.getPot().reset();
    }

    const GameVariables &PokerEngine::getGameVariables() const {
        return gameVariables_;
    }
//
//    void PokerEngine::rotate() {
//        Player *button = players_[0];
//        std::vector < Player * > new_player_positions;
//        std::cout << "here" << std::endl;
//        for (int i = 1; i < players_.size() - 1; i++) {
//            std::cout << "here: " << i << std::endl;
//            new_player_positions.push_back(players_[i]);
//        }
//        std::cout << "here2" << std::endl;
//        new_player_positions.push_back(button); // now Small blind
//        assert(new_player_positions.size() == nPlayers_);
//        players_ = new_player_positions;
//    }
//
//    void PokerEngine::initPlayers() {
//        for (auto &it: players_) {
//            auto *player = new CallStationPlayer();
//            players_.push_back(player);
//        }
//    }
//
//    int PokerEngine::getNPlayers() const {
//        return nPlayers_;
//    }
//
//    void PokerEngine::setNPlayers(int nPlayers) {
//        PokerEngine::nPlayers_ = nPlayers;
//    }
//
//
//    float PokerEngine::getCurrentBet() const {
//        return currentBet_;
//    }
//
//    void PokerEngine::setCurrentBet(float currentBet) {
//        PokerEngine::currentBet_ = currentBet;
//    }
//
//    void PokerEngine::contribPot(float amount) {
//        pot_ += amount;
//    }
//
//    State *PokerEngine::getState() const {
//        return state_;
//    }
//
//    const std::vector<Player *> &PokerEngine::getPlayers() const {
//        return players_;
//    }
//
//    const Pot &PokerEngine::getPot() const {
//        return pot_;
//    }
}