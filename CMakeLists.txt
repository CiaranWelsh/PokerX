cmake_minimum_required(VERSION 3.0)

project(PokerSimulationsInCpp)


#set(Boost_INCLUDE_DIR D:/boost_1_64_0)
#set(Boost_LIBRARY_DIR ${Boost_INCLUDE_DIR}/stage/lib)
set(BOOST_DIR D:/boost_1_64_0)
set(NUMCPP_DIR D:/NumCpp/include)

include_directories(src ${BOOST_DIR} ${NUMCPP_DIR})

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)

