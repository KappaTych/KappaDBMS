include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(parser_tests_run
        ParserTestsFixture.cpp
        )

if (NOT TARGET parser)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../src/backend/parser ${CMAKE_CURRENT_BINARY_DIR}/src/backend/parser)
endif()


target_link_libraries(parser_tests_run parser gtest gtest_main gmock gmock_main)
target_include_directories(parser_tests_run PUBLIC
        ../../src/backend
        ../../src/backend/include
        )