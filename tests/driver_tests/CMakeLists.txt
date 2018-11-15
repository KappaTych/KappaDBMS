include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(driver_tests_run
        DriverTestsFixture.cpp
        )

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../src/backend/driver ${CMAKE_CURRENT_BINARY_DIR}/src/backend/driver)

target_link_libraries(driver_tests_run driver gtest gtest_main gmock gmock_main)
target_include_directories(driver_tests_run PUBLIC
        ../../src/backend
        ../../src/backend/include
        )