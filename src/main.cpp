#include "votann/engine.hpp"
#include "votann/portfolio.hpp"
#include "strategies/bnh_strategy.hpp"

int main() {
	auto strategy = std::make_unique<BuyAndHoldStrategy>();
    votann::Portfolio portfolio(std::move(strategy));
    votann::BacktestEngine engine(portfolio);

    const std::string filename = "data/cryptodata_bybit_CRVTAOLTC_1m.csv";
    engine.load_and_run(filename);

    return 0;
}

