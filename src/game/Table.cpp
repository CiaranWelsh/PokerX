#ifndef POKERSIMULATIONSINCPP_TABLE_CPP
#define POKERSIMULATIONSINCPP_TABLE_CPP

#include "Table.h"
#include "Errors.h"

namespace game {

    Table::Table(Players &players) {
        this->players = players;
    }

    Table::Table(Table &table) {
        players = table.players;
        dealer = table.dealer;
        gamePlay = table.gamePlay;
    }

    Table &Table::operator=(const Table &other) {
        players = other.players;
        dealer = other.dealer;
        gamePlay = other.gamePlay;
        return *this;
    }


    Table::Table() {
        reset();
    }

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
            throw errors::NullPointerException("current_event ptr is nullptr. Whoops. ", __FILE__, __LINE__);
//        std::string copy_of_current_event_id = current_event->getId();

        double amount_to_call = getAmountToCall();
        current_event->go(gamePlay, players, dealer, amount_to_call);

        // Switch current event
        if (current_event->getId() == "BeginGame") {
            current_event = &rotatePlayers;
        } else if (current_event->getId() == "RotatePlayers") {
            current_event = &postSmallBlind;
        } else if (current_event->getId() == "PostSmallBlind") {
            current_event = &postBigBlind;
        } else if (current_event->getId() == "PostBigBlind") {
            current_event = &dealHoleCards;
        } else if (current_event->getId() == "DealHoleCards") {
            current_event = &playerAction;
        } else if (current_event->getId() == "PlayerAction") {
            // when all players left in the game have equal bets, next street
            if (gamePlay.all_players_equal) {
                current_event = &nextStreet;
            } else {
                // next player and go again
                players.next_player();
                current_event = &playerAction;
            }
        }

        return current_event;
    }

    double Table::getAmountToCall() {
        // largest bidder
        double &largest_bidder_amount = gamePlay.largest_bidder_amount;
        double &amount_player_has_in_their_pot = players.getCurrentPlayer()->pot.value;
        cout << "largest bidder amount: " << largest_bidder_amount << endl;
        cout << "amount player has in pot: " << amount_player_has_in_their_pot << endl;
        if (amount_player_has_in_their_pot > largest_bidder_amount)
            throw errors::ValueError("This definately should not happen", __FILE__, __LINE__);
        return largest_bidder_amount - amount_player_has_in_their_pot;
    }

}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

