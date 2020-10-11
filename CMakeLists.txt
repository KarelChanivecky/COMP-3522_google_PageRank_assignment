cmake_minimum_required(VERSION 3.15)
project(assignment1_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment1_v2 main.cpp Matrix.cpp Matrix.hpp Page_Matrix.cpp
        Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp Stochastic_Matrix.cpp
        Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)

add_executable(test_connectivity_matrix test_connectivity_matrix.cpp Matrix.cpp Matrix.hpp Page_Matrix.cpp
        Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp Stochastic_Matrix.cpp
        Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)

add_executable(test_matrix test_matrix.cpp catch.hpp Matrix.cpp Matrix.hpp Page_Matrix.cpp
        Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp Stochastic_Matrix.cpp
        Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)

add_executable(test_page_rank test_page_rank.cpp catch.hpp Matrix.cpp Matrix.hpp Page_Matrix.cpp
        Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp Stochastic_Matrix.cpp
        Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)

add_executable(test_stochastic_matrix test_stochastic_matrix.cpp catch.hpp catch.hpp Matrix.cpp
        Matrix.hpp Page_Matrix.cpp Page_Matrix.hpp Connectivity_Matrix.cpp Connectivity_Matrix.hpp
        Stochastic_Matrix.cpp Stochastic_Matrix.hpp Page_Ranker.cpp Page_Ranker.hpp)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wa,-mbig-obj")
