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


TEST_CASE( "test 1" ) {
    vector<double> values{ 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0 };
    vector<string> * pageNames = assemble_pages( values );
    Connectivity_Matrix cm{ values, *pageNames };
    Stochastic_Matrix sm{ cm };
    Matrix * result = rank_pages( sm );
    vector<vector<double>> expected{{ 0.2309 },
                                    { 0.2309 },
                                    { 0.2564 },
                                    { 0.1046 },
                                    { 0.1772 }};
    delete pageNames;
    REQUIRE( expected == result->get_matrix());
    delete result;
}


TEST_CASE( "test 2" ) {
    vector<double> values{ 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 };
    vector<string> * pageNames = assemble_pages( values );
    Connectivity_Matrix cm{ values, *pageNames };
    Stochastic_Matrix sm{ cm };
    Matrix * result = rank_pages( sm );
    vector<vector<double>> expected{{ 0.3175 },
                                    { 0.3175 },
                                    { 0.3175 },
                                    { 0.0476 }};
    delete pageNames;
    REQUIRE( expected == result->get_matrix());
    delete result;
}


