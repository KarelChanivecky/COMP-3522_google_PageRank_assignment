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
#include <stdexcept>
#include "catch.hpp"
#include "Matrix.hpp"

using namespace std;

const vector<double> NINE_VALUES {1.1, 1.1, 1.1, 1.1, 5.5, 1.1, 1.1, 1.1, 1.1};
const vector<double> EIGHT_VALUES {1.0, 2.1, 3.1, 4.1, 5.5, 6.1, 7.1, 8.1, 9.1};

TEST_CASE( "0 param constructor", "Matrix constructor test" ) {
    Matrix m;

    REQUIRE(m.get_col_count() == DEFAULT_VAL);
    REQUIRE(m.get_row_count() == DEFAULT_VAL);
}

TEST_CASE("Matrix with initial values", "Matrix constructor test" ) {
    Matrix m(NINE_VALUES);
    double val = m.get_value(1, 1);
    REQUIRE(val == 5.5);
}

TEST_CASE("Matrix with initial values and non-integer square root") {
    bool exceptionThrown = false;
    try {
        Matrix m(EIGHT_VALUES);
    } catch (invalid_argument& e) {
        exceptionThrown = true;
    }

    REQUIRE(exceptionThrown);
}