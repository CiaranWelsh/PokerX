add_subdirectory(googletest)
include(GoogleTest)

add_subdirectory(Mockups)

# BINARY: Name of the binary for the test unit you are adding
# LINK_WITH_GOOGLETEST: ON or OFF.
# OUT_VARIABLE: test target will be added into this list
function(add_test_executable BINARY LINK_WITH_GOOGLETEST LINK_WITH_POKERX_BINARY OUT_VARIABLE)
    add_executable(${BINARY} ${ARGN})

    if (${LINK_WITH_GOOGLETEST})
        target_link_libraries(${BINARY} PRIVATE gtest gtest_main gmock gmock_main)
    endif ()

    if (LINK_WITH_POKERX_BINARY)
        target_link_libraries(${BINARY} PRIVATE PokerX)
    endif ()

    gtest_add_tests(TARGET ${BINARY})

    target_include_directories(${BINARY} PRIVATE "${POKERX_INCLUDE_DIR}")

    #    target_include_directories(${BINARY} PRIVATE "${NUMCPP_INCLUDE_DIR}")
    #    add_dependencies(${BINARY} poker)

    if ("${${OUT_VARIABLE}}" STREQUAL "")
        set(${OUT_VARIABLE} "${BINARY}" PARENT_SCOPE)
    else ()
        set(${OUT_VARIABLE} "${${OUT_VARIABLE}}" "${BINARY}" PARENT_SCOPE)
    endif ()

endfunction()

set(TestExecutables)

# A unit test style test for State class. We create an set
# of light state from the abstract State class.
add_test_executable(StateTests ON OFF TestExecutables
        StateTests.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/State.h"
        AbstractStateMachineTests/enumState.h
        AbstractStateMachineTests/LightOff.h
        AbstractStateMachineTests/LightOff.cpp
        AbstractStateMachineTests/LightLow.h
        AbstractStateMachineTests/LightLow.cpp
        AbstractStateMachineTests/LightHigh.h
        AbstractStateMachineTests/LightHigh.cpp
        )


# An integration style test on StateMachine and States. We create
# a StateMachine simulation of a light switching states from Off to
# low intensity to high intensity. The code uses the same
# abstract interface as used in PokerEngine, but its much simpler.
add_test_executable(StateMachineAbstractionTests ON OFF TestExecutables
        StateMachineTests.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/StateMachine.h"
        "${POKERX_SOURCE_DIR}/engine/StateMachine.cpp"
        AbstractStateMachineTests/enumState.h
        AbstractStateMachineTests/LightOff.h
        AbstractStateMachineTests/LightOff.cpp
        AbstractStateMachineTests/LightLow.h
        AbstractStateMachineTests/LightLow.cpp
        AbstractStateMachineTests/LightHigh.h
        AbstractStateMachineTests/LightHigh.cpp
        )

# GameVariable Unit tests
add_test_executable(GameVariableTests ON OFF TestExecutables
        GameVariableTests.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/GameVariables.h"
        "${POKERX_SOURCE_DIR}/engine/GameVariables.cpp"
        )

# Pot Unit tests
add_test_executable(PotTests.cpp ON OFF TestExecutables
        PotTests.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/Pot.h"
        "${POKERX_SOURCE_DIR}/engine/Pot.cpp"
        )


# ResetState Unit tests
# Note: It is not possible to build the test with only the ResetState source code
# because of compile errors. We therefore link to PokerX library
add_test_executable(
        ResetStateTests ON ON TestExecutables
        ResetStateTests.cpp
        Mockups/MockPokerEngine.h
        Mockups/MockState.h
        )


# ButtonMoves Unit tests
add_test_executable(
        ButtonMovesTests ON ON TestExecutables
        ButtonMovesTests.cpp
        Mockups/MockPokerEngine.h
        Mockups/MockState.h
        )

# PlayerManager unit tests
add_test_executable(
        PlayerManagerTests ON ON TestExecutables
        PlayerManagerTests.cpp
        Mockups/FakePlayer.h
)

# Player unit tests
add_test_executable(
        PlayerTests ON ON TestExecutables
        PlayerTests.cpp

        # Headers
        "${POKERX_INCLUDE_DIR}/PokerX/engine/Player.h"
        "${POKERX_INCLUDE_DIR}/PokerX/engine/Action.h"

        # Sources
        "${POKERX_SOURCE_DIR}/engine/Player.cpp"
        "${POKERX_SOURCE_DIR}/engine/PlayerManager.cpp"


)

# integration style tests to check the Player and GameVariables
# classes interact correctly according to the observer pattern
add_test_executable(ObserverPatternTests ON ON TestExecutables
        GameVariableObserverTests.cpp
        )

# integration tests for PokerEngine
add_test_executable(PokerEngineStateMachineTests ON ON TestExecutables
        PokerEngineStateMachineTests.cpp
        Mockups/FakePlayer.h
        Mockups/MockPlayerManager.h
        )

# Tests for Cards and CardCollection objects
add_test_executable(CardTests                       ON ON TestExecutables CardTests.cpp)
add_test_executable(CardCollectionTests             ON ON TestExecutables CardCollectionTests.cpp)
add_test_executable(RestricteCardCollectionTests    ON ON TestExecutables RestrictedCardCollectionTests.cpp)
add_test_executable(DeckTests                       ON ON TestExecutables DeckTests.cpp)
add_test_executable(HoleCardTests                   ON ON TestExecutables HoleCardTests.cpp)
add_test_executable(CommunityCardTests              ON ON TestExecutables CommunityCardTests.cpp)

add_executable(AConsoleGame AConsoleGame.cpp)
target_link_libraries(AConsoleGame PRIVATE PokerX)


add_test_executable(ContainerTests.cpp              ON ON TestExecutables ContainerTests.cpp)


#add_test_executable(PokerTests ON  ON TestExecutables PokerTests.cpp)
#add_test_executable(StateTests ON  ON TestExecutables IStateTests.cpp)
#add_test_executable(EngineTests ON ON  TestExecutables EngineTests.cpp)
#add_test_executable(PotTests ON ON TestExecutables PotTests.cpp)
#add_test_executable(CallStationTests ON ON TestExecutables CallStationTests.cpp)
#
#add_executable(x EngineTests.cpp)


#
#add_test_executable(HandTests ON TestExecutables HandTests.cpp)
