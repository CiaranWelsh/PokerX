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
     * @details
     */
    class PlayerManager : public IPlayerManager {

    public:

        PlayerManager() = default;

        /**
         * @brief calls each of the contained Player objects updateObservers method
         * to implement the observer
         * @details
         * @note Could have the PlayerManager observe the GameVariables instead?
         */
        void updateObservers(IGameVariables &source, const std::string &data_field);

        void add(SharedPlayerPtr player) override;

        [[nodiscard]] bool checkAllPlayersEqual() const override;

        SharedPlayerPtr getButton() override;

        [[nodiscard]] const SharedPlayerPtr &getCurrentPlayer() const override;

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

        [[nodiscard]] int getButtonIdx() const override;

        void setButtonIdx(int buttonIdx) override;

        [[nodiscard]] int getCurrentPlayerIdx() const override;

        void setCurrentPlayerIdx(int currentPlayerIdx) override;


    protected:

        /**
         * @brief implements the abstract method from superclass
         * for rotating the contents vector.
         * @details This method does *not* move the button or
         * the current player, only rotates the players once.
         * @see nextPlayer for another method that rotates the players
         * *and* moves current player pointer
         */
        void rotateContainerContents() override;

    private:

        /**
         * @brief implements the logic for moving the player pointer.
         */
        void moveCurrentPlayer() override;


    };
}


#endif //POKERX_PLAYERMANAGER_H
