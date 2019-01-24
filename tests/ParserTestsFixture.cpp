//
// Created by truefinch on 16.11.18.
//

#include <gtest/gtest.h>
#include <parser/parser.hpp>
#include <parser/sql.hpp>
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

    void assert_table_def(cmd::TableDefinition& exp_table_def, cmd::TableDefinition& table_def) {
        ASSERT_EQ(exp_table_def.name_, table_def.name_);
        ASSERT_EQ(exp_table_def.schema_, table_def.schema_);
        ASSERT_EQ(exp_table_def.database_, table_def.database_);
    }

    void assert_col_def(cmd::ColumnDefinition& e, cmd::ColumnDefinition& c) {
        ASSERT_EQ(e.name_, c.name_);
        ASSERT_EQ(e.type_, e.type_);
    }

    void assert_column(std::string name, cmd::Column left) {
        ASSERT_EQ(name, left.name_);
        ASSERT_TRUE(left.schema_.empty());
        ASSERT_TRUE(left.table_.empty());
    }

    void assert_column(cmd::Column name, cmd::Column left) {
        assert_column(name.name_, left);
    }

    void assert_column(std::string name, cmd::ptr_Expression& node) {
        ASSERT_EQ(cmd::COLUMN, node->type());
        auto left = std::static_pointer_cast<cmd::Column>(node);
        assert_column(name, *left);
    }

    void assert_literal(cmd::Literal& e_l, cmd::Literal& l) {
        ASSERT_EQ(e_l.ValueType(), l.ValueType());
        ASSERT_EQ(e_l.Value(), l.Value());
    }

    void assert_literal(cmd::LiteralType type, std::string value, cmd::ptr_Expression &node) {
        ASSERT_EQ(cmd::LITERAL, node->type());
        auto right = std::static_pointer_cast<cmd::Literal>(node);
        ASSERT_EQ(type, right->ValueType());
        ASSERT_EQ(value, right->Value());
    }

    void assert_operator(cmd::OperationType type, cmd::ptr_Expression& node) {
        ASSERT_EQ(cmd::OPERATION, node->type());
        ASSERT_EQ(type, std::static_pointer_cast<cmd::Operation>(node)->operation());
    }

    std::shared_ptr<cmd::BinaryOperation> cast_b(cmd::ptr_Expression& exp) {
        return std::static_pointer_cast<cmd::BinaryOperation>(exp);
    }

    std::shared_ptr<cmd::UnaryOperation> cast_u(cmd::ptr_Expression& exp) {
        return std::static_pointer_cast<cmd::UnaryOperation>(exp);
    }

}

TEST_F(ParserTestsFixture, CREATE_TABLE)
{
    // init test input and expected results
    std::string create_sql (
            "CREATE TABLE students (id INTEGER);"
            "CREATE TABLE text_table (title Text, co TEXT, add TEXT);"
            "CREATE TABLE double_id (scalar DOUBLE);"
            "CREATE TABLE integer_id (s INTEGER);"
    );
    int exp_size_tree = 4;
    auto exp_type = cmd::InstructionType::CREATE_TABLE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"students"},
            {"text_table"},
            {"double_id"},
            {"integer_id"},
    };

     std::vector<std::list<cmd::ColumnDefinition>> exp_column_def {
             {{"id", cmd::LiteralType::INTEGER}},
             {{"title", cmd::LiteralType::TEXT}, {"co", cmd::LiteralType::TEXT}, {"add", cmd::LiteralType::TEXT}},
             {{"scalar", cmd::LiteralType::DOUBLE}},
             {{"s", cmd::LiteralType::INTEGER}}
     };

    auto tree = parser.Process(create_sql);

    ASSERT_EQ(exp_size_tree, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto create = std::static_pointer_cast<cmd::CreateTable>(tree[i]);

        assert_table_def(exp_table_def[i], create->table_);

        ASSERT_EQ(exp_column_def[i].size(), create->columns_.size());
        auto& columns = create->columns_;
        for (auto exp_col = exp_column_def[i].begin(), col = columns.begin();
                col != columns.end(); ++col, ++exp_col) {
            assert_col_def(*exp_col, *col);
        }
    }
}

TEST_F(ParserTestsFixture, DROP_TABLE)
{
    std::string drop_table(
            "Drop table t;"
            "drop table leee");
    int exp_tree_size = 2;
    cmd::InstructionType exp_type = cmd::DROP_TABLE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"t"}, {"leee"}
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(exp_tree_size, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto drop = std::static_pointer_cast<cmd::DropTable>(tree[i]);

        assert_table_def(exp_table_def[i], drop->table_);
    }
}

