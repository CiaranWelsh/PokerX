set(BINARY ${CMAKE_PROJECT_NAME}_tests)
add_executable(${BINARY} main.cpp
        CardTests.cpp
        DeckTests.cpp
        CardCollectionTests.cpp
        CommunityCardTests.cpp
        HoleCardTests.cpp
        EvaluatorTests.cpp
        CounterTests.cpp
        PlayerTests.cpp
        PotTests.cpp
        PositionsTests.cpp
        DealerTests.cpp
        TableTests.cpp
        SinglePokerHandTests.cpp
        )

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)








