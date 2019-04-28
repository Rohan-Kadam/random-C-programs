cmake_minimum_required (VERSION 2.6)
project (CMake)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(CMake main.cpp)
