//
// Created by Ciaran on 17/01/2021.
//

#include <PokerX/Error.h>
#include <algorithm>
#include "PokerX/engine/PlayerManager.h"

namespace pokerx {

    void PlayerManager::addPlayer(Player *player) {
        players_.push_back(player);
    }

    void PlayerManager::rotate() {
        Player *front_player = players_[0];
        players_.erase(players_.begin());
        players_.push_back(front_player);
        // must update current_player field
        current_player_ = players_[0];
        /*
         * Makes this method recursive. Keep rotating until you find a
         * player who is still in the game. All players should be inplace=true
         * when the game begins
         */
        if (!current_player_->isInPlay()) {
            rotate();
        }
    }


    Player *&PlayerManager::operator[](int index) {
        if (players_.empty()) {
            LOGIC_ERROR << "You cannot get access to players "
                        << "as there are not players yet." << std::endl;
        }
        return players_[index];
    }

    int PlayerManager::size() {
        return players_.size();
    }

    std::vector<Player *>::iterator PlayerManager::begin() {
        return players_.begin();
    }

    std::vector<Player *>::iterator PlayerManager::end() {
        return players_.end();
    }

    bool PlayerManager::checkAllPlayersEqual() {
        std::vector<float> amounts;
        for (Player* player : players_) {
            if (player->isInPlay())
                amounts.push_back(player->getStack());
        }

        bool equal = false;
        if (std::adjacent_find(amounts.begin(), amounts.end(), std::not_equal_to<>()) == amounts.end()) {
            equal = true;
        }
        return equal;
    }


    void PlayerManager::setButton(Player *button) {
        button_ = button;
    }

    Player *PlayerManager::getButton() {
        return button_;
    }

    std::ostream &operator<<(std::ostream &os, PlayerManager &players) {
        os << "[";
        for (int i = 0; i < players.size(); i++) {
            if (i == players.size() - 1)
                os << *players[i] << "]";
            else
                os << *players[i] << ", ";
        }
        os << "]";
        return os;
    }

    Player *PlayerManager::getCurrentPlayer() const {
        return current_player_;
    }

    void PlayerManager::setCurrentPlayer(Player *currentPlayer) {
        current_player_ = currentPlayer;
    }

    Player *PlayerManager::operator[](const std::string &name){
        Player* x = nullptr;
        for (auto* player : players_){
            if (player->getName() == name)
                x = player;
        }
        if (x == nullptr)
            LOGIC_ERROR<<"Did not find a player with that name" << std::endl;
        return x;
    }


}
