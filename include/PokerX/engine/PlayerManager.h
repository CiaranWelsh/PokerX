//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_PLAYERMANAGER_H
#define POKERX_PLAYERMANAGER_H

#include <vector>
#include "PokerX/engine/Player.h"
#include <iostream>

namespace pokerx {

    class PlayerManager {

    public:

        PlayerManager() = default;

        void addPlayer(Player* player);

        void rotate();

        Player* operator[](const std::string& name);

        Player* &operator[](int index);

        int size();

        std::vector<Player*>::iterator begin();

        std::vector<Player*>::iterator end();

        friend std::ostream &operator<<(std::ostream &os, PlayerManager &players);

        bool checkAllPlayersEqual();

        void setButton(Player* button);

        Player* getButton();
        [[nodiscard]] Player *getCurrentPlayer() const;

        void setCurrentPlayer(Player *currentPlayer);
    private:
        std::vector<Player*> players_;

        Player* current_player_;
        Player* button_;
    };
}


#endif //POKERX_PLAYERMANAGER_H
