#pragma once
#include "data_row.hpp"

class IStrategy {
public:
    virtual void onData(const DataRow<9>& row) = 0;
    virtual ~IStrategy() = default;
};
