cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaDriver)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

option(DRIVER_SHARED "Make driver shared library" ON)
option(DRIVER_PLAYGROUND "Build driver with tests" OFF)

file(GLOB_RECURSE SRC_DRIVER . *.hpp *.cpp)

set(SRC_PG ../../tests/playground/DriverPG.cpp)

if (DRIVER_SHARED)
    add_library(driver SHARED EXCLUDE_FROM_ALL ${SRC_DRIVER})
else()
    add_library(driver STATIC EXCLUDE_FROM_ALL ${SRC_DRIVER})
endif()

target_include_directories(driver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(driver storage parser)
set_target_properties(driver PROPERTIES VERSION ${BUILD_VERSION} SOVERSION ${BUILD_MAJOR})

if (DRIVER_PLAYGROUND OR BUILD_DRIVER)
    add_executable(driver_pg ${SRC_PG})
    target_link_libraries(driver_pg driver)
    target_include_directories(driver_pg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
    )
endif()
