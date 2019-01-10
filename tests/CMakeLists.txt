#project(${CMAKE_PROJECT_NAME}_tests)

option(BUILD_DRIVER_TESTS "Build DRIVER_TESTS" OFF)
option(BUILD_PARSER_TESTS "Build PARSER_TESTS" ON)
option(BUILD_STORAGE_TESTS "Build STORAGE_TESTS" OFF)
option(BUILD_ALL_TESTS "Build TESTS_TESTS" OFF)

#include(${lib_cmake}/googletest.cmake)
#fetch_googletest(
#        ${PROJECT_SOURCE_DIR}/cmake
#        ${PROJECT_BINARY_DIR}/googletest
#)

# Clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/lib/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif()

set(SRC_TESTS)

if (BUILD_DRIVER_TESTS OR BUILD_ALL_TESTS)
    set(SRC_TESTS ${SRC_TESTS} DriverTestsFixture.cpp)
endif (BUILD_DRIVER_TESTS OR BUILD_ALL_TESTS)
unset(BUILD_DRIVER_TESTS CACHE)

if (BUILD_PARSER_TESTS OR BUILD_ALL_TESTS)
    set(SRC_TESTS ${SRC_TESTS} ParserTestsFixture.cpp)
endif (BUILD_PARSER_TESTS OR BUILD_ALL_TESTS)
unset(BUILD_PARSER_TESTS CACHE)

if (BUILD_STORAGE_TESTS OR BUILD_ALL_TESTS)
    set(SRC_TESTS ${SRC_TESTS} StorageEngineTestsFixture.cpp)
endif (BUILD_STORAGE_TESTS OR BUILD_ALL_TESTS)
unset(BUILD_STORAGE_TESTS CACHE)

unset(BUILD_ALL_TESTS CACHE)

enable_testing()

add_executable(tests_run ${SRC_TESTS})
target_link_libraries(tests_run gtest gtest_main ${LINK_LIBS})
target_include_directories(tests_run PUBLIC
        /src
        /src/include
        )
