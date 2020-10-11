//
// Created by fress on 11-Oct.-20.
//

#include <iostream>
#include "fast_tests.hpp"
#include "Matrix.hpp"

const vector<double> EIGHT_VALUES {1.0, 2.1, 3.1, 4.1, 5.5, 6.1, 7.1, 8.1, 9.1};
const vector<double> NINE_VALUES {1.1, 1.1, 1.1, 1.1, 5.5, 1.1, 1.1, 1.1, 1.1};
const vector<double> ANOTHER_NINE_VALUES {13.1, 1.1, 1.1, 1.1, 5.5, 1.1, 1.1, 1.1, 1.1};

void testEmptyConstructor() {
    Matrix m;

    cout << "Col count is " << m.get_col_count() << endl;
    cout << "Row count is " << m.get_row_count() << endl;
}

void testInitialValuesConstructor() {

    string result;
    Matrix m(NINE_VALUES);
    double val = m.get_value(1, 1);

    if (val == 5.5) {
        result = "PASS";
    } else {
        result = "FAIL";
    }

    cout << "testInitialValuesConstructor " << result << "\n" << endl;
}

void testInitialValuesConstructorThrowsException() {
    try {
        Matrix m(EIGHT_VALUES);
        cout << "testInitialValuesConstructorThrowsException FAIL\n" << endl;
    } catch (invalid_argument& e) {
        cout << "testInitialValuesConstructorThrowsException PASS\n" << endl;
    }
}

void testIncrement() {
    Matrix m(NINE_VALUES);
    cout << m << endl;

    m++;
    cout << m << endl;
}

void testEqualsEquals() {
    Matrix a(NINE_VALUES);
    Matrix b(ANOTHER_NINE_VALUES);

    if (a == b) {
        cout << "TEST: '== works': PASS" << endl;
    } else {
        cout << "TEST: '== works': FAIL" << endl;
    }
}