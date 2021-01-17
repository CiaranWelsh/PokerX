set(target poker)

# todo refactor into C++ 20 style modules etc.

set(SOURCES

        CardCollectionObserver.h
        ISubject.h

        # Card sources
        card/Card
        card/CardCollection
        card/RestrictedCardCollection
        card/Deck
        card/HoleCards
        card/CommunityCards

        #Eval sources.
        eval/Hand

        game/IEntity.h
        game/state/IState.h
        game/state/ButtonMoves


        #        eval/Evaluator.cpp eval/Evaluator.h
#        Errors.h
#        utils/Counter.h
#        utils/UniformRNG.h utils/UniformRNG.cpp
#
#        players/Player.h players/Player.cpp
#        players/CallStation.h players/CallStation.cpp
#        players/ActionType.h
#        #        players/Random.h players/Random.cpp
#
#        game/Dealer.h game/Dealer.cpp
#        game/Players.h game/Players.cpp
#        game/Pot.h game/Pot.cpp
#        game/Table.h game/Table.cpp
#        game/Street.h
#
#        events/Event.cpp events/Event.h
#        events/time_event/TimeEvent.cpp
#        events/time_event/TimeEvent.h
#        events/player_event/PlayerEvent.cpp
#        events/player_event/PlayerEvent.h
#        events/dealer_event/DealerEvent.cpp
#        events/dealer_event/DealerEvent.h
#        events/time_event/BeginGame.cpp
#        events/time_event/BeginGame.h
#        events/player_event/RotatePlayers.cpp
#        events/player_event/RotatePlayers.h
#        events/player_event/PostSmallBlind.cpp
#        events/player_event/PostSmallBlind.h
#        events/player_event/PostBigBlind.cpp
#        events/player_event/PostBigBlind.h
#        events/EventPtr.h
#        game/GamePlay.h events/time_event/EndGame.cpp
#        events/time_event/EndGame.h events/dealer_event/DealHoleCards.cpp
#        events/dealer_event/DealHoleCards.h events/player_event/PlayerAction.cpp
#        events/player_event/PlayerAction.h events/time_event/NextStreet.cpp
#        events/time_event/NextStreet.h utils/EqualityChecker.h events/dealer_event/DealTurn.cpp
#        events/dealer_event/DealTurn.h events/dealer_event/DealFlop.cpp
#        events/dealer_event/DealFlop.h events/dealer_event/DealRiver.cpp
#        events/dealer_event/DealRiver.h utils/Log.h utils/ArgMax.h
#        events/dealer_event/Showdown.cpp events/dealer_event/Showdown.h
#        players/FoldStation.cpp players/FoldStation.h
#        events/dealer_event/ResetGame.cpp events/dealer_event/ResetGame.h
#        players/Checker.cpp players/Checker.h players/Raiser.cpp
#        players/Raiser.h players/PreflopRaiser.cpp players/PreflopRaiser.h
)

add_library(${target} STATIC ${SOURCES})
target_include_directories(${target} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

include(GenerateExportHeader)
generate_export_header(${target})





