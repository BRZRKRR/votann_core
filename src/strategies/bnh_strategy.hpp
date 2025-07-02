#pragma once
#include "../votann/strategy.hpp"
#include "../votann/logger.hpp"
#include <iostream>

class BuyAndHoldStrategy : public IStrategy {
	public:
		bool has_position = false;

		void onData(const DataRow<9>& row) override {
			if (!has_position) {
				std::cout << "[STRATEGY] Buying at " << row.prices[0] << " (timestamp: " << row.unix_timestamp << ")\n";
				has_position = true;
			}
		}
};
