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
        PlayerPtr current_player;

    public:
        Players();

        ~Players();

        Players(Players const &positions);

        PlayerPtr getCurrentPlayer();

        explicit Players(std::vector<PlayerPtr> vec);

        vector<PlayerPtr> getPositions();

        void addPlayer(const PlayerPtr &player_ptr);

        void addPlayer(const PlayerPtr &player, int index);

        void rotate();

        void previous_player();

        PlayerPtr operator[](int index);

        static Players callStations(int howMany, double start_amount = 10);

        int size();

        std::vector<PlayerPtr>::iterator begin();

        std::vector<PlayerPtr>::iterator end();

        friend ostream &operator<<(ostream &os, Players &players);

        void next_player();

        bool checkAllPlayersEqual();

        bool noPlayersPlayedThisStreet();
    };
}
#endif //_POSITIONS_H