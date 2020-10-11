/**
 * 10/10/2020
 * Created by Clinton Fernandes
 * A01 182 058
 *
 * BCIT CST
 * Set O Datacomm
 *
 * ${PROJECT_NAME}
 */

#include <stdexcept>
#include "catch.hpp"
#include "Matrix.hpp"

const vector<double> NINE_VALUES {1.1, 1.1, 1.1, 1.1, 5.5, 1.1, 1.1, 1.1, 1.1};
const vector<double> EIGHT_VALUES {1.0, 2.1, 3.1, 4.1, 5.5, 6.1, 7.1, 8.1, 9.1};

TEST_CASE( "0 param constructor" ) {
    Matrix m;

    REQUIRE(m.get_col_count() == 1);
    REQUIRE(m.get_row_count() == 1);
}

TEST_CASE("Matrix with initial values") {
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