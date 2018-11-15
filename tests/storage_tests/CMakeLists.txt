include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(storage_tests_run
        StorageEngineTestsFixture.cpp
        )

if (NOT TARGET storage)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../src/backend/storage ${CMAKE_CURRENT_BINARY_DIR}/src/backend/storage)
endif()

target_link_libraries(storage_tests_run storage gtest gtest_main gmock gmock_main)
target_include_directories(storage_tests_run PUBLIC
        ../../src/backend
        ../../src/backend/include
        )
#target_link_libraries(storage_tests_run ${CMAKE_PROJECT_NAME}_lib)