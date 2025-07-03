#include "portfolio.hpp"

votann::Portfolio::Portfolio(std::unique_ptr<IStrategy> strategy)
    : strategy_(std::move(strategy)) {}

void votann::Portfolio::processRow(const DataRow<9>& row) {
    if (!risk_manager_.isAllowed(row)) return;
    strategy_->onData(row);
    logger_.log(row.unix_timestamp + "");
}