TEST_F(ParserTestsFixture, SHOW_TABLE)
{
    std::string drop_table(
            "show table stud;"
            "show table stud1");
    int exp_tree_size = 2;
    cmd::InstructionType exp_type = cmd::SHOW_CREATE_TABLE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"stud"}, {"stud1"}
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(exp_tree_size, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto show = std::static_pointer_cast<cmd::ShowCreateTable>(tree[i]);

        assert_table_def(exp_table_def[i], show->table_);
    }
}

TEST_F(ParserTestsFixture, SELECT_ALL)
{
    std::string drop_table(
            "SElECT * from t;");
    int exp_size_tree = 1;
    cmd::InstructionType exp_type = cmd::SELECT_ALL;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"t"}
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(exp_size_tree, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto select = std::static_pointer_cast<cmd::Select>(tree[i]);

        assert_table_def(exp_table_def[i], select->table_);

        ASSERT_TRUE(select->columnDef_.empty());

        ASSERT_EQ(nullptr, select->where_);
    }
}

TEST_F(ParserTestsFixture, SELECT_COLUMN)
{
    std::string drop_table(
            "select a, -b + 1, c * 234 from t;");
    int exp_size_tree = 1;
    cmd::InstructionType exp_type = cmd::SELECT;

    cmd::TableDefinition exp_table_def {
            {"t"}
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(exp_size_tree, tree.size());

    ASSERT_EQ(exp_type, tree[0]->type());
    auto select = std::static_pointer_cast<cmd::Select>(tree[0]);

    assert_table_def(exp_table_def, select->table_);

    ASSERT_EQ(nullptr, select->where_);

    auto col_def = select->columnDef_.begin();
    {
        assert_column("a", *col_def);
    }
    ++col_def;
    {
        assert_operator(cmd::OperationType::PLUS, *col_def);
        auto node = cast_b(*col_def);
        assert_operator(cmd::OperationType::UNARY_MINUS, node->left_);
        {
            auto b = cast_u(node->left_);
            assert_column("b", b->operator_);
        }
        assert_literal(cmd::LiteralType::INTEGER, "1", node->right_);
    }
    ++col_def;
    {
        assert_operator(cmd::OperationType::MULTIPLY, *col_def);
        auto node = cast_b(*col_def);
        assert_column("c", node->left_);
        assert_literal(cmd::LiteralType::INTEGER, "234", node->right_);
    }
}

TEST_F(ParserTestsFixture, SELECT_WHERE)
{
    std::string select_where(
            "SElECT * from t where ee == 12 and dd  > 1");
    int exp_size_tree = 1;
    cmd::InstructionType exp_type = cmd::SELECT_ALL;

    std::vector<cmd::TableDefinition> exp_table_def {
        {"t"}
    };

    auto tree = parser.Process(select_where);

    ASSERT_EQ(tree.size(), exp_size_tree);

    ASSERT_EQ(tree[0]->type(), exp_type);
    auto select = std::static_pointer_cast<cmd::Select>(tree[0]);

    assert_table_def(exp_table_def[0], select->table_);

    ASSERT_TRUE(select->columnDef_.empty());

    // ee == 12 and dd  > 1
    assert_operator(cmd::OperationType::AND, select->where_);
    auto and_ = cast_b(select->where_);
    {
        assert_operator(cmd::OperationType::EQUAL, and_->left_);
        auto node = cast_b(and_->left_);
        assert_column("ee", node->left_);
        assert_literal(cmd::LiteralType::INTEGER, "12", node->right_);
    }
    {
        assert_operator(cmd::OperationType::GREATER, and_->right_);
        auto node = cast_b(and_->right_);
        assert_column("dd", node->left_);
        assert_literal(cmd::LiteralType::INTEGER, "1", node->right_);
    }

}

TEST_F(ParserTestsFixture, INSERT_INTO)
{
    std::string insert_sql (
            "insert into table_name values (123, 'test', 12.1); "
            "insert into table_name field1, field2 values ('1', '2');");
    auto size_tree = 2;
    auto exp_type = cmd::InstructionType::INSERT;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"table_name"},
            {"table_name"},
    };

    std::vector<std::list<cmd::Column>> exp_into {
            {},
            {{"field1"}, {"field2"}},
    };

    std::vector<std::list<cmd::Literal>> exp_value {
            {{cmd::Literal((long long)123), cmd::Literal(std::string("test")), cmd::Literal((long double)12.1)}},
            {{cmd::Literal(std::string("1")), cmd::Literal(std::string("2"))}}
    };

    auto tree = parser.Process(insert_sql);

    ASSERT_EQ(size_tree, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto insert = std::static_pointer_cast<cmd::Insert>(tree[i]);

        assert_table_def(exp_table_def[i], insert->table_);

        auto& into_ = insert->into_;
        ASSERT_EQ(exp_into[i].size(), into_.size());
        for (auto exp_col = exp_into[i].begin(), col = into_.begin();
             col != into_.end(); ++col, ++exp_col) {
            assert_column(*exp_col, *col);
        }

        auto& value_ = insert->values_;
        ASSERT_EQ(exp_value[i].size(), value_.size());
        for (auto exp_lit = exp_value[i].begin(), lit = value_.begin();
             lit != value_.end(); ++lit, ++exp_lit) {
            assert_literal(*exp_lit, *lit);
        }

    }
}

