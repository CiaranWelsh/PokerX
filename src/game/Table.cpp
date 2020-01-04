#include <events/time_event/BeginGame.h>
#include "Table.h"
#include "errors.h"

namespace game {
    void Table::resetPot() {
        pot.value = 0;
    }

    void Table::setPositions() {

    }

    Table::Table(Players &players) {
        this->players = players;
        current_player = players[0];
    }

    Table::Table(Table &table) {
        small_blind = table.small_blind;
        big_blind = table.big_blind;
        pot = table.pot;
        players = table.players;
        dealer = table.dealer;
    }

    void Table::setSmallBlind(double sb) {
        small_blind = sb;
    }

    void Table::setBigBlind(double bb) {
        big_blind = bb;
    }

    double Table::getSmallBlind() {
        return small_blind;
    }

    double Table::getBigBlind() {
        return big_blind;
    }

    Table::Table() {
        reset();
//        events::BeginGame beginGame;
//        setEvent(&beginGame);
    };

    Table::~Table() = default;

    Table Table::CallStationTable(int howMany, double start_amount) {
        Players players;
        players = Players::callStations(howMany);
        Table table(players);
        return table;
    }

    void Table::reset() {
        street = Preflop;
        pot = 0.0;
    }

    void Table::rotate_players() {
        players.rotate();
    }

//    void Table::setEvent(events::Event *event) {
//        current_event = event;
//    }

//    void Table::step() {
//        if (!current_event)
//            throw errors::NullPointerException();
//        current_event->go();
//    }


}












