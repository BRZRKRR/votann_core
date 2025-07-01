cmake_minimum_required(VERSION 3.20)
project(votann_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(votann_core ${SOURCES})
