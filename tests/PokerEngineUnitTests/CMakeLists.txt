add_test_executable(PreflopTests ON ON TestExecutables PokerEngineTests.h PreflopTests.cpp ${MOCK_SOURCE_FILES})
add_test_executable(BettingTests ON ON TestExecutables PokerEngineTests.h BettingTests.cpp ${MOCK_SOURCE_FILES})

add_test_executable(AllPlayersEqualTests ON ON TestExecutables PokerEngineTests.h AllPlayersEqualTests.cpp ${MOCK_SOURCE_FILES})
add_test_executable(SplitPotTests ON ON TestExecutables PokerEngineTests.h SplitPotTests.cpp ${MOCK_SOURCE_FILES})

#SwitchStreetTests
#BettingTests
#ShowdownTests
