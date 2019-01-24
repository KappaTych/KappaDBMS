//
// Created by truefinch on 16.11.18.
//

#include <vector>
#include <exception>
#include <memory>

#include <gtest/gtest.h>
#include <driver/driver.hpp>
#include <json.hpp>

namespace {
    using json = nlohmann::json;

    class DriverTestsFixture : public ::testing::Test {
    public:
        virtual void SetUp() {}

        static void SetUpTestCase() {}

        virtual void TearDown() {};

        static void TearDownTestCase() {};
    };
}

TEST_F(DriverTestsFixture, CREATE_TABLE_TEST_1)
{
    sql::Driver& driver = sql::Driver::Instance();
    try {
        driver.RunQuery("DROP TABLE products");
    }
    catch (std::logic_error& error) {}
    std::string create_query = "CREATE TABLE products (id INTEGER, count INTEGER, price DOUBLE, description TEXT);";
    std::string result = driver.RunQuery(create_query);

    std::vector<sql::Table> expected_result;
    sql::Table expected_table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<sql::BoolField>(true)} });
    expected_table.name_.name_ = "CREATE TABLE products (id INTEGER, count INTEGER, price DOUBLE, description TEXT)";
    expected_result.push_back(expected_table);
    json expected_json;
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F(DriverTestsFixture, INSERT_TEST_1_1)
{
    sql::Driver& driver = sql::Driver::Instance();
    std::string result;
    std::vector<sql::Table> expected_result;
    sql::Table expected_table;
    json expected_json;

    expected_table = sql::Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<sql::BoolField>(true)} });
    expected_table.name_.name_ = "INSERT INTO products VALUES (1, 1, 12.24, 'Book')";
    expected_result.push_back(expected_table);
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;
    result = driver.RunQuery("INSERT INTO products VALUES (1, 1, 12.24, 'Book');");

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F(DriverTestsFixture, INSERT_TEST_1_2)
{
    sql::Driver& driver = sql::Driver::Instance();
    std::string result;
    std::vector<sql::Table> expected_result;
    sql::Table expected_table;
    json expected_json;

    expected_table = sql::Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<sql::BoolField>(true)} });
    expected_table.name_.name_ = "INSERT INTO products VALUES (2, 2, 13.36, 'Axe')";
    expected_result.push_back(expected_table);
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;
    result = driver.RunQuery("INSERT INTO products VALUES (2, 2, 13.36, 'Axe');");

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F(DriverTestsFixture, INSERT_TEST_1_3)
{
    sql::Driver& driver = sql::Driver::Instance();
    std::string result;
    std::vector<sql::Table> expected_result;
    sql::Table expected_table;
    json expected_json;

    expected_table = sql::Table({ {"result", cmd::LiteralType::BOOL} }, { {std::make_shared<sql::BoolField>(true)} });
    expected_table.name_.name_ = "INSERT INTO products VALUES (3, 4, 228.228, 'Computer')";
    expected_result.push_back(expected_table);
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;
    result = driver.RunQuery("INSERT INTO products VALUES (3, 4, 228.228, 'Computer');");

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F (DriverTestsFixture, SELECT_ALL_1)
{
    sql::Driver& driver = sql::Driver::Instance();
    std::string result;
    std::vector<sql::Table> expected_result;
    sql::Table expected_table;
    json expected_json;

    expected_table = sql::Table({"SELECT * FROM products "},
        {
          {"id", cmd::LiteralType::INTEGER},
          {"count", cmd::LiteralType::INTEGER},
          {"price", cmd::LiteralType::DOUBLE},
          {"description", cmd::LiteralType::TEXT}
        },
        {
          {
            std::make_shared<sql::IntField>(sql::IntField(1)),
            std::make_shared<sql::IntField>(sql::IntField(1)),
            std::make_shared<sql::DoubleField>(sql::DoubleField(12.24)),
            std::make_shared<sql::TextField>(sql::TextField("Book"))
          },
          {
            std::make_shared<sql::IntField>(sql::IntField(2)),
            std::make_shared<sql::IntField>(sql::IntField(2)),
            std::make_shared<sql::DoubleField>(sql::DoubleField(13.36)),
            std::make_shared<sql::TextField>(sql::TextField("Axe"))
          },
          {
            std::make_shared<sql::IntField>(sql::IntField(3)),
            std::make_shared<sql::IntField>(sql::IntField(4)),
            std::make_shared<sql::DoubleField>(sql::DoubleField(228.228)),
            std::make_shared<sql::TextField>(sql::TextField("Computer"))
          },
        });
    expected_result.push_back(expected_table);
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;
    result = driver.RunQuery("SELECT * FROM products;");

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F(DriverTestsFixture, SELECT_WHERE_1)
{
    sql::Driver& driver = sql::Driver::Instance();
    std::string result;
    std::vector<sql::Table> expected_result;
    sql::Table expected_table;
    json expected_json;
    expected_table = sql::Table({"SELECT id, description FROM products where id = 1"},
        {
             {"id", cmd::LiteralType::INTEGER},
             {"description", cmd::LiteralType::TEXT}
        },
        {
          {
             std::make_shared<sql::IntField>(sql::IntField(1)),
             std::make_shared<sql::TextField>(sql::TextField("Book"))
          }
        });
    expected_result.push_back(expected_table);
    expected_json["code"] = 1;
    expected_json["result"] = expected_result;
    result = driver.RunQuery("SELECT id, description FROM products where id = 1;");

    ASSERT_EQ(expected_json.dump(), result);
}

TEST_F(DriverTestsFixture, SELECT_WHERE_2)
{

}

TEST_F(DriverTestsFixture, DROP_TABLE_1)
{
    sql::Driver& driver = sql::Driver::Instance();
    driver.RunQuery("DROP TABLE products");
    ASSERT_THROW(driver.RunQuery("DROP TABLE products"), std::logic_error);
}