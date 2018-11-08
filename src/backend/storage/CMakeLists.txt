cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(KappaStorage)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "0")
set(BUILD_VERSION "1")
set(BUILD_VERSION ${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_VERSION})

option(STORAGE_SHARED "Make storage shared library" OFF)
option(STORAGE_TEST "Build storage with tests" OFF)

file(GLOB_RECURSE SRC_STORAGE . src/backend/storage/*.cpp)

set(SRC_TESTS
../../../tests/StorageEngineTest.cpp
)

if (STORAGE_SHARED)
    add_library(storage SHARED EXCLUDE_FROM_ALL ${SRC_STORAGE})
else()
    add_library(storage STATIC EXCLUDE_FROM_ALL ${SRC_STORAGE})
endif()

set_target_properties(storage PROPERTIES VERSION ${BUILD_VERSION} SOVERSION ${BUILD_MAJOR})

if (STORAGE_TEST)
    add_executable(storage_test ${SRC_TESTS})
    target_link_libraries(storage_test storage)
    target_include_directories(storage_test PUBLIC
        ../include
    )
endif()
