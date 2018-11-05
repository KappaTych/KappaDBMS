//
// Created by truefinch on 02.11.18.
//

#include "StorageEngine.h"

bool se::StorageEngine::create(std::string name, std::vector<tables::Column> columns) {
    _tables.emplace_back(tables::Table(name, columns));
    //TODO: remove columns with some stream of pare values - column name and column type
}
