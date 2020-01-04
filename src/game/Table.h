/**
 * Project PokerSimulationsInCpp
 */


#ifndef _TABLE_H
#define _TABLE_H

#include "Pot.h"
#include "Dealer.h"
#include "Players.h"
#include "Street.h"
//#include "events/Event.h"
//#include "events/time_event/BeginGame.h"

namespace game {
    class Table {
    private:
        double small_blind = 0.5;
        double big_blind = 1.0;
        PlayerPtr current_player; //Player 0 is the btn

    public:

        // boolean flags marking poker landmarks
        bool game_started = false;
        bool game_ended = false;
        bool small_blind_posted = false;
        bool big_blind_posted = false;
        bool ante_posted = false;
        bool dealt_hole_cards = false;
        bool preflop_done = false;
        bool flop_done = false;
        bool turn_done = false;
        bool river_done = false;
        bool dealt_preflop = false;
        bool dealt_flop = false;
        bool dealt_turn = false;
        bool dealt_river = false;
        bool showdown = false;

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

        static Table CallStationTable(int howMany, double start_amount=10.0);

        Dealer dealer;
        Players players;

        void rotate_players();

//        void setEvent(events::Event* event);

        void step();

//        events::Event* current_event = nullptr;
        Street street = Preflop;
        Pot pot;
    };
}
#endif //_TABLE_H