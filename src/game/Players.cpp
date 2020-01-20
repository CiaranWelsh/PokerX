/**
 * Project PokerSimulationsInCpp
 */


#include <players/CallStation.h>
#include "Players.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <dshow.h>
#include <utils/EqualityChecker.h>
#include "players/FoldStation.h"
/**
 * Positions implementation
 */
namespace game {
    Players::Players() = default;

    Players::~Players() = default;

    Players::Players(Players const &positions) {
        this->players_ = positions.players_;
        current_player = players_[0];
    }

    Players::Players(std::vector<PlayerPtr> vec) {
        this->players_ = std::move(vec);
        current_player = players_[0];
    }

    vector<std::shared_ptr<Player>> Players::getPositions() {
        return players_;
    }

    void Players::addPlayer(const PlayerPtr &player_ptr) {
        players_.push_back(player_ptr);
    }

    void Players::addPlayer(const PlayerPtr &player, int index) {
        players_.insert(players_.begin() + index, player);
    }

    void Players::rotate() {
        PlayerPtr front_player = players_[0];
        players_.erase(players_.begin());
        players_.push_back(front_player);
        // must update current_player field
        current_player = players_[0];
        /*
         * Makes this method recursive. Keep rotating until you find a
         * player who is still in the game. All players should be inplace=true
         * when the game begins
         */
        if (!current_player->inplay) {
            rotate();
        }
    }

    void Players::previous_player() {
        PlayerPtr back_player = players_[size() - 1];
        players_.erase(players_.begin() + size() - 1);
        players_.insert(players_.begin(), back_player);
        current_player = players_[0];
        if (!current_player->inplay)
            previous_player();
    }

    void Players::next_player() {
        rotate();
    }

    PlayerPtr& Players::operator[](int index) {
        if (players_.empty()) {
            throw errors::EmptyContainerError("You cannot get access to players "
                                              "as there are not players yet.", __FILE__, __LINE__);
        }
        if (players_[index] == nullptr) {
            throw errors::NullPointerException("In Players::operator[], index is a nullptr", __FILE__, __LINE__);
        }
        return players_[index];
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


    Players Players::foldStations(int howMany, double start_amount) {
        std::vector<PlayerPtr> positions;
        for (int i = 0; i < howMany; i++) {
            ostringstream name;
            name << "player" << i;
            PlayerPtr ptr(new FoldStation(name.str()));
            ptr->stack = start_amount;
            positions.push_back(ptr);
            name.flush();
        }
        Players pos(positions);
        return pos;
    }

    PlayerPtr& Players::operator=(int index) {
        return players_[index];
    }

    PlayerPtr Players::operator[](std::string name){
        PlayerPtr x;
        for (const PlayerPtr& player : players_){
            if (player->getName() == name)
                x = player;
        }
        if (x == nullptr)
            throw errors::NullPointerException("Did not find a player with that name", __FILE__, __LINE__);
        return x;
    }

    int Players::size() {
        return players_.size();
    }

    std::vector<PlayerPtr>::iterator Players::begin() {
        return players_.begin();
    }

    std::vector<PlayerPtr>::iterator Players::end() {
        return players_.end();
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
        std::vector<double> amounts;
        for (PlayerPtr player : players_) {
            if (player->inplay)
                amounts.push_back(player->pot.value);
        }
        return utils::EqualityChecker<double>(amounts);
    }

    /*
     * If none of the players played in this street, we proceed
     * with another round of betting.
     */
    bool Players::noPlayersPlayedThisStreet() {
        std::vector<bool> vec;
        for (PlayerPtr player : players_)
            vec.push_back(player->played_this_street);
        return utils::EqualityChecker<bool>(vec);
    }

}





