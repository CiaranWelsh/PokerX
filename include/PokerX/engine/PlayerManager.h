//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PLAYERMANAGER_H
#define POKERX_PLAYERMANAGER_H

#include <vector>
#include "PokerX/engine/Player.h"
#include <iostream>
#include <sstream>

namespace pokerx {

    class PlayerManager {

    public:

        PlayerManager() = default;

        /**
         * @brief calls each of the contained Player objects update method
         * to implement the observer
         */
        void update(GameVariables &source, const std::string &data_field);


        void addPlayer(const SharedPlayerPtr &player);

        void rotate();

        SharedPlayerPtr operator[](const std::string &name);

        SharedPlayerPtr &operator[](int index);

        int size();

        [[nodiscard]] std::vector<SharedPlayerPtr>::const_iterator begin() const;

        [[nodiscard]] std::vector<SharedPlayerPtr>::const_iterator end() const;

        friend std::ostream &operator<<(std::ostream &os, PlayerManager &players);

        [[nodiscard]] bool checkAllPlayersEqual() const;

        void setButton(SharedPlayerPtr button);

        SharedPlayerPtr getButton();

        [[nodiscard]] SharedPlayerPtr getCurrentPlayer() const;

        void setCurrentPlayer(SharedPlayerPtr currentPlayer);

        template<class T>
        static PlayerManager populate(unsigned int n, float stack) {
            PlayerManager manager;
            int i = 0;
            while (i < n){
                std::ostringstream os;
                os << "Player" << i;
                manager.addPlayer(std::make_shared<T>(T(os.str(), stack)));
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
        void watch(GameVariables& variables);

    private:
        std::vector<SharedPlayerPtr> players_;

        SharedPlayerPtr current_player_;
        SharedPlayerPtr button_;
    };
}


#endif //POKERX_PLAYERMANAGER_H
