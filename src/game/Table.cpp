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
            // when all players left in the game have equal bets and no players
            // have played yet this round, next street
            if (players.checkAllPlayersEqual() && (players.noPlayersPlayedThisStreet())) {
                current_event = &nextStreet;
            } else {
                if (gamePlay.street == River) {
                    players.next_player();
                    current_event = &showdown;
                } else {
                    // next player and go again
                    players.next_player();
                    current_event = &playerAction;
                }
            }
        } else if (current_event->getId() == "NextStreet") {
            current_event = &playerAction;
        } else if (current_event->getId() == "Showdown"){
            current_event = &endGame;
        }
        return current_event;
    }

    void Table::updateAmountToCall() {
        // largest bidder
        double &largest_bidder_amount = gamePlay.largest_bidder_amount;
        double &amount_player_has_in_their_pot = players.getCurrentPlayer()->pot.value;
        if (amount_player_has_in_their_pot > largest_bidder_amount)
            throw errors::ValueError("This definately should not happen", __FILE__, __LINE__);
        gamePlay.amount_to_call = std::make_unique<double>(largest_bidder_amount - amount_player_has_in_their_pot);
    }

    cards::CardCollection Table::getCommunityCards() {
        return gamePlay.communityCards;
    }

}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

