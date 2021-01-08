add_subdirectory(googletest)
include(GoogleTest)

# BINARY: Name of the binary for the test unit you are adding
# LINK_WITH_GOOGLETEST: ON or OFF.
# OUT_VARIABLE: test target will be added into this list
function(add_test_executable BINARY LINK_WITH_GOOGLETEST OUT_VARIABLE)
    add_executable(${BINARY} ${ARGN})

    if (${LINK_WITH_GOOGLETEST})
        set(GTEST_LIBS
                gtest gtest_main
                gmock gmock_main)
    endif ()

    gtest_add_tests(TARGET ${BINARY})

    target_link_libraries(${BINARY} PRIVATE poker ${GTEST_LIBS})

#    target_include_directories(${BINARY} PRIVATE "${NUMCPP_INCLUDE_DIR}")
    add_dependencies(${BINARY} poker)

    if ("${${OUT_VARIABLE}}" STREQUAL "")
        set(${OUT_VARIABLE} "${BINARY}" PARENT_SCOPE)
    else ()
        set(${OUT_VARIABLE} "${${OUT_VARIABLE}}" "${BINARY}" PARENT_SCOPE)
    endif ()

endfunction()

set(TestExecutables)
add_test_executable(CardTests ON TestExecutables CardTests.cpp)
add_test_executable(CardCollectionTests ON TestExecutables CardCollectionTests.cpp)
#add_test_executable(CounterTests ON TestExecutables CounterTests.cpp)


#set(BINARY poker_tests)
#add_executable(${BINARY} main.cpp
#        CardTests.cpp
#        DeckTests.cpp
#        CardCollectionTests.cpp
#        CommunityCardTests.cpp
#        HoleCardTests.cpp
#        EvaluatorTests.cpp
#        CounterTests.cpp
#        PlayerTests.cpp
#        PotTests.cpp
#        PlayersTests.cpp
#        DealerTests.cpp
#        TableTests.cpp
#        SinglePokerHandTests.cpp
#        EventTests.cpp
#        ExceptionTests.cpp)
#
#add_test(NAME ${BINARY} COMMAND ${BINARY})
#
#target_link_libraries(${BINARY} PUBLIC poker gtest gtest_main)








