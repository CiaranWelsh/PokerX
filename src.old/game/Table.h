/**
 * Project PokerSimulationsInCpp
 */


#ifndef POKERSIMULATIONSINCPP_TABLE_H
#define POKERSIMULATIONSINCPP_TABLE_H

#include "Pot.h"
#include "Dealer.h"
#include "Players.h"
#include "Street.h"
#include "GamePlay.h"
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostBigBlind.h>
#include <events/player_event/PostSmallBlind.h>
#include <events/player_event/PlayerAction.h>
#include <events/dealer_event/DealHoleCards.h>
#include <events/time_event/BeginGame.h>
#include <events/time_event/EndGame.h>
#include <events/time_event/NextStreet.h>
#include <events/dealer_event/Showdown.h>
#include <events/dealer_event/ResetGame.h>
#include "events/EventPtr.h"
#include "utils/Log.h"

namespace game {

    // some forward declarations

    class Table {
    public:
        // attributes
        Dealer dealer;
        Players players;
        GamePlay gamePlay;

        // events
        events::BeginGame beginGame;
        events::EndGame endGame;
        events::ResetGame resetGame;
        events::RotatePlayers rotatePlayers;
        events::PostSmallBlind postSmallBlind;
        events::PostBigBlind postBigBlind;
        events::DealHoleCards dealHoleCards;
        events::PlayerAction playerAction;
        events::NextStreet nextStreet;
        events::Showdown showdown;

        // current event
        events::Event *current_event = &beginGame;

        void reset();

        Table();

        explicit Table(Players &players);

        Table(Table &table);

        Table &operator=(const Table &other);

        ~Table();

        static Table CallStationTable(int howMany, double start_amount = 10.0);

        events::Event *step();

        void updateAmountToCall();

        cards::CardCollection getCommunityCards();

    };
}
#endif //POKERSIMULATIONSINCPP_TABLE_H