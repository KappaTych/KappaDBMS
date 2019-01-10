//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
    class StorageEngineTestsFixture : public ::testing::Test {
    public:
        StorageEngineTestsFixture() {}

        virtual void SetUp() {}

        static void SetUpTestCase() {}

        virtual void TearDown() {};

        static void TearDownTestCase() {};
    };
}

TEST_F(StorageEngineTestsFixture, TEST1) {
    ASSERT_EQ(1, 1);
}