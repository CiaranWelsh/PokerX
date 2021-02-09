cmake_minimum_required(VERSION 3.15)

project(PokerX)

###################################################################
# Options and settings
#

include(GnuInstallDirs)

# put all runtime targets (exe and dll) into bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_INSTALL_BINDIR}")

# put libraries into lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_LIBDIR}")

# archives
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_INSTALL_LIBDIR}")

# export all on windows. Ignored on other.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

set(POKERX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(POKERX_INCLUDE_DIR "${POKERX_ROOT_DIR}/include")
set(POKERX_SOURCE_DIR "${POKERX_ROOT_DIR}/src")

###################################################################
#   Dependencies
#

option(WITH_ASAN "compiile with adress sanitizer" OFF)

if (WITH_ASAN)
    if (APPLE AND NOT UNIX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
    endif ()
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)


#########################################################
#   Build PokerX library
#
add_library(
        PokerX STATIC

        # headers
        include/PokerX/engine/Action.h
        include/PokerX/engine/AllInPlayer.h
        include/PokerX/engine/AllPlayersEqual.h
        include/PokerX/engine/BigBlind.h
        include/PokerX/engine/ButtonMoves.h
        include/PokerX/engine/Container.h
        include/PokerX/engine/CallStationPlayer.h
        include/PokerX/engine/Card.h
        include/PokerX/engine/CardCollection.h
        include/PokerX/engine/CommunityCards.h
        include/PokerX/engine/CheckerPlayer.h
        include/PokerX/engine/Deck.h
        include/PokerX/engine/DealHoleCards.h
        include/PokerX/engine/DealFlop.h
        include/PokerX/engine/DealTurn.h
        include/PokerX/engine/DealRiver.h
        include/PokerX/engine/EndStreet.h
        include/PokerX/engine/FolderPlayer.h
        include/PokerX/engine/eGamePlayState.h
        include/PokerX/engine/GameVariables.h
        include/PokerX/engine/HoleCards.h
        include/PokerX/engine/IGameVariables.h
        include/PokerX/engine/IPlayer.h
        include/PokerX/engine/IPlayerManager.h
        include/PokerX/engine/IObserver.h
        include/PokerX/engine/IObservableSharedPtr.h
        include/PokerX/engine/NextStreet.h
        include/PokerX/engine/PokerEngine.h
        include/PokerX/engine/Pot.h
        include/PokerX/engine/PreflopBetting.h
        include/PokerX/engine/RaiserPlayer.h
        include/PokerX/engine/RotatoryContainer.h
        include/PokerX/engine/Player.h
        include/PokerX/engine/PlayerManager.h
        include/PokerX/engine/Reset.h
        include/PokerX/engine/RestrictedCardCollection.h
        include/PokerX/engine/RandomNumberGenerator.h
        include/PokerX/engine/River.h
        include/PokerX/engine/Showdown.h
        include/PokerX/engine/SmallBlind.h
        include/PokerX/engine/StreetStart.h
        include/PokerX/engine/State.h
        include/PokerX/engine/StateMachine.h
        include/PokerX/engine/StreetMachine.h
        include/PokerX/engine/Turn.h
        include/PokerX/engine/PlayerToAct.h
        include/PokerX/Error.h
        include/PokerX/engine/hands/Hand.h
        include/PokerX/engine/hands/Pair.h
        include/PokerX/engine/hands/TwoPair.h
        include/PokerX/engine/hands/HighCard.h
        include/PokerX/engine/hands/ThreeOfAKind.h
        include/PokerX/engine/hands/Straight.h
        include/PokerX/engine/hands/Flush.h
        include/PokerX/engine/hands/FullHouse.h
        include/PokerX/engine/hands/FourOfAKind.h
        include/PokerX/engine/hands/StraightFlush.h
        include/PokerX/engine/hands/RoyalFlush.h
        include/PokerX/engine/hands/Best5.h
        include/PokerX/engine/hands/HandType.h
        include/PokerX/engine/hands/IHand.h
        include/PokerX/engine/Evaluator.h
        include/PokerX/engine/Policy.h
        include/PokerX/engine/PolicyPlayer.h

        # sources
        src/engine/AllInPlayer.cpp
        src/engine/AllPlayersEqual.cpp
        src/engine/BigBlind.cpp
        src/engine/ButtonMoves.cpp
        src/engine/CallStationPlayer.cpp
        src/engine/Card.cpp
        src/engine/CardCollection.cpp
        src/engine/CommunityCards.cpp
        src/engine/CheckerPlayer.cpp
        src/engine/Deck.cpp
        src/engine/DealHoleCards.cpp
        src/engine/DealFlop.cpp
        src/engine/DealTurn.cpp
        src/engine/DealRiver.cpp
        src/engine/EndStreet.cpp
        src/engine/Flop.cpp
        src/engine/FolderPlayer.cpp
        src/engine/GameVariables.cpp
        src/engine/HoleCards.cpp
        src/engine/NextStreet.cpp
        src/engine/PokerEngine.cpp
        src/engine/Pot.cpp
        src/engine/PreflopBetting.cpp
        src/engine/Player.cpp
        src/engine/PlayerManager.cpp
        src/engine/RandomNumberGenerator.cpp
        src/engine/RaiserPlayer.cpp
        src/engine/Reset.cpp
        src/engine/RestrictedCardCollection.cpp
        src/engine/River.cpp
        src/engine/Showdown.cpp
        src/engine/SmallBlind.cpp
        src/engine/StreetStart.cpp
        src/engine/StateMachine.cpp
        src/engine/StreetMachine.cpp
        src/engine/Turn.cpp
        src/engine/PlayerToAct.cpp
        src/engine/hands/Hand.cpp
        src/engine/hands/Pair.cpp
        src/engine/hands/TwoPair.cpp
        src/engine/hands/HighCard.cpp
        src/engine/hands/ThreeOfAKind.cpp
        src/engine/hands/Straight.cpp
        src/engine/hands/Flush.cpp
        src/engine/hands/FullHouse.cpp
        src/engine/hands/FourOfAKind.cpp
        src/engine/hands/StraightFlush.cpp
        src/engine/hands/RoyalFlush.cpp
        src/engine/hands/Best5.cpp
        src/engine/hands/IHand.cpp
        src/engine/Evaluator.cpp
        src/engine/Policy.cpp
        src/engine/PolicyPlayer.cpp


)

target_include_directories(
        PokerX PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)
include(GenerateExportHeader)
generate_export_header(PokerX)

#########################################################
#   Build tests
#
include(GoogleTest)
enable_testing()

add_subdirectory(tests)

install(TARGETS PokerX)

install(DIRECTORY include DESTINATION .)