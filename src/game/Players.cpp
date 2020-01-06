/**
 * Project PokerSimulationsInCpp
 */


#include <players/CallStation.h>
#include "Players.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <dshow.h>

/**
 * Positions implementation
 */
namespace game {
    Players::Players() = default;

    Players::~Players() = default;

    Players::Players(Players &positions) {
        this->_positions = positions._positions;
    }
    Players::Players(std::vector<PlayerPtr> vec) {
        this->_positions = std::move(vec);
    }

    vector<boost::shared_ptr<Player>> Players::getPositions() {
        return _positions;
    }

    void Players::addPlayer(const PlayerPtr &player_ptr) {
        _positions.push_back(player_ptr);
    }

    void Players::addPlayer(const PlayerPtr &player, int index) {
        _positions.insert(_positions.begin() + index, player);
    }

    void Players::rotate() {
        PlayerPtr front_player = _positions[0];
        _positions.erase(_positions.begin());
        _positions.push_back(front_player);
    }

    void Players::next_player(){
        rotate();
    }

    PlayerPtr Players::operator[](int index) {
        if (_positions.empty()){
            throw errors::EmptyContainerError();
        }
        if (_positions[index] == NULL){
            throw errors::NullPointerException();
        }
        return _positions[index];
    }

    Players Players::callStations(int howMany, double start_amount) {
        std::vector<PlayerPtr> positions;
        for (int i = 0; i < howMany; i++) {
            ostringstream name;
            name << "player" << i;
            PlayerPtr ptr(new CallStation(name.str()));
            ptr->stack = start_amount;
            positions.push_back(ptr);
            name.flush();
        };
        Players pos(positions);
        return pos;
    }


    int Players::size() {
        return _positions.size();
    }

    std::vector<PlayerPtr>::iterator Players::begin() {
        return _positions.begin();
    }

    std::vector<PlayerPtr>::iterator Players::end() {
        return _positions.end();
    }

    ostream &operator<<(ostream &os, Players &players) {
        os << "[";
        for (int i = 0; i < players.size(); i++) {
            if (i == players.size() - 1)
                os << *players[i] << "]";
            else
                os << *players[i] << ", ";
        }
        os << "]";
        return os;
    }

    PlayerPtr Players::getCurrentPlayer() {
        return current_player;
    }


}





