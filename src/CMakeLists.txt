set(BINARY ${CMAKE_PROJECT_NAME})

#add_executable(${BINARY}_run main.cpp Card.cpp Card.h Hand.cpp Hand.h)
add_library(${BINARY}_lib STATIC
        cards/Card.h cards/Card.cpp
        eval/Hand.h eval/Hand.cpp
        cards/Deck.h cards/Deck.cpp
        cards/CardCollection.h cards/CardCollection.cpp
        cards/HoleCards.h cards/HoleCards.cpp
        cards/CommunityCards.h cards/CommunityCards.cpp
        eval/Evaluator.cpp eval/Evaluator.h Errors.h)







