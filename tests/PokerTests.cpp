/**
 * What is it that I'm actually trying to do?
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "eval/Hand.h"
#include "Mockups/MockCard.h"

using namespace testing;


class PokerTests : public ::testing::Test {
public:

    HandTests() = default;
};




	/**
	* Has getters and setters for controlling the game variables
	*/
	Poker poker;
	poker.setNumPlayers(2);
	poker.setSmallBlind(1);
	poker.setBigBlind(2);

	// opens the console and walk through the game, waiting on user input
	poker.playConsole();


