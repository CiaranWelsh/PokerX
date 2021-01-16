//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/Table.h>
#include <events/time_event/BeginGame.h>
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostSmallBlind.h>
#include <events/player_event/PostBigBlind.h>
#include <eval/Evaluator.h>
#include <players/FoldStation.h>
#include <players/Checker.h>
#include <players/Raiser.h>
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
    game::Players playersWithFolder;
    game::Table tableWithFolder;

    void SetUp() {
        players = game::Players::callStations(9);
        game::Table table2(players);
        table = table2;
        players = game::Players::callStations(9);
        playersWithFolder = players;
        FoldStation foldStation("folder");
        playersWithFolder[5] = std::make_shared<FoldStation>(foldStation);
        game::Table tableWithFolder2(playersWithFolder);
        tableWithFolder = tableWithFolder2;
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
    std::string expected = "ResetGame";
    std::string actual = table.current_event->getId();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestRotatePlayersWorked) {
    cout << table.players << endl;
    cout << table.current_event->getId() << endl;
    table.step(); // begin game, switch active event to RotatePlayers
    cout << table.current_event->getId() << endl;
    table.step(); // Use the RotatePlayers.go method.
    cout << table.current_event->getId() << endl;
    cout << table.players << endl;
//    cout << endl;
//    cout << table.players << endl;
//    std::string expected = "player1";
//    std::string actual = table.players.getCurrentPlayer()->getName();
//    ASSERT_EQ(expected, actual);
}


/*
 * RotatePlayer tests
 */
TEST_F(EventTests, TestRotatePlayers) {
    table = game::Table::CallStationTable(9);
    RotatePlayers rotatePlayers;
    rotatePlayers.go(table.gamePlay, table.players, table.dealer, table.gamePlay.small_blind);
    game::PlayerPtr player0 = table.players[0];
    std::string expected = "player1";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}


/*
 * PostSmallBlind tests
 */
TEST_F(EventTests, TestPostSmallBlind1) {
    table.step(); // begin
    table.step(); // reset game
    table.step(); // rotate
    table.step(); // SB
    game::PlayerPtr player = table.players[0];
    double actual = table.players["player1"]->stack;
    double expected = 9.5;
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestPostSmallBlind2) {
    table.step(); // begin
    table.step(); // reset game
    table.step(); // rotate
    table.step(); // SB
    game::PlayerPtr player = table.players[0];
    double actual = table.players["player1"]->pot;
    double expected = 0.5;
    ASSERT_EQ(expected, actual);
}


TEST_F(EventTests, TestPostSmallBlind3) {
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
    table.step(); //reset game
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
    table.step(); // reset game
    table.step(); //rotation
    table.step(); //small blind
    table.step(); //big blind
    table.step(); //deal
    HoleCards holeCardsAfter = table.players[5]->holeCards;
    ASSERT_EQ(2, holeCardsAfter.size());
}

TEST_F(EventTests, TestNumberOfCardsLeft) {
    table.step(); //begin game
    table.step(); // reset game
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
    table.step(); // reset game
    table.step();
    table.step();
    game::PlayerPtr player = table.players.getCurrentPlayer();
    std::string expected = "player2";
    ASSERT_EQ(expected, player->getName());
}

TEST_F(EventTests, TestTransitionFromPreflopToFlop) {
    table.step(); //begin game
    table.step(); // reset game
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
    table.step(); // reset game
    table.step(); // back to small blind player1
    table.step();
    ASSERT_EQ(table.gamePlay.street, game::Flop);
}


//TEST_F(EventTests, TestGameEndedFlagReset) {
//    cout << endl;
//    while (!table.gamePlay.game_ended) {
//        table.step();
//    }
//    ASSERT_TRUE(table.gamePlay.game_ended);
//    table.reset();
//    ASSERT_FALSE(table.gamePlay.game_ended);
//}

