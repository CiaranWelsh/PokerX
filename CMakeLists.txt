cmake_minimum_required(VERSION 3.0)

project(PokerSimulationsInCpp)


set(BOOST_DIR D:/boost_1_64_0)
set(NUMCPP_DIR D:/NumCpp/include)

include_directories(src ${BOOST_DIR} ${NUMCPP_DIR})

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)

