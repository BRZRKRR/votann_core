#!/bin/bash

set -e

PROJECT_ROOT="votann_core"

echo "📁 Creating project structure..."

mkdir -p ${PROJECT_ROOT}/{src/votann,src/strategies,configs,data,scripts,tests,build}

echo "📄 Generating initial CMakeLists.txt..."

cat > ${PROJECT_ROOT}/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.20)
project(votann_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
include_directories(\${CMAKE_SOURCE_DIR}/src)

add_executable(votann_core \${SOURCES})
EOF

echo "🧠 Generating source files..."

# --- src/main.cpp ---
cat > ${PROJECT_ROOT}/src/main.cpp <<EOF
#include <iostream>

int main() {
    std::cout << "Hello from votann_core!" << std::endl;
    return 0;
}
EOF

# --- src/votann/logger.hpp ---
cat > ${PROJECT_ROOT}/src/votann/logger.hpp <<EOF
#pragma once
#include <string>

namespace votann {

void LogInfo(const std::string& message);
void LogError(const std::string& message);

}
EOF

# --- src/votann/logger.cpp ---
cat > ${PROJECT_ROOT}/src/votann/logger.cpp <<EOF
#include "logger.hpp"
#include <iostream>

namespace votann {

void LogInfo(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

void LogError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}

}
EOF

# --- Example engine.hpp/cpp skeleton ---
cat > ${PROJECT_ROOT}/src/votann/engine.hpp <<EOF
#pragma once

namespace votann {

class BacktestEngine {
public:
    void Run();
};

}
EOF

cat > ${PROJECT_ROOT}/src/votann/engine.cpp <<EOF
#include "engine.hpp"
#include "logger.hpp"

namespace votann {

void BacktestEngine::Run() {
    LogInfo("BacktestEngine is running.");
}

}
EOF

# --- Example strategy interface ---
cat > ${PROJECT_ROOT}/src/strategies/strategy_interface.hpp <<EOF
#pragma once

namespace votann {

class IStrategy {
public:
    virtual void onCandle() = 0;
    virtual ~IStrategy() = default;
};

}
EOF

# --- Placeholder test file ---
cat > ${PROJECT_ROOT}/tests/votann_test.cpp <<EOF
#include <iostream>

int main() {
    std::cout << "Running basic VOTANN test..." << std::endl;
    return 0;
}
EOF

echo "🚀 Done! Your minimal votann_core project is ready at ./${PROJECT_ROOT}"

