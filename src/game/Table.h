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
#include "events/EventPtr.h"

namespace game {

    // some forward declarations

    class Table {
    private:
        double small_blind = 0.5;
        double big_blind = 1.0;
        //Player 0 is the btn

    public:
        // attributes
        Dealer dealer;
        Players players;
        PlayerPtr current_player;
        GamePlay gamePlay;

        // events
        events::BeginGame beginGame;
        events::RotatePlayers rotatePlayers;
        events::PostSmallBlind postSmallBlind;
//        events::PostBigBlind postBigBlind;

        // current event
        events::Event *current_event = &beginGame;

        void reset();

        Table();

        explicit Table(Players &players);

        Table(Table &table);

        ~Table();

        void resetPot();

        void setPositions();

        void setSmallBlind(double sb);

        void setBigBlind(double bb);

        double getSmallBlind();

        double getBigBlind();

        static Table CallStationTable(int howMany, double start_amount = 10.0);

        void rotate_players();

//        Table& operator=(const Table& other);

//        void setEvent(events::Event* event);

        events::Event * step();

//        events::Event *beginGame() {
//            reset();
//            beginGame.go(gamePlay.game_started);
//            current_event = &rotatePlayers;
//        }

    };
}
#endif //POKERSIMULATIONSINCPP_TABLE_H