set(target engine)


set(
        SOURCES
        StateMachine
#        State.h
#        PokerEngine
#        NoLimitHoldem
#        ButtonMoves
#        SmallBlind
#        Player.h
#        CallStationPlayer
#        ConsolePlayer
#        Pot
)

add_library(${target} STATIC ${SOURCES})
#target_include_directories(${target} PUBLIC .. ${CMAKE_CURRENT_SOURCE_DIR})















