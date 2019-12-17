set(BINARY ${CMAKE_PROJECT_NAME})

#add_executable(${BINARY}_run main.cpp Card.cpp Card.h Hand.cpp Hand.h)
add_library(${BINARY}_lib STATIC
        Card.h Card.cpp
        Hand.h Hand.cpp
        Deck.h Deck.cpp
        CardCollection.h CardCollection.cpp
        RandomNumberGenerator.cpp RandomNumberGenerator.h)







