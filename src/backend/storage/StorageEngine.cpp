//
// Created by truefinch on 02.11.18.
//

#include <iostream>
#include <fstream>
#include "StorageEngine.h"
#include "../include/json.hpp"

bool se::StorageEngine::create(std::string name, std::vector<tables::Column> columns) {
    _tables.insert(std::pair<std::string, tables::Table>(name, tables::Table(name, columns)));
    //TODO: remove columns with some stream of pare values - column name and column type
    if (flush())
        return true;
    else false;
}

using json = nlohmann::json;

bool se::StorageEngine::flush() {
    json j;
    for (auto& table : _tables) {
        j[table.first] = table.second.getColumns();
    }

    std::string result = j.dump();
    std::ofstream fout("../database/tables.json");
    //Debug
//    std::cout << result;
    fout << result;
    fout.flush();
    fout.close();
}
