//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <ClassToTestCodeCoverage.h>

namespace {
    class StorageEngineTestsFixture : public ::testing::Test {
    public:
        ClassToTestCodeCoverage obj;
        StorageEngineTestsFixture() {}

        virtual void SetUp() {}

        static void SetUpTestCase() {}

        virtual void TearDown() {};

        static void TearDownTestCase() {};
    };
}

TEST_F(StorageEngineTestsFixture, TEST1) {
    ASSERT_EQ(obj.Print(), "Hello, World!");
}

TEST_F(StorageEngineTestsFixture, TEST2) {
    ASSERT_EQ(obj.Print1(0), "Hello, coveralls!");
}