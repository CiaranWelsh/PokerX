cmake_minimum_required(VERSION 3.15)

project(PokerSimulationsInCpp)

find_package(Boost REQUIRED)

message(STATUS "Boost_FOUND ${Boost_FOUND}")

set(NUMCPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/NumCpp/include")

add_subdirectory(src)
add_subdirectory(tests)

