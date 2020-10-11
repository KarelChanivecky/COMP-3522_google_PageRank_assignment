/**
 * 9/25/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * Clinton Fernandes
 * A01 182 058
 *
 * BCIT CST
 * Set O Datacomm
 * COMP - 3522
 *
 * Assignment 1
 */

#define CATCH_CONFIG_MAIN
#include "Connectivity_Matrix.hpp"
#include "catch.hpp"
#include "Stochastic_Matrix.hpp"

TEST_CASE("CONNECTIVITY all values are correct") {
    vector<double> values { 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
    vector<string> pageNames{"A", "B", "C"};
    vector<vector<double>> expected {{0.0, 1.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}};
    Connectivity_Matrix result{ values, pageNames};
    REQUIRE(expected == result.get_matrix());
}

TEST_CASE( "CONNECTIVITY incorrect size throws exception" ) {
    vector<double> values { 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };
    vector<string> pageNames{"A", "B", "C"};
    bool  exception_thrown = false;
    try {
        Connectivity_Matrix result{ values, pageNames};
    } catch ( invalid_argument &e) {
        exception_thrown = true;
    }
    REQUIRE(exception_thrown);
}

TEST_CASE("CONNECTIVITY matrix size 1") {
    vector<double> values { 0.0 };
    vector<string> pageNames{"A"};
    vector<vector<double>> expected {{0.0}};
    Connectivity_Matrix result{ values, pageNames};
    REQUIRE(expected == result.get_matrix());
}

