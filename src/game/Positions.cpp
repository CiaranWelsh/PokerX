/**
 * Project PokerSimulationsInCpp
 */


#include <players/CallStation.h>
#include "Positions.h"
#include <iostream>
#include <sstream>

/**
 * Positions implementation
 */
namespace game {
    Positions::Positions() = default;

    Positions::~Positions() = default;

    Positions::Positions(Positions &positions) {
        this->_positions = positions._positions;
    }
    Positions::Positions(std::vector<PlayerPtr> vec) {
        this->_positions = vec;
    }

    vector<boost::shared_ptr<Player>> Positions::getPositions() {
        return _positions;
    }

    void Positions::addPlayer(const PlayerPtr &player_ptr) {
        _positions.push_back(player_ptr);
    }

    void Positions::addPlayer(const PlayerPtr &player, int index) {
        _positions.insert(_positions.begin() + index, player);
    }

    void Positions::rotate() {
        PlayerPtr front_player = _positions[0];
        _positions.erase(_positions.begin());
        _positions.push_back(front_player);
    }

    PlayerPtr Positions::operator[](int index) {
        return _positions[index];
    }

    Positions Positions::callStations(int howMany) {
        ostringstream name;
        std::vector<PlayerPtr> positions;
        for (int i = 0; i < howMany; i++) {
            name << "player" << i;
            PlayerPtr ptr(new CallStation(name.str()));
            positions.push_back(ptr);
            name.flush();
        };
        Positions pos(positions);
        return pos;
    }


    int Positions::size() {
        return _positions.size();
    }

}