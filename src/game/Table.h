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
#include <events/time_event/BeginGame.h>
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostBigBlind.h>
#include <events/player_event/PostSmallBlind.h>
#include <events/time_event/EndGame.h>
#include "events/EventPtr.h"

namespace game {

    // some forward declarations

    class Table {
    public:
        // attributes
        Dealer dealer;
        Players players;
        PlayerPtr current_player;
        GamePlay gamePlay;

        // events
        events::BeginGame beginGame;
        events::EndGame endGame;
        events::RotatePlayers rotatePlayers;
        events::PostSmallBlind postSmallBlind;
        events::PostBigBlind postBigBlind;

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

    };
}
#endif //POKERSIMULATIONSINCPP_TABLE_H