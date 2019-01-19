cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaParser)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

option(PARSER_SHARED "Make parser shared library" ON)
option(PARSER_PLAYGROUND "Build parser with tests" ON)

file(GLOB_RECURSE SRC_PARSER . *.hpp *.cpp)

set(SRC_PG ../../tests/playground/ParserPG.cpp)

if (PARSER_SHARED)
    add_library(parser SHARED EXCLUDE_FROM_ALL ${SRC_PARSER})
else()
    add_library(parser STATIC EXCLUDE_FROM_ALL ${SRC_PARSER})
endif()

target_include_directories(parser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
set_target_properties(parser PROPERTIES VERSION ${BUILD_VERSION} SOVERSION ${BUILD_MAJOR})

if (PARSER_PLAYGROUND OR BUILD_PARSER)
    add_executable(parser_pg ${SRC_PG})
    target_link_libraries(parser_pg parser)
    target_include_directories(parser_pg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
    )
endif()
