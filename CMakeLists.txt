cmake_minimum_required(VERSION 3.15)

project(PokerSimulationsInCpp)

# put all runtime targets (exe and dll) into bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# put libraries into lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# archives
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# export all on windows. Ignored on other.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

find_package(Boost REQUIRED)

message(STATUS "Boost_FOUND ${Boost_FOUND}")

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(NUMCPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/NumCpp/include")

add_subdirectory(src)
add_subdirectory(tests)

