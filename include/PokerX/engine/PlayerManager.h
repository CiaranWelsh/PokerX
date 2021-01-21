//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PLAYERMANAGER_H
#define POKERX_PLAYERMANAGER_H

#include <vector>
#include "PokerX/engine/Player.h"
#include "PokerX/engine/RotatoryContainer.h"
#include <iostream>
#include <sstream>

namespace pokerx {

    /**
     * @brief Container class for Player instances.
     * @details
     */
    class PlayerManager : public RotatoryContainer<SharedPlayerPtr> {

    public:

        PlayerManager() = default;

        /**
         * @brief calls each of the contained Player objects update method
         * to implement the observer
         * @note Could have the PlayerManager observe the GameVariables instead?
         */
        void update(GameVariables &source, const std::string &data_field);

        void add(SharedPlayerPtr player) override;

        [[nodiscard]] bool checkAllPlayersEqual() const;

        SharedPlayerPtr getButton();

        [[nodiscard]] const SharedPlayerPtr &getCurrentPlayer() const;

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
        void watch(GameVariables &variables);

        void moveButton();

        /**
         * @brief rotate players and move the current player
         * pointer onto the next player.
         */
        void nextPlayer();

        [[nodiscard]] int getButtonIdx() const;

        void setButtonIdx(int buttonIdx);

        [[nodiscard]] int getCurrentPlayerIdx() const;

        void setCurrentPlayerIdx(int currentPlayerIdx);


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
        void moveCurrentPlayer();

        int button_idx = 0;
        int current_player_idx = 0;

    };
}


#endif //POKERX_PLAYERMANAGER_H
