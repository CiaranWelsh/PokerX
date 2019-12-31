/**
 * Project PokerSimulationsInCpp
 */


#include <players/CallStation.h>
#include "Positions.h"

/**
 * Positions implementation
 */
namespace game {
    Positions::Positions() = default;

    Positions::~Positions() = default;

    Positions::Positions(Positions &positions) {
        this->_positions = positions._positions;
    }

    vector<Player *> Positions::getPositions() {
        return _positions;
    }

    void Positions::addPlayer(Player *player) {
        _positions.push_back(player);
    }

    void Positions::addPlayer(Player *player, int index) {
        _positions.insert(_positions.begin() + index, player);
    }

    void Positions::rotate() {
        Player front_player = *_positions[0];
        _positions.erase(_positions.begin());
        _positions.push_back(&front_player);
    }

    /*
     * This getter function needs to have a factory design
     * of some variety. I intend to add more players later,
     * and I dont know how many or their identity. Therefore
     * instead of hard coding a bunch of if else s5tatements,
     * find a way of implementing a design that means any player can be
     * added to a position.
     */
    Player* Positions::operator[](int index) {
        if (_positions[index]->getType() == "CallStation")
            CallStation cs(*_positions[index]);
            return *cs;
    }
}