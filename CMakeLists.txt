cmake_minimum_required(VERSION 3.17)
project(rgr)

set(CMAKE_CXX_STANDARD 14)

add_executable(rgr main.cpp data.hpp data.cpp)