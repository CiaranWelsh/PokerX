#include "Table.h"


namespace game {
    void Table::resetPot() {
        pot.value = 0;
    }

    void Table::setPositions() {

    }

    Table::Table(Players &players) {
        this->players = players;
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

    Table::Table() = default;

    Table::~Table() = default;

    Table Table::CallStationTable(int howMany, double start_amount) {
        Players players;
        players = Players::callStations(howMany);
        Table table(players);
        return table;
    }

    void Table::init() {
        street = Preflop;
        pot = 0.0;
    }

    void Table::rotate_players() {
        players.rotate();
    }
}












