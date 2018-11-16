cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaParser)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

option(PARSER_SHARED "Make parser shared library" ON)
option(PARSER_TEST "Build parser with tests" OFF)

file(GLOB_RECURSE SRC_PARSER . *.hpp *.cpp)

set(SRC_TESTS
    ../../../tests/playground/ParserTest.cpp
)

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

#if (PARSER_TEST OR BUILD_TESTS)
#    add_executable(parser_test ${SRC_TESTS})
#    target_link_libraries(parser_test parser)
#    target_include_directories(parser_test PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/..
#        ${CMAKE_CURRENT_SOURCE_DIR}/../include
#    )
#endif()
