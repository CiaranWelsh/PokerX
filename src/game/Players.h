/**
 * Project PokerSimulationsInCpp
 */


#ifndef _POSITIONS_H
#define _POSITIONS_H

#include "vector"
#include "players/Player.h"
#include <boost/shared_ptr.hpp>

namespace game {
    typedef std::shared_ptr<Player> PlayerPtr;

    class Players {
    private:
        vector<PlayerPtr> players_;
        PlayerPtr current_player;
        PlayerPtr button;

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

        PlayerPtr operator[](std::string name);

        PlayerPtr& operator[](int index);

        PlayerPtr& operator=(int index);

        void previous_player();

        static Players callStations(int howMany, double start_amount = 10);

        int size();

        std::vector<PlayerPtr>::iterator begin();

        std::vector<PlayerPtr>::iterator end();

        friend ostream &operator<<(ostream &os, Players &players);

        void next_player();

        bool checkAllPlayersEqual();

        bool noPlayersPlayedThisStreet();

        Players foldStations(int howMany, double start_amount);

        void setButton(PlayerPtr button);

        PlayerPtr getButton();
    };
}
#endif //_POSITIONS_H