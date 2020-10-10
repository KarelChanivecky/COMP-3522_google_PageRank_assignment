cmake_minimum_required(VERSION 3.15)
project(assignment1_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment1_v2 main.cpp Matrix.cpp Matrix.hpp Page_Matrix.cpp Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp Stochastic_Matrix.cpp Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)