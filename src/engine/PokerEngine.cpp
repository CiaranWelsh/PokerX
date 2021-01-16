//
// Created by Ciaran on 10/01/2021.
//

#include "PokerEngine.h"
#include <iostream>
#include <vector>
#include <cassert>
#include "CallStationPlayer.h"

namespace engine {

    void PokerEngine::action() {
        state_->action(this);
    }

    void PokerEngine::reset() {
        pot_.reset();
    }

    void PokerEngine::rotate() {
        Player *button = players_[0];
        std::vector < Player * > new_player_positions;
        std::cout << "here" << std::endl;
        for (int i = 1; i < players_.size() - 1; i++) {
            std::cout << "here: " << i << std::endl;
            new_player_positions.push_back(players_[i]);
        }
        std::cout << "here2" << std::endl;
        new_player_positions.push_back(button); // now Small blind
        assert(new_player_positions.size() == nPlayers_);
        players_ = new_player_positions;
    }

    void PokerEngine::initPlayers() {
        for (auto &it: players_) {
            auto *player = new CallStationPlayer();
            players_.push_back(player);
        }
    }

    int PokerEngine::getNPlayers() const {
        return nPlayers_;
    }

    void PokerEngine::setNPlayers(int nPlayers) {
        PokerEngine::nPlayers_ = nPlayers;
    }


    float PokerEngine::getCurrentBet() const {
        return currentBet_;
    }

    void PokerEngine::setCurrentBet(float currentBet) {
        PokerEngine::currentBet_ = currentBet;
    }

    void PokerEngine::contribPot(float amount) {
        pot_ += amount;
    }

    State *PokerEngine::getState() const {
        return state_;
    }

    const std::vector<Player *> &PokerEngine::getPlayers() const {
        return players_;
    }

    const Pot &PokerEngine::getPot() const {
        return pot_;
    }
}