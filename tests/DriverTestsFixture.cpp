//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <driver/driver.hpp>

namespace {
    class DriverTestsFixture : public ::testing::Test {
    public:
        DriverTestsFixture() {}

        virtual void SetUp() {}

        static void SetUpTestCase() {}

        virtual void TearDown() {};

        static void TearDownTestCase() {};
    };
}

TEST_F(DriverTestsFixture, TEST1) {
    auto& instance = sql::Driver::Instance();
    std::string query = "CREATE TABLE students1 (id Text, id1 TEXT, idddd TEXT);";
    std::cout << instance.RunQuery(query) << std::endl;
}