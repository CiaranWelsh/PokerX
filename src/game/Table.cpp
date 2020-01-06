#ifndef POKERSIMULATIONSINCPP_TABLE_CPP
#define POKERSIMULATIONSINCPP_TABLE_CPP

#include "Table.h"
#include "errors.h"

namespace game {
    void Table::resetPot() {
        gamePlay.pot.value = 0;
    }

    Table::Table(Players &players) {
        this->players = players;
        current_player = players[0];
    }

    Table::Table(Table &table) {
        small_blind = table.small_blind;
        big_blind = table.big_blind;
        players = table.players;
        dealer = table.dealer;
        current_player = table.current_player;
        gamePlay = table.gamePlay;
    }

//    Table& Table::operator=(const Table& other){
//        *this = other;
//        return *this;
//    }

    void Table::setSmallBlind(double sb) {
        small_blind = sb;
    }

    void Table::setBigBlind(double bb) {
        big_blind = bb;
    }

    double Table::getSmallBlind() {
        return small_blind;
    }

    double Table::getBigBlind() {
        return big_blind;
    }

    Table::Table() {
        reset();
    };

    Table::~Table() = default;

    Table Table::CallStationTable(int howMany, double start_amount) {
        Players players;
        players = Players::callStations(howMany);
        Table table(players);
        return table;
    }

    void Table::reset() {
        gamePlay.street = Preflop;
        gamePlay.pot = 0.0;
    }

    void Table::rotate_players() {
        players.rotate();
    }


    events::Event *Table::step() {
        if (!current_event)
            throw errors::NullPointerException();
        std::string copy_of_current_event_id = current_event->getId();

        // first try this, catch exceptions and try again with the other arguments
        current_event->go(gamePlay);


        if (current_event->getId() == "BeginGame") {
            current_event = &rotatePlayers;
        }
        else if (current_event->getId() == "RotatePlayers")
            current_event = &postSmallBlind;

        if (copy_of_current_event_id == current_event->getId())
            throw errors::EventNotChangedAfterStepError();

        return current_event;
    }


}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

