#include "dbStub.h"

#include <iostream>

void create_table(sql::TableName t, std::vector<sql::ColumnDefinition> v) {
	std::cout << "CREATE" << t.schema << " " << t.name;
	for (auto &e : v) {
		std::cout << e.name << " " << e.type;
	}
}

void drop_table(sql::TableName t) {
	std::cout << "Drop" << t.schema << " " << t.name;
}

void show_table(sql::TableName t) {
	std::cout << "SHOW" << t.schema << " " << t.name;
}