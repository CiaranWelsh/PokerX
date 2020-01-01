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

    class Positions {
    private:
        vector<PlayerPtr> _positions;
    public:
        Positions();

        ~Positions();

        Positions(Positions &positions);

        explicit Positions(std::vector<PlayerPtr> vec);

        vector<boost::shared_ptr<Player>> getPositions();

        void addPlayer(const PlayerPtr& player_ptr);

        void addPlayer(const PlayerPtr& player, int index);

        void rotate();

        PlayerPtr operator[](int index);

        static Positions callStations(int howMany);

        int size();


    };
}
#endif //_POSITIONS_H