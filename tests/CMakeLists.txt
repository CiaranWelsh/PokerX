set(BINARY ${CMAKE_PROJECT_NAME}_tests)
add_executable(${BINARY} main.cpp
#        CardTests.cpp
        HandTests.cpp
#        DeckTests.cpp
        )

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)








