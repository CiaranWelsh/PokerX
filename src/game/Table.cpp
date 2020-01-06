#ifndef POKERSIMULATIONSINCPP_TABLE_CPP
#define POKERSIMULATIONSINCPP_TABLE_CPP

#include "Table.h"
#include "errors.h"

namespace game {

    Table::Table(Players &players) {
        this->players = players;
         current_player = players.getCurrentPlayer();
    }

    Table::Table(Table &table) {
        players = table.players;
        dealer = table.dealer;
        gamePlay = table.gamePlay;
        current_player = table.current_player;
    }

    Table &Table::operator=(const Table &other) {
        players = other.players;
        dealer = other.dealer;
        gamePlay = other.gamePlay;
        current_player = other.current_player;
        return *this;
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

    events::Event *Table::step() {
        if (!current_event)
            throw errors::NullPointerException();
        std::string copy_of_current_event_id = current_event->getId();

        // first try this, catch exceptions and try again with the other arguments
        current_event->go(gamePlay);

        if (current_event->getId() == "BeginGame") {
            current_event = &rotatePlayers;
        } else if (current_event->getId() == "RotatePlayers") {
            current_event = &postSmallBlind;
            players.next_player();
        }
        else if (current_event->getId() == "PostSmallBlind") {
            current_event = &postBigBlind;
            players.next_player();
        }
        else if (current_event->getId() == "PostBigBlind") {
            current_event = &endGame;
            players.next_player();
        }


        if (copy_of_current_event_id == current_event->getId())
            throw errors::EventNotChangedAfterStepError();


        return current_event;
    }


}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

