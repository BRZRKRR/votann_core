#include "votann/engine.hpp"
#include "votann/portfolio.hpp"

int main() {
    votann::Portfolio portfolio;
    votann::BacktestEngine engine(portfolio);

    const std::string filename = "data/cryptodata_bybit_CRVTAOLTC_1m.csv";
    engine.load_and_run(filename);

    return 0;
}

