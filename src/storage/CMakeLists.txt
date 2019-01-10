cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaStorage)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

option(STORAGE_SHARED "Make storage shared library" ON)
option(STORAGE_PLAYGROUND "Build storage with tests" ON)

file(GLOB_RECURSE SRC_STORAGE . *.hpp *.cpp)

set(SRC_PG ../../tests/playground/StorageEnginePG.cpp)

if (STORAGE_SHARED)
    add_library(storage SHARED EXCLUDE_FROM_ALL ${SRC_STORAGE})
else()
    add_library(storage STATIC EXCLUDE_FROM_ALL ${SRC_STORAGE} BlockManager.cpp)
endif()

set_target_properties(storage PROPERTIES VERSION ${BUILD_VERSION} SOVERSION ${BUILD_MAJOR})
target_link_libraries(storage cppfs)
target_include_directories(storage PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

if (STORAGE_PLAYGROUND OR BUILD_STORAGE)
    add_executable(storage_pg ${SRC_PG})
    target_link_libraries(storage_pg storage cppfs)
    target_include_directories(storage_pg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
    )
endif()