cmake_minimum_required(VERSION 3.15)
project(hp35)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(hp35 hp-35.cpp)
