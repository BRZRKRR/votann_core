#pragma once

namespace votann {

class IStrategy {
public:
    virtual void onCandle() = 0;
    virtual ~IStrategy() = default;
};

}
