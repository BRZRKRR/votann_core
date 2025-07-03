#pragma once
#include "data_row.hpp"
#include <iostream>

class Logger {
private:
	std::string _path;
public:
	Logger(){}
	Logger(const std::string& path): _path(path) {}


    void log(const std::string& msg) {
        std::cout << msg;
        std::cout << std::endl;
    }
};

