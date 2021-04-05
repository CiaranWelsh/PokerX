//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PLAYERMANAGER_H
#define POKERX_PLAYERMANAGER_H

#include <vector>
#include "PokerX/engine/Player.h"
#include "PokerX/engine/RotatoryContainer.h"
#include "PokerX/engine/IPlayerManager.h"
#include <iostream>
#include <sstream>

namespace pokerx {


    /**
     * @brief Container class for Player instances.
     * @details Responsible for the rotatory aspects of poker.
     * When the current cards are done with, the button moves.
     * We do this by rotating the order of the vector, so in a
     * 6 player game, player 6 becomes player 1. Therefore,  the button
     * and all the positions (Btn, UTG etc) are fixed numerical values (0 = btn).
     * A call to nextPlayer on the other hand, increments the currentPlayerIdx.
     */
    class PlayerManager : public IPlayerManager {

    public:

        using IPlayerManager::IPlayerManager;

        PlayerManager() = default;

        /**
         * @brief calls each of the contained Player objects updateObservers method
         * to implement the observer
         * @details
         * @note Could have the PlayerManager observe the GameVariables instead?
         */
        void updateObservers(IGameVariables &source, const std::string &data_field);

        void add(SharedIPlayerPtr player) override;

        [[nodiscard]] bool allPlayersEqual() override;

        [[nodiscard]] SharedIPlayerPtr getCurrentPlayer() const override;

        template<class T>
        static PlayerManager populate(unsigned int n, float stack) {
            PlayerManager manager;
            int i = 0;
            while (i < n) {
                std::ostringstream os;
                os << "Player" << i;
                manager.add(std::make_shared<T>(T(os.str(), stack)));
                i++;
            }
            return manager;
        }

        /**
         * @brief Configure all players to observe the GameVariables
         * reference
         * @details This method is important for the observer pattern that is
         * implemented between GameVariables class and Player instances.
         * Players observe the GameVariables
         */
        void watch(IGameVariables *variables) override;

        void moveButton() override;

        /**
         * @brief rotate players and move the current player
         * pointer onto the next player.
         */
        void nextPlayer() override;

        /**
         * @brief get the player indexed by @param n
         */
        SharedIPlayerPtr getPlayer(unsigned int n) override;

        [[nodiscard]] int getCurrentPlayerIdx() const override;

        void setCurrentPlayerIdx(int currentPlayerIdx) override;

        void setCurrentPlayerByName(const std::string &name) override;

        friend std::ostream &operator<<(std::ostream &os, PlayerManager &playerManager);

        void setStackSizeTo(float amount) override;

        void enumeratePlayerNames() override;

        void enumerateEmptyPlayerNames() override;

        std::vector<std::string> getPlayerNames() override;

        SharedIPlayerPtr getPlayerByName(const std::string &name) override;

        /**
         * @brief get the player at index 0, which is the button
         */
        SharedIPlayerPtr getButton() override;

        /**
         * @brief set the player with name @param playerName
         * as the button.
         */
        void setButton(std::string playerName) override;

        /**
         * @brief get the index in PlayerManager of @param player
         */
        int getIndexOfPlayer(const SharedIPlayerPtr &player) override;

        void resetAmountContribThisStreet() override;

        std::vector<Hand> getPlayerHands() override;

        std::unordered_map<std::string, Hand> getRemainingPlayerHands() override;

        void reset() override;


        SharedIPlayerPtr getSmallBlind() override;

        SharedIPlayerPtr getBigBlind() override;

        /**
         * @brief indicator method that returns true
         * when all players have taken at least 1 turn this
         * street.
         */
        bool allPlayersTakenAtLeastOneTurn() override;

        int getNumPlayersStillInPot() override;
    };
}


#endif //POKERX_PLAYERMANAGER_H
