#include <iostream>

#include "dbStub.hpp"

void create_table(sql::TableName t, std::vector<sql::ColumnDefinition> v) {
	std::cout << "Success::CREATE" << t.schema << " " << t.name << std::endl;
	for (auto &e : v) {
		std::cout << e.name << " " << e.type << " ";
	}
	std::cout << std::endl;
}

void drop_table(sql::TableName t) {
	std::cout << "Success::Drop" << t.schema << " " << t.name << std::endl;
}

void show_table(sql::TableName t) {
	std::cout << "Success::SHOW" << t.schema << " " << t.name << std::endl;
}