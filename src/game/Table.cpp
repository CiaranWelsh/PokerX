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
        cout << "Resetting" << endl;
        // just create new game play obj to reset
        Deck new_deck;
        this->dealer.resetDeck();
        GamePlay gamePlay2{};
        gamePlay = gamePlay2;
        for (auto player : players) {
            player->reset();
        }

        current_event = &beginGame;

    }

    events::Event *Table::step() {
        if (!current_event)
            throw errors::NullPointerException("current_event ptr is nullptr. Whoops. ", __FILE__, __LINE__);

        // modifies the amount to call within the gamePlay struct for the next player
        updateAmountToCall();
        current_event->go(gamePlay, players, dealer, *gamePlay.amount_to_call);

        // Switch current event
        if (current_event->getId() == "BeginGame") {
            cout << "Here 1" << endl;
            current_event = &resetGame;
        } else if (current_event->getId() == "ResetGame") {
            cout << "Here 2" << endl;
            current_event = &rotatePlayers;
        } else if (current_event->getId() == "RotatePlayers") {
            cout << "Here 3" << endl;
            current_event = &postSmallBlind;
        } else if (current_event->getId() == "PostSmallBlind") {
            cout << "Here 4" << endl;
            current_event = &postBigBlind;
        } else if (current_event->getId() == "PostBigBlind") {
            cout << "Here 5" << endl;
            current_event = &dealHoleCards;
        } else if (current_event->getId() == "DealHoleCards") {
            cout << "Here 6" << endl;
            current_event = &playerAction;
        } else if (current_event->getId() == "PlayerAction") {
            cout << "Here 7" << endl;
            // when all players left in the game have equal bets and no players
            // have played yet this round, next street
            if (players.checkAllPlayersEqual() && (players.noPlayersPlayedThisStreet())) {
                cout << "Here 8" << endl;
                current_event = &nextStreet;
            } else {
                if (gamePlay.street == River) {
                    cout << "Here 9" << endl;
                    players.next_player();
                    current_event = &showdown;
                } else {
                    cout << "Here 10" << endl;
                    // next player and go again
                    players.next_player();
                    current_event = &playerAction;
                }
            }
        } else if (current_event->getId() == "NextStreet") {
            cout << "Here 11" << endl;
            current_event = &playerAction;
        } else if (current_event->getId() == "Showdown"){
            cout << "Here 12" << endl;
            current_event = &endGame;}
        else if (current_event->getId() == "EndGame"){
            cout << "back to begining" << endl;
            current_event = &beginGame;
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