TEST_F(EventTests, TestGamePlay3) {
    cout << endl;
    std::vector<int> winning_players;
    std::vector<eval::HandType> winning_hands;
    // test fails because all in isn't handled.
    int num = 5;
    for (int i = 0; i < num; i++) {
        cout << "Running iteration: " << i << endl;
        cout << table.gamePlay.game_ended << endl;
        while (!table.gamePlay.game_ended) {
            table.step();
        }
        winning_hands.push_back(table.gamePlay.winning_hand);
        winning_players.push_back(table.gamePlay.winning_players[0]);
        cout << "Winning hand " << table.gamePlay.winning_hand;
        cout << " Winning Player " << table.gamePlay.winning_players[0] << endl;
        cout << "Community cards: " << table.gamePlay.communityCards << endl;
        for (auto player : table.players) {
            cout << player->getName() << " " << player->holeCards << endl;
        }
        table.reset();
    }
}


TEST_F(EventTests, TestGamePlayWithOneFolder) {
    cout << endl;
    tableWithFolder.step(); // resetting
    tableWithFolder.step(); // rotating
    tableWithFolder.step(); // small
    tableWithFolder.step(); // big
    tableWithFolder.step(); // utg1 calls
    tableWithFolder.step(); // utg2 calls
    tableWithFolder.step(); // Middle position calls
    tableWithFolder.step(); // Hijack position calls
    tableWithFolder.step(); // folder

    std::shared_ptr<Player> folder = tableWithFolder.players["folder"];
    ASSERT_FALSE(folder->inplay);
}



//TEST_F(EventTests, TestGamePlayWi) {
//    cout << endl;
//    while(!tableWithFolder.gamePlay.game_ended){
//        tableWithFolder.step();
//    }
//}



class MixedTableTests : public ::testing::Test {
protected:
    game::Players players;
    game::Table table;

    // call station should always check if they can and call if they cant

    void SetUp() {
        FoldStation foldStation1("player5");
        FoldStation foldStation2("player6");
        Raiser raiser("player7");
        foldStation1.stack = 100;
        foldStation2.stack = 100;
        raiser.stack = 100;
        players = game::Players::callStations(9, 100);

        players[5] = std::make_shared<FoldStation>(foldStation1);
        players[6] = std::make_shared<FoldStation>(foldStation2);
        players[7] = std::make_shared<Raiser>(raiser);

        game::Table table2(players);

        table = table2;
    }
};



TEST_F(MixedTableTests, TestMixedTablePotAmount) {
    table.step(); // resetting
    table.step(); // rotating
    table.step(); // small
    table.step(); // big
    table.step(); // utg1 calls
    table.step(); // utg2 calls
    table.step(); // Middle position calls
    table.step(); // Hijack position calls
    table.step(); // folder
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();

    cout << "Total in pot: " << table.gamePlay.pot << endl;
    int expected = 21;
    int actual = table.gamePlay.pot.value;
    ASSERT_EQ(expected, actual);
}

TEST_F(MixedTableTests, TestAllPlayersEqualAtEndOfFlop) {
    while(table.gamePlay.street == game::Preflop){
        table.step();
    }
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step(); // all players are equal here
    ASSERT_TRUE(table.players.checkAllPlayersEqual());
}

TEST_F(MixedTableTests, TestMixedTable) {
    while(table.gamePlay.street == game::Preflop){
        table.step();
    }
    // 3 * 7 (2 people folded) = 21
    cout << "Total in pot after preflop: " << table.gamePlay.pot << endl;

//    while(table.gamePlay.street == game::Flop){
//        table.step();
//    }
    // Flop + 3 * 7 (2 people folded) = 42
//    cout << "Total in pot after flop: " << table.gamePlay.pot << endl;

    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    table.step();
    cout << "players equal? " << table.players.checkAllPlayersEqual() << endl;
    table.step(); // all players are equal here
    cout << "players equal? " << table.players.checkAllPlayersEqual() << endl;
}

//
//TEST_F(EventTests, TestGamePlay4) {
//    cout << endl;
//    while (!table.gamePlay.game_ended) {
//        table.step();
//    }
//    table.reset();
//
//    while (!table.gamePlay.game_ended) {
//        table.step();
//    }
////    table.reset();
////    cout << table.gamePlay.pl
////    I shold desctroy the current game play object and create a new one for
////    each game that we play
//
//}















