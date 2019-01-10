//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <parser/parser.hpp>
#include <memory.h>
#include <string>

namespace {
    class ParserTestsFixture : public ::testing::Test {
    public:
        ParserTestsFixture() {}

        sql::Parser &parser = sql::Parser::Instance();

        virtual void SetUp() {}

        static void SetUpTestCase() {}

        virtual void TearDown() {};

        static void TearDownTestCase() {};
    };
}

TEST_F(ParserTestsFixture, CREATE_TABLE_TEST) {
    // init test input and expected results
    std::vector<std::shared_ptr<cmd::Instruction>> instructions;
    std::vector<std::string> create_table_instructions{
            "CREATE TABLE students(id INTEGER);",
    };

    std::vector<cmd::InstructionType> expected_instruction_types{
            cmd::InstructionType::CREATE_TABLE,
    };

    std::vector<std::vector<std::string>> expected_definitions{
            {"default", "public", "students"},
    };

    //parse queues and get instructions
    for (const auto &create_table_instruction : create_table_instructions) {
        instructions.push_back(parser.Process(create_table_instruction)[0]);
    }


    //check got instructions data and expected data
    for (int i = 0; i < instructions.size(); ++i) {
        ASSERT_EQ(expected_instruction_types[i], instructions[i].get()->type());

        ASSERT_EQ(expected_definitions[i][0], dynamic_cast<cmd::CreateTable*>(instructions[0].get())->table_.database_);
        ASSERT_EQ(expected_definitions[i][1], dynamic_cast<cmd::CreateTable*>(instructions[0].get())->table_.schema_);
        ASSERT_EQ(expected_definitions[i][2], dynamic_cast<cmd::CreateTable*>(instructions[0].get())->table_.name_);

    }
}