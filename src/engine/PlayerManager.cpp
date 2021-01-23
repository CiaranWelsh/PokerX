//
// Created by Ciaran on 17/01/2021.
//

#include <PokerX/Error.h>
#include <algorithm>
#include <utility>
#include "PokerX/engine/PlayerManager.h"

namespace pokerx {

    void PlayerManager::add(const SharedPlayerPtr player) {
        contents_.push_back(player);
    }

    void PlayerManager::updateObservers(IGameVariables &source, const string &data_field) {
        for (const auto &player: contents_) {
            player->update(source, data_field);
        }
    }

    bool PlayerManager::checkAllPlayersEqual() const {
        std::vector<float> amounts;
        for (const auto & player : contents_) {
            if (player->isInPlay())
                amounts.push_back(player->getStack());
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
        /**
         *
         */
        for (const auto &player: contents_) {
            player->watch(variables);
//            variables->registerObserver(player);
        }
    }


    void PlayerManager::moveButton() {
        // if button index == vector size -1: btn is 0
        if (getButtonIdx() == size()){
            setButtonIdx(0);
        } else {
            // else i++
            setButtonIdx(getButtonIdx() + 1);
        }
    }

    void PlayerManager::moveCurrentPlayer() {
        // if button index == vector size -1: btn is 0
        if (getCurrentPlayerIdx() == size()){
            setCurrentPlayerIdx(0);
        } else {
            // else i++
            setCurrentPlayerIdx(getCurrentPlayerIdx() + 1);
        }
    }

    SharedPlayerPtr PlayerManager::getButton() {
        return contents_[getButtonIdx()];
    }

    SharedPlayerPtr PlayerManager::getCurrentPlayer() const {
        return contents_[getCurrentPlayerIdx()];
    }

    int PlayerManager::getButtonIdx() const {
        return button_idx;
    }

    void PlayerManager::setButtonIdx(int buttonIdx) {
        button_idx = buttonIdx;
    }

    int PlayerManager::getCurrentPlayerIdx() const {
        return current_player_idx;
    }

    void PlayerManager::setCurrentPlayerIdx(int currentPlayerIdx) {
        current_player_idx = currentPlayerIdx;
    }

    void PlayerManager::rotateContainerContents() {
        {
            if (contents_.size() == 1) {
                return;
            }
            std::vector<SharedPlayerPtr> new_contents(contents_.size());

            for (int i = 0; i < contents_.size() - 1; i++) { // -1 for penultimate element
                new_contents[i + 1] = contents_[i];
            }

            // deal with last
            new_contents[0] = contents_[contents_.size() - 1];
            // assign new contents vector to old
            contents_ = new_contents;
        }
    }

    void PlayerManager::nextPlayer() {
        rotateContainerContents();
        moveCurrentPlayer();
    }


}
