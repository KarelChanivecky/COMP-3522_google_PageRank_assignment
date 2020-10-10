/**
 * 10/10/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * BCIT CST
 * Set O Datacomm
 *
 * ${PROYECT_NAME}
 */

#include "catch.hpp"
#include "Page_Ranker.hpp"


TEST_CASE( "normalization for more than one page, not all connected, is correct" ) {
    vector<double> values { 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0 };
    vector<string> pageNames{"A", "B", "C"};
    vector<vector<double>> expected {{0.0}, {1.0}, {0.0}};
    Connectivity_Matrix cm{ values, pageNames};
    Stochastic_Matrix sm{cm};
    Matrix * result = rank_pages(sm);
    REQUIRE( expected == result->get_matrix() ); // move this method up the hierarchy to Matrix
}