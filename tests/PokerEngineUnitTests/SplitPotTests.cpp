#include <PokerX/engine/PlayerToAct.h>
#include <PokerX/engine/GameVariables.h>
#include <PokerX/engine/PlayerManager.h>
#include <PokerX/engine/PolicyPlayer.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/AllPlayersEqual.h"


#include "PokerEngineTests.h"

class SplitPotTests : public ::testing::Test {
public:

    SplitPotTests() = default;
};

/**
 * If there are four players in the hand and Player 1 is all-in with his
 * last INR 100, the most he could win is 4 X INR 100. So at the end of
 * the betting round, take INR 400 and put it aside as "Player 1's Pot".
 * He can win that pot, and that pot alone. Then play continues as usual
 * with everyone else competing for both pots. Suppose later in that hand
 * Player 2 is faced with a INR 600 bet, and puts in his last INR 200,
 * going all-in. At the end of the betting round, Player 2 and everyone
 * else puts INR 200 into their pot. Now that pot is "Player 2's Pot".
 * The change goes into a third pot, and play proceeds as usual. After
 * all the cards are dealt and the showdown takes place, the pots are
 * awarded in reverse order. The last two players who stayed in till the
 * end show their cards and the winner takes the third pot. Then Player 2
 * gets to show his hand against those two, and the winner takes "Player
 * 2's pot" then Player 1 gets to show his hand against all three opponents,
 * and the winner gets "Player 1's pot".
 */


/**
 *
 */
TEST_F(SplitPotTests, Test) {
    using initA = std::initializer_list<pokerx::Action>;
    using initF = std::initializer_list<float>;

    PlayerManager players({
                                  std::make_shared<PolicyPlayer>("btn", 20, initA({ALL_IN})),
                                  std::make_shared<PolicyPlayer>("sb", 18, initA({ALL_IN})),
                                  std::make_shared<PolicyPlayer>("bb", 13, initA({ALL_IN})),
                                  std::make_shared<PolicyPlayer>("utg", 10.0, initA({ALL_IN})),
                                  std::make_shared<PolicyPlayer>("hj", 8, initA({ALL_IN})),
                                  std::make_shared<PolicyPlayer>("co", 6, initA({ALL_IN}))
                          });
    GameVariables gameVariables;
    gameVariables.setStreet(PREFLOP_STREET);
    PokerEngine engine(&players, &gameVariables);

    engine.action(1);
    engine.action(1);
    engine.action(1);
    engine.action(1);
    engine.action(1);
    engine.action(1);

    // players all go all in
    engine.action();
    engine.action();
    engine.action();
    engine.action();
    engine.action();

    engine.action(1);





}






















