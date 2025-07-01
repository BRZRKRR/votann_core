#include "engine.hpp"
#include <fstream>

votann::BacktestEngine::BacktestEngine(Portfolio& portfolio)
    : portfolio_(portfolio) {}

void votann::BacktestEngine::load_and_run(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        throw std::runtime_error("Failed to open: " + filename);
    }

    std::string header;
    std::getline(input, header);

    DataRow<9> row;
    while (input >> row) {
        portfolio_.processRow(row);
    }
}
