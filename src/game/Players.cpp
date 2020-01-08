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

    Players::Players(Players const &positions) {
        this->_positions = positions._positions;
        current_player = _positions[0];
    }

    Players::Players(std::vector<PlayerPtr> vec) {
        this->_positions = std::move(vec);
        current_player = _positions[0];
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
        cout << "Players::rotate function has been called "<<endl;

        PlayerPtr front_player = _positions[0];
        _positions.erase(_positions.begin());
        _positions.push_back(front_player);
        // must update current_player field
        current_player = _positions[0];
        /*
         * Makes this method recursive. Keep rotating until you find a
         * player who is still in the game. All players should be inplace=true
         * when the game begins
         */
        if (!current_player->inplay)
            rotate();
    }

    void Players::previous_player() {
        PlayerPtr back_player = _positions[size() - 1];
        _positions.erase(_positions.begin() + size() - 1);
        _positions.insert(_positions.begin(), back_player);
        current_player = _positions[0];
        if (!current_player->inplay)
            previous_player();

    }

    void Players::next_player() {
        rotate();
    }

    PlayerPtr Players::operator[](int index) {
        if (_positions.empty()) {
            throw errors::EmptyContainerError("You cannot get access to players "
                                              "as there are not players yet.", __FILE__, __LINE__);
        }
        if (_positions[index] == nullptr) {
            throw errors::NullPointerException("In Players::operator[], index is a nullptr", __FILE__, __LINE__);
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
        }
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
        if (current_player == nullptr) {
            throw errors::NullPointerException("Cannot get current player as "
                                               "it is a nullptr", __FILE__, __LINE__);
        }
        return current_player;
    }

    bool Players::checkAllPlayersEqual() {
        bool equal = true;
        for (int i = 1; i < size(); i++) {
            //todo overload Pot == and != operators
            if (_positions[i]->pot.value != current_player->pot.value) {
                equal = false;
                break;
            } else {
                next_player();
            }
        }
        return equal;
    }


}





