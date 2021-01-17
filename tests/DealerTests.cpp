//
// Created by CiaranWelsh on 01/01/2020.
//

#include <game/Dealer.h>
#include <game/Table.h>
#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "game/Pot.h"
#include "game/Players.h"
#include "players/CallStation.h"

using namespace std;
using namespace game;

TEST(DealerTests, testDealCard) {
    Dealer dealer;
    Card card = dealer.dealCard();
    ASSERT_EQ(dealer.deckSize(), 51);
}


TEST(DealerTests, dealFlop) {
    Dealer dealer;
    CardCollection cards = dealer.dealFlop();
    ASSERT_EQ(dealer.deckSize(), 48);
}

TEST(DealerTests, dealTurn) {
    Dealer dealer;
    Card card = dealer.dealTurn();
    ASSERT_EQ(dealer.deckSize(), 50);
}

TEST(DealerTests, dealRiver) {
    Dealer dealer;
    Card card = dealer.dealRiver();
    ASSERT_EQ(dealer.deckSize(), 50);
}

TEST(DealerTests, dealHoleCards) {
    Players players;
    players = Players::callStations(9);
    Table table(players);
    table.dealer.dealHoleCards(table.players);
    int count = 0;
    for (auto i: table.players) {
        count += i->holeCards.size();
    }
    int expected = 18;
    ASSERT_EQ(expected, count);
}










