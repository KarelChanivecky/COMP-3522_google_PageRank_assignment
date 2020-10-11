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
#include "Page_Ranker.hpp"
#include "catch.hpp"

TEST_CASE( "RANK normalization for more than one page, not all connected, is correct" ) {
    vector<double> values { 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0 };
    vector<string> pageNames{"A", "B", "C"};
    vector<vector<double>> expected {{0.0}, {1.0}, {0.0}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix sm{cm};
    Matrix * result = rank_pages(sm);
    REQUIRE( expected == result->get_matrix() );
}