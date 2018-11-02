#include <vector>

#include "sql-stmt/Table.h"

void create_table(sql::TableName, std::vector<sql::ColumnDefinition>);
void drop_table(sql::TableName);
void show_table(sql::TableName);