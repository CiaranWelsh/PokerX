
add_subdirectory(engine)

set(target poker)


# todo refactor into C++ 20 style modules etc.

set(
        SOURCES
        Poker
)

#add_library(${target} STATIC ${SOURCES})
#target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

#include(GenerateExportHeader)
#generate_export_header(${target})
