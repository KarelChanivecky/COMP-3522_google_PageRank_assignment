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
#include "Stochastic_Matrix.hpp"
#include "catch.hpp"

TEST_CASE("STOCHASTIC normalization for one page, connected, is correct") {
    vector<double> values { 1.0 };
    vector<string> pageNames{"A"};
    vector<vector<double>> expected {{1.0}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix result{cm};
    REQUIRE(expected == result.get_matrix());
}

TEST_CASE("STOCHASTIC normalization for one page, not connected, is correct") {
    vector<double> values { 0.0 };
    vector<string> pageNames{"A"};
    vector<vector<double>> expected {{1.0}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix result{cm};
    REQUIRE(expected == result.get_matrix());
}

TEST_CASE( "STOCHASTIC normalization for more than one page, not all connected, is correct" ) {
    vector<double> values { 0.0, 1.0, 0.0,
                            1.0, 0.0, 0.0,
                            0.0, 1.0, 0.0 };
    vector<string> pageNames{"A", "B", "C"};
    vector<vector<double>> expected {{0.0, 1.0, 0}, {0.5, 0.0, 0.5}, {0.3333333333, 0.3333333333, 0.3333333333}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix result{cm};
    REQUIRE( expected == result.get_matrix() );
}

TEST_CASE( "STOCHASTIC normalization for more than one page, all connected, is correct" ) {
    vector<double> values { 0.0, 1.0, 1.0,
                            1.0, 0.0, 1.0,
                            0.0, 1.0, 1.0 };
    vector<string> pageNames{"A", "B", "C"};
    vector<vector<double>> expected {{0.0, 1, 0.0},  {0.5, 0.0, 0.5}, {0.3333333333, 0.3333333333, 0.3333333333}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix result{cm};
    REQUIRE( expected == result.get_matrix() );
}