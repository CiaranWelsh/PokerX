set(BINARY ${CMAKE_PROJECT_NAME})

#add_executable(${BINARY}_run main.cpp Card.cpp Card.h Hand.cpp Hand.h)
add_library(${BINARY}_lib STATIC
        cards/Card.h cards/Card.cpp
        eval/Hand.h eval/Hand.cpp
        cards/Deck.h cards/Deck.cpp
        cards/CardCollection.h cards/CardCollection.cpp
        cards/HoleCards.h cards/HoleCards.cpp
        cards/CommunityCards.h cards/CommunityCards.cpp
        eval/Evaluator.cpp eval/Evaluator.h
        Errors.h
        utils/Counter.h

        players/Player.h players/Player.cpp
        players/CallStation.h players/CallStation.cpp
        players/ActionType.h
        #        players/Random.h players/Random.cpp

        game/Dealer.h game/Dealer.cpp
        game/Players.h game/Players.cpp
        game/Pot.h game/Pot.cpp
        game/Table.h game/Table.cpp
        game/Street.h

        events/Event.cpp events/Event.h
        events/time_event/TimeEvent.cpp
        events/time_event/TimeEvent.h
        events/player_event/PlayerEvent.cpp
        events/player_event/PlayerEvent.h
        events/dealer_event/DealerEvent.cpp
        events/dealer_event/DealerEvent.h
        events/time_event/BeginGame.cpp
        events/time_event/BeginGame.h
        events/player_event/RotatePlayers.cpp
        events/player_event/RotatePlayers.h
        events/player_event/PostSmallBlind.cpp
        events/player_event/PostSmallBlind.h
        events/player_event/PostBigBlind.cpp
        events/player_event/PostBigBlind.h
        events/EventPtr.h
        game/GamePlay.h events/time_event/EndGame.cpp events/time_event/EndGame.h events/dealer_event/DealHoleCards.cpp events/dealer_event/DealHoleCards.h events/player_event/PlayerAction.cpp events/player_event/PlayerAction.h events/time_event/NextStreet.cpp events/time_event/NextStreet.h utils/EqualityChecker.h events/dealer_event/DealTurn.cpp events/dealer_event/DealTurn.h events/dealer_event/DealFlop.cpp events/dealer_event/DealFlop.h events/dealer_event/DealRiver.cpp events/dealer_event/DealRiver.h utils/Log.h utils/ArgMax.h events/dealer_event/Showdown.cpp events/dealer_event/Showdown.h players/FoldStation.cpp players/FoldStation.h events/dealer_event/ResetGame.cpp events/dealer_event/ResetGame.h players/Checker.cpp players/Checker.h players/Raiser.cpp players/Raiser.h players/PreflopRaiser.cpp players/PreflopRaiser.h)







