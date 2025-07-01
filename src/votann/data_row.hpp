#pragma once
#include <cstdint>
#include <array>
#include <istream>

template<size_t NUM_INST>
struct DataRow {
    uint64_t unix_timestamp;
    std::array<double, NUM_INST> prices;

    double& operator[](size_t index) { return prices[index]; }
    const double& operator[](size_t index) const { return prices[index]; }

    friend std::istream& operator>>(std::istream& is, DataRow& data) {
        char comma;
        is >> data.unix_timestamp >> comma;
        for (auto& price : data.prices) {
            is >> price >> comma;
        }
        return is;
    }
};
