set(BINARY ${CMAKE_PROJECT_NAME})

#add_executable(${BINARY}_run main.cpp Card.cpp Card.h Hand.cpp Hand.h)
add_library(${BINARY}_lib STATIC
        Card.h Card.cpp
        Hand.cpp Hand.h
        Deck.cpp Deck.h
        )







