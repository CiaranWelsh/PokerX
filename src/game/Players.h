/**
 * Project PokerSimulationsInCpp
 */


#ifndef _POSITIONS_H
#define _POSITIONS_H

#include "vector"
#include "players/Player.h"
#include <boost/shared_ptr.hpp>

namespace game {
    typedef boost::shared_ptr<Player> PlayerPtr;

    class Players {
    private:
        vector<PlayerPtr> _positions;
    public:
        Players();

        ~Players();

        Players(Players &positions);

        explicit Players(std::vector<PlayerPtr> vec);

        vector<PlayerPtr> getPositions();

        void addPlayer(const PlayerPtr& player_ptr);

        void addPlayer(const PlayerPtr& player, int index);

        void rotate();

        PlayerPtr operator[](int index);

        static Players callStations(int howMany, double start_amount=10);

        int size();

        std::vector<PlayerPtr>::iterator begin();

        std::vector<PlayerPtr>::iterator end();

    };
}
#endif //_POSITIONS_H