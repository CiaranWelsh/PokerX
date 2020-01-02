/**
 * Project PokerSimulationsInCpp
 */


#ifndef _TABLE_H
#define _TABLE_H

#include "Pot.h"
#include "Dealer.h"
#include "Players.h"
#include "Street.h"

namespace game {
    class Table {
    private:
//        State current_state;
        Pot pot;
        double small_blind = 0.5;
        double big_blind = 1.0;
        Street street = Preflop;
        PlayerPtr current_player = players[0]; //Player 0 is the btn
        bool begin_street = true;
    public:

        void init();

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


    };
}
#endif //_TABLE_H