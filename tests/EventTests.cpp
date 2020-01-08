//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/Table.h>
#include <events/time_event/BeginGame.h>
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostSmallBlind.h>
#include <events/player_event/PostBigBlind.h>
#include "gtest/gtest.h"
#include "iostream"
#include "events/Event.h"
#include "game/Table.h"
#include "game/Players.h"
#include "game/Street.h"

using namespace std;
using namespace events;

class EventTests : public ::testing::Test {
protected:
    game::Players players;
    game::Table table;

    void SetUp() {
        players = game::Players::callStations(9);
        game::Table table2(players);
        table = table2;
    }
};


/*
 * BeginGame tests
 */

TEST_F(EventTests, TestInheritance) {
    BeginGame beginGame;
    std::string expected = "BeginGame";
    ASSERT_EQ(expected, beginGame.getId());
}


TEST_F(EventTests, TestGetId) {
    std::string expected = "BeginGame";
    std::string actual = table.current_event->getId();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestGameStartedFlagIsSwitched) {
    ASSERT_FALSE(table.gamePlay.game_started);
    table.step();
    ASSERT_TRUE(table.gamePlay.game_started);
}


TEST_F(EventTests, TestCorrectStreet) {
    ASSERT_TRUE(table.gamePlay.street == game::Preflop);
}


TEST_F(EventTests, TestEventSwitchedToRotatePlayers) {
    table.step();
    std::string expected = "RotatePlayers";
    std::string actual = table.current_event->getId();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestRotatePlayersWorked) {
    table.step(); // begin game, switch active event to RotatePlayers
    cout << endl;
    cout << table.players << endl;
    table.step(); // Use the RotatePlayers.go method.
    cout << table.players << endl;
    std::string expected = "player1";
    std::string actual = table.players.getCurrentPlayer()->getName();
    ASSERT_EQ(expected, actual);
}


/*
 * RotatePlayer tests
 */
TEST_F(EventTests, TestRotatePlayers) {
    game::Table table;
    RotatePlayers rotatePlayers;
    rotatePlayers.go(players);
    game::PlayerPtr player0 = players[0];
    std::string expected = "player1";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}


/*
 * PostSmallBlind tests
 */
TEST_F(EventTests, TestPostSmallBlindPlayerPtrNotEmpty) {
    PostSmallBlind postSmallBlind;
    game::PlayerPtr player0 = players[0];
    std::string expected = "player0";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}


TEST_F(EventTests, TestPostSmallBlind) {
    game::PlayerPtr player0 = players[0];
    PostSmallBlind postSmallBlind;
    table.updateAmountToCall();
    postSmallBlind.go(table.gamePlay, table.players, table.dealer, *table.gamePlay.amount_to_call);
    ASSERT_TRUE(player0->stack == 9.5);
    ASSERT_TRUE(player0->pot == 0.5);
}



/*
 * PostBigBlind tests
 */
TEST_F(EventTests, TessmatPostBigBlindPlayerPtrNotEmpty) {
    PostBigBlind postBigBlind;
    game::PlayerPtr player0 = players[0];
    std::string expected = "player0";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestPostBigBlind) {
    // Big blind is 0.5
    game::PlayerPtr player0 = players[0];
    table.updateAmountToCall();
    double amount = *table.gamePlay.amount_to_call;
    PostBigBlind postBigBlind;
    postBigBlind.go(table.gamePlay, table.players, table.dealer, amount);
    ASSERT_TRUE(player0->stack == 9.0);
    ASSERT_TRUE(player0->pot == 1.0);
}

/*
 * DealHoleCard tests
 */
TEST_F(EventTests, TestDealHoleCards) {
    table.step(); //begin game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    HoleCards holeCardsBefore = table.players.getCurrentPlayer()->holeCards;
    ASSERT_NE(2, holeCardsBefore.size());
    table.step(); //deal
    HoleCards holeCardsAfter = table.players.getCurrentPlayer()->holeCards;
    ASSERT_EQ(2, holeCardsAfter.size());
}

TEST_F(EventTests, TestDealHoleCardsOtherPlayersAlsoDealtCards) {
    table.step(); //begin game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    table.step(); //deal
    HoleCards holeCardsAfter = table.players[5]->holeCards;
    ASSERT_EQ(2, holeCardsAfter.size());
}

TEST_F(EventTests, TestNumberOfCardsLeft) {
    table.step(); //begin game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    table.step(); //deal
    Deck cards_left = table.dealer.getDeck();
    int expected = 52 - 9 * 2 - 1; // 52 cards, 9 players 2 cards each minus 1 for the discarded
    ASSERT_EQ(expected, cards_left.size());
}

TEST_F(EventTests, TestCurrentPlayerPtrPointsAtUTGPlayer) {
    table.step(); //begin game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    table.step(); //deal
    game::PlayerPtr player = table.players.getCurrentPlayer();
    std::string expected = "player2";
    ASSERT_EQ(expected, player->getName());
}

TEST_F(EventTests, Testx) {
    table.step(); //begin game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    table.step(); //deal
    table.step(); //Player 2 UTG1 to act
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step(); // player 8 to act
    table.step(); // back to small blind player1
    cout << "All players equal? " << table.gamePlay.all_players_equal << endl;
    table.step();
    cout << "All players equal? " << table.gamePlay.all_players_equal << endl;
//    table.step();
//    game::PlayerPtr player = table.players.getCurrentPlayer();
//    std::string expected = "player2";
//    ASSERT_EQ(expected, player->getName());
}


TEST_F(EventTests, TestGamePlay) {
    cout << endl;
    while (!table.gamePlay.game_ended) {
        table.step();
        cout << "Current player: " << table.players.getCurrentPlayer()->getName();
        cout << ", Current event: " << table.current_event->getId();
        cout << ", Event description: " << table.current_event->getDescription() << endl;
    }
}


















