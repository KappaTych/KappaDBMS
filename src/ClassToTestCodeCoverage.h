//
// Created by truefinch on 11.01.19.
//

#pragma once

#include <string>

class ClassToTestCodeCoverage {
public:
    ClassToTestCodeCoverage() = default;
    std::string Print() {
        return "Hello, World!";
    }
    std::string Print1(int i) {
        if (i == 1){
            return "Hello, travis!";
        } else {
            return "Hello, coveralls!";
        }
    }
};

