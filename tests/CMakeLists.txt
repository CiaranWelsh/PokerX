add_subdirectory(googletest)
include(GoogleTest)

add_subdirectory(Mockups)

# BINARY: Name of the binary for the test unit you are adding
# LINK_WITH_GOOGLETEST: ON or OFF.
# OUT_VARIABLE: test target will be added into this list
function(add_test_executable BINARY LINK_WITH_GOOGLETEST LINK_WITH_POKERX_BINARY OUT_VARIABLE)
    add_executable(${BINARY} ${ARGN})

    if (${LINK_WITH_GOOGLETEST})
        target_link_libraries(${BINARY} PRIVATE  gtest gtest_main gmock gmock_main)
    endif ()

    if(LINK_WITH_POKERX_BINARY)
        target_link_libraries(${BINARY} PRIVATE engine)
    endif()

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

add_test_executable(StateTests ON OFF TestExecutables
        StateTests.cpp
        AbstractStateMachineTests/eState.h
        AbstractStateMachineTests/LightOff.h
        AbstractStateMachineTests/LightOff.cpp
        AbstractStateMachineTests/LightLow.h
        AbstractStateMachineTests/LightLow.cpp
        AbstractStateMachineTests/LightHigh.h
        AbstractStateMachineTests/LightHigh.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/State.h"
        )



add_test_executable(StateMachineAbstractionTests ON OFF TestExecutables
        StateMachineTests.cpp
        AbstractStateMachineTests/LightOff.h
        AbstractStateMachineTests/LightOff.cpp
        AbstractStateMachineTests/LightLow.h
        AbstractStateMachineTests/LightLow.cpp
        AbstractStateMachineTests/LightHigh.h
        AbstractStateMachineTests/LightHigh.cpp
        "${POKERX_INCLUDE_DIR}/PokerX/engine/StateMachine.h"
        "${POKERX_SOURCE_DIR}/engine/StateMachine.cpp"
        )

#add_test_executable(PokerTests ON  ON TestExecutables PokerTests.cpp)
#add_test_executable(StateTests ON  ON TestExecutables IStateTests.cpp)
#add_test_executable(EngineTests ON ON  TestExecutables EngineTests.cpp)
#add_test_executable(PotTests ON ON TestExecutables PotTests.cpp)
#add_test_executable(CallStationTests ON ON TestExecutables CallStationTests.cpp)
#
#add_executable(x EngineTests.cpp)

#add_test_executable(CardTests ON TestExecutables CardTests.cpp)
#add_test_executable(CardCollectionTests ON TestExecutables CardCollectionTests.cpp)
#add_test_executable(RestricteCardCollectionTests ON TestExecutables RestrictedCardCollectionTests.cpp)
#add_test_executable(DeckTests ON TestExecutables DeckTests.cpp)
#add_test_executable(HoleCardTests ON TestExecutables HoleCardTests.cpp)
#add_test_executable(CommunityCardTests ON TestExecutables CommunityCardTests.cpp)
#
#add_test_executable(HandTests ON TestExecutables HandTests.cpp)
