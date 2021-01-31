//
// Created by Ciaran on 17/01/2021.
//

#include <PokerX/Error.h>
#include <algorithm>
#include <utility>
#include "PokerX/engine/PlayerManager.h"
#include <algorithm>

namespace pokerx {

    void PlayerManager::add(const SharedPlayerPtr player) {
        contents_.push_back(player);
    }

    void PlayerManager::updateObservers(IGameVariables &source, const std::string &data_field) {
        for (const auto &player: contents_) {
            player->update(source, data_field);
        }
    }

    bool PlayerManager::allPlayersEqual() const {
        std::vector<float> amounts;
        for (const auto &player : contents_) {
            if (player->hasFolded())
                amounts.push_back(player->getAmountContrib());
        }

        bool equal = false;
        if (std::adjacent_find(amounts.begin(), amounts.end(), std::not_equal_to<>()) == amounts.end()) {
            equal = true;
        }
        return equal;
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

    void PlayerManager::watch(IGameVariables *variables) {
        for (const auto &player: contents_) {
            player->watch(variables);
        }
    }

    void PlayerManager::nextPlayer() {
        // if button index == vector size -1: btn is 0
        if (getCurrentPlayerIdx() == size() - 1) {
            setCurrentPlayerIdx(0);
        } else {
            // else i++
            setCurrentPlayerIdx(getCurrentPlayerIdx() + 1);
        }
    }

    SharedPlayerPtr PlayerManager::getCurrentPlayer() const {
        return contents_[getCurrentPlayerIdx()];
    }

    int PlayerManager::getCurrentPlayerIdx() const {
        return current_player_idx;
    }

    SharedIPlayerPtr PlayerManager::getPlayer(unsigned int n) {
        return contents_[n];
    }

    void PlayerManager::setCurrentPlayerIdx(int currentPlayerIdx) {
        if (currentPlayerIdx < 0) {
            LOGIC_ERROR << "Can't have a negative index player" << std::endl;
        } else if (currentPlayerIdx > size() - 1) {
            LOGIC_ERROR << "Can't set player index greater than number of players" << std::endl;
        }
        current_player_idx = currentPlayerIdx;
    }

    int PlayerManager::getIndexOfPlayer(const SharedIPlayerPtr &player) {
        const std::string& name = player->getName();
        auto iter = std::find(contents_.begin(), contents_.end(), player);
        if (iter == contents_.end()){
            LOGIC_ERROR << "Player \"" << name  << "\" not in this PlayerManager. "
                                                               "These are available players: "
                                                               "" << *this << std::endl;
        }
        return std::distance(contents_.begin(), iter);
    }

    void PlayerManager::setCurrentPlayerByName(const std::string &name) {
        auto player = getPlayerByName(name);
        setCurrentPlayerIdx(getIndexOfPlayer(player));
    }

    SharedIPlayerPtr PlayerManager::getPlayerByName(const std::string &name) {
        // go collect the player names we'll search in
        std::vector<std::string> playerNames;
        for (const auto &player : contents_) {
            playerNames.push_back(player->getName());
        }

        for (int i = 0; i < size(); i++) {
            const std::string &playerName = playerNames[i];
            if (playerName == name) {
                return getPlayer(i);
            }
        }

        LOGIC_ERROR << "Player with name " << name << " wasn't found"
                    << ". These are your players: " << *this << std::endl;
    }

    std::vector<std::string> PlayerManager::getPlayerNames() {
        std::vector<std::string> names;
        for (const auto &player : contents_) {
            names.push_back(player->getName());
        }
        return names;
    }

    void PlayerManager::moveButton() {
        rotateContainerContents();
    }

    void PlayerManager::setStackSizeTo(float amount) {
        for (const auto &player : contents_) {
            player->setStack(amount);
        }
    }

    void PlayerManager::enumeratePlayerNames() {
        int i = 0;
        for (const auto &player : contents_) {
            std::ostringstream os;
            os << "Player" << i;
            player->setName(os.str());
        }
    }

    void PlayerManager::enumerateEmptyPlayerNames() {
        int i = 0;
        for (const auto &player : contents_) {
            std::ostringstream os;
            os << "Player" << i;
            if (player->getName().empty()) {
                player->setName(os.str());
            }
        }
    }

    void PlayerManager::resetAmountContribThisStreet() {
        for(const auto& player: contents_){
            player->setAmountContrib(0.0);
        }
    }

    std::vector<Hand> PlayerManager::getPlayerHands() {
        std::vector<Hand> hands;
        for (const auto& player: contents_){
            hands.emplace_back(Hand(player->getHand()));
        }
        return std::vector<Hand>();
    }

}
