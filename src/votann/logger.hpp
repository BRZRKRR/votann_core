#pragma once
#include "data_row.hpp"
#include <iostream>

class Logger {
public:
    void log(const DataRow<9>& row) {
        std::cout << "[LOG] Timestamp: " << row.unix_timestamp << " | Prices: ";
        for (const auto& p : row.prices) std::cout << p << " ";
        std::cout << std::endl;
    }
};

