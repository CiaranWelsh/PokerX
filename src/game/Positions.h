/**
 * Project PokerSimulationsInCpp
 */


#ifndef _POSITIONS_H
#define _POSITIONS_H

#include "vector"
#include "players/Player.h"

namespace game {
    class Positions {
    private:
        vector<Player*> _positions;
    public:
        Positions();

        ~Positions();

        Positions(Positions &positions);

        vector<Player *> getPositions();

        void addPlayer(Player *player);

        void addPlayer(Player *player, int index);

        void rotate();

        Player *operator[](int index);


    };
}
#endif //_POSITIONS_H