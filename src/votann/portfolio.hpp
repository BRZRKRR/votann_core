#pragma once
#include "data_row.hpp"
#include "strategy.hpp"
#include "risk_manager.hpp"
#include "logger.hpp"



namespace votann {
	class Portfolio {
	public:
		Portfolio() = delete;
		Portfolio(std::unique_ptr<IStrategy> strategy);

		void processRow(const DataRow<9>& row);

	private:
		std::unique_ptr<IStrategy> strategy_;
		RiskManager risk_manager_;
		Logger logger_;
};
}
