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
            current_event = &resetGame;
            cout << "Resetting game"<< endl;
        } else if (current_event->getId() == "ResetGame") {
            current_event = &rotatePlayers;
            cout << "Rotating players"<< endl;
        } else if (current_event->getId() == "RotatePlayers") {
            current_event = &postSmallBlind;
            cout << "Posting small blind"<< endl;
        } else if (current_event->getId() == "PostSmallBlind") {
            current_event = &postBigBlind;
            cout << "Posting big blind"<< endl;
        } else if (current_event->getId() == "PostBigBlind") {
            current_event = &dealHoleCards;
            cout << "Dealing hole cards"<< endl;
        } else if (current_event->getId() == "DealHoleCards") {
            current_event = &playerAction;
            cout << "PlayerAction"<< endl;
        } else if (current_event->getId() == "PlayerAction") {
            // when all players left in the game have equal bets and no players
            // have played yet this round, next street
            if (players.checkAllPlayersEqual() && (players.noPlayersPlayedThisStreet())) {
                current_event = &nextStreet;
                cout << "Moving to the next street "<< endl;
            } else {
                if (gamePlay.street == River) {
                    players.next_player();
                    current_event = &showdown;
                    cout << "Switching to showdown"<< endl;
                } else {
                    // next player and go again
                    players.next_player();
                    current_event = &playerAction;
                    cout << "Switching to next player"<< endl;
                }
            }
        } else if (current_event->getId() == "NextStreet") {
            current_event = &playerAction;
            cout << " "<< endl;
        } else if (current_event->getId() == "Showdown") {
            current_event = &endGame;
            cout << "Showdown complete" << endl;
            cout << current_event->getId() << endl;
        }
        else if (current_event->getId() == "EndGame"){
            cout << "before swap"<< endl;
            current_event = &beginGame;
            cout << "Game ended and set to begin again" << endl;
        }
        return current_event;
    }

    void Table::updateAmountToCall() {
        // largest bidder
        double &largest_bidder_amount = gamePlay.largest_bidder_amount;
        double &amount_player_has_in_their_pot = players.getCurrentPlayer()->pot.value;
        gamePlay.amount_to_call = std::make_unique<double>(largest_bidder_amount - amount_player_has_in_their_pot);
    }

    cards::CardCollection Table::getCommunityCards() {
        return gamePlay.communityCards;
    }

}


#endif// POKERSIMULATIONSINCPP_TABLE_CPP

