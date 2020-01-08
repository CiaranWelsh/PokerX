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

        // modifies the amount to call within the gamePlay struct for the next player
        updateAmountToCall();
        cout << __FILE__ << __LINE__ << "The amount to call is: " << *gamePlay.amount_to_call << endl;
        current_event->go(gamePlay, players, dealer, *gamePlay.amount_to_call);

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
            cout << players << endl;
            cout << "output from checkAllPlayersEqual: " << players.checkAllPlayersEqual() << endl;
            // if all players are equal and all players have played this street, we can move on
            if (players.checkAllPlayersEqual() && (!players.noPlayersPlayedThisStreet())) {
                cout << "All players equal, moving on to next street: " << gamePlay.street << endl;
                current_event = &nextStreet;
                cout << "Moved on to next street: " << gamePlay.street << endl;
                cout << "Amount in the main pot is now: " << gamePlay.pot << endl;
//                gamePlay.street_ended = true;
            } else {
                // next player and go again
                cout << "All players not equal, moving on to next player" << endl;
                cout << players << endl;
                players.next_player();
                current_event = &playerAction;
            }
        }
        else if (current_event->getId() == "NextStreet") {
            cout << "else if is on NextStreet" << endl;
            current_event = &playerAction;
        }


        return current_event;
    }

    void Table::updateAmountToCall() {
        // largest bidder
        double &largest_bidder_amount = gamePlay.largest_bidder_amount;
        double &amount_player_has_in_their_pot = players.getCurrentPlayer()->pot.value;
        cout << "\n current_player: " << players.getCurrentPlayer()->getName() << endl;
        cout << "largest bidder amount: " << largest_bidder_amount << endl;
        cout << "amount player has in pot before calling: " << amount_player_has_in_their_pot << endl;
        if (amount_player_has_in_their_pot > largest_bidder_amount)
            throw errors::ValueError("This definately should not happen", __FILE__, __LINE__);
        cout << "Therefore largest bidder amount minus amount player already has in pot is "
             << largest_bidder_amount - amount_player_has_in_their_pot << endl;
        gamePlay.amount_to_call = std::make_unique<double>(largest_bidder_amount - amount_player_has_in_their_pot);
    }

}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

