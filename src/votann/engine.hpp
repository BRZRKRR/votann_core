#pragma once
#include "portfolio.hpp"
#include "data_row.hpp"

namespace votann {

	class BacktestEngine {
	public:
		BacktestEngine() = delete;
    	BacktestEngine(Portfolio& portfolio);
		void load_and_run(const std::string& filename);


	private:
		Portfolio& portfolio_;
	};

}
