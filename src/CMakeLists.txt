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

#        game/Dealer.h game/Dealer.cpp
        game/Positions.h game/Positions.cpp
        game/Pot.h game/Pot.cpp
#        game/Seat.h game/Seat.cpp
#        game/Table.h game/Table.cpp
        )