TEST_F(ParserTestsFixture, DELETE)
{
    std::string drop_table(
            "delete from table_name");
    int exp_tree_size = 1;
    cmd::InstructionType exp_type = cmd::DELETE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"table_name"},
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(exp_tree_size, tree.size());
    for (int i = 0; i < tree.size(); ++i) {
        ASSERT_EQ(exp_type, tree[i]->type());
        auto delete_ = std::static_pointer_cast<cmd::Delete>(tree[i]);

        assert_table_def(exp_table_def[i], delete_->table_);

        ASSERT_EQ(nullptr, delete_->where_);
    }

}

TEST_F(ParserTestsFixture, DELETE_WHERE)
{
    std::string drop_table(
            "delete from table_name where qqq / 1");
    int exp_tree_size = 1;
    cmd::InstructionType exp_type = cmd::DELETE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"table_name"},
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(tree.size(), exp_tree_size);

    ASSERT_EQ(tree[0]->type(), exp_type);
    auto delete_ = std::static_pointer_cast<cmd::Delete>(tree[0]);

    assert_table_def(exp_table_def[0], delete_->table_);

    assert_operator(cmd::OperationType::DIVISION, delete_->where_);
    {
        auto node = cast_b(delete_->where_);
        assert_column("qqq", node->left_);
        assert_literal(cmd::LiteralType::INTEGER, "1", node->right_);
    }
}

TEST_F(ParserTestsFixture, UPDATE)
{
    std::string drop_table(
            "update table_name set field2 = 12 + field2, field3 = 'dd', field4 = 12.1");
    int exp_tree_size = 1;
    cmd::InstructionType exp_type = cmd::UPDATE;

    std::vector<cmd::TableDefinition> exp_table_def {
            {"table_name"},
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(tree.size(), exp_tree_size);

    ASSERT_EQ(tree[0]->type(), exp_type);
    auto update = std::static_pointer_cast<cmd::Update>(tree[0]);

    assert_table_def(exp_table_def[0], update->table_);

    ASSERT_EQ(update->where_, nullptr);

    auto setlist = update->setList_.begin();
    {
        assert_column("field2", setlist->first);
        assert_operator(cmd::OperationType::PLUS, setlist->second);
        auto node = cast_b(setlist->second);
        assert_literal(cmd::LiteralType::INTEGER, "12", node->left_);
        assert_column("field2", node->right_);
    }
    ++setlist;
    {
        assert_column("field3", setlist->first);
        assert_literal(cmd::LiteralType::TEXT, "dd", setlist->second);
    }
    ++setlist;
    {
        assert_column("field4", setlist->first);
        assert_literal(cmd::LiteralType::DOUBLE, "12.100000", setlist->second);
    }
}

TEST_F(ParserTestsFixture, UPDATE_WHERE)
{
    std::string drop_table(
            "update table_name set field2 = 12, field3 = 'dd' where 1 > 0");
    int exp_tree_size = 1;
    cmd::InstructionType exp_type = cmd::UPDATE;
    std::vector<cmd::TableDefinition> exp_table_def {
            {"table_name"},
    };

    auto tree = parser.Process(drop_table);

    ASSERT_EQ(tree.size(), exp_tree_size);

    ASSERT_EQ(tree[0]->type(), exp_type);
    auto update = std::static_pointer_cast<cmd::Update>(tree[0]);
    assert_table_def(exp_table_def[0], update->table_);

    auto setlist = update->setList_.begin();
    {
        assert_column("field2", setlist->first);
        assert_literal(cmd::LiteralType::INTEGER, "12", setlist->second);
    }
    ++setlist;
    {
        assert_column("field3", setlist->first);
        assert_literal(cmd::LiteralType::TEXT, "dd", setlist->second);
    }
    
    assert_operator(cmd::OperationType::GREATER, update->where_);
    {
        auto node = cast_b(update->where_);
        assert_literal(cmd::LiteralType::INTEGER, "1", node->left_);
        assert_literal(cmd::LiteralType::INTEGER, "0", node->right_);
    }
}