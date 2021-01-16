cmake_minimum_required(VERSION 3.15)

project(PokerX)

###################################################################
# Options and settings
#

# put all runtime targets (exe and dll) into bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# put libraries into lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# archives
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# export all on windows. Ignored on other.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

set(POKERX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(POKERX_INCLUDE_DIR "${POKERX_ROOT_DIR}/include")
set(POKERX_SOURCE_DIR "${POKERX_ROOT_DIR}/src")

###################################################################
#   Dependencies
#

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")


find_package(Boost REQUIRED)

message(STATUS "Boost_FOUND ${Boost_FOUND}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(NUMCPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/NumCpp/include")

option(SHOW_DEBUG_STATEMENTS "When defined, extra print statements are output to console during execution" OFF)
if (${CMAKE_CURRENT_SOURCE_DIR} EQUAL ${CMAKE_SOURCE_DIR})
    if (${CMAKE_BUILD_TYPE} EQUAL "Debug")
        if (SHOW_DEBUG_STATEMENTS)
            add_definitions(DEBUG_MODE)
        endif ()
    endif ()
endif ()

add_subdirectory(src)
add_subdirectory(tests)

