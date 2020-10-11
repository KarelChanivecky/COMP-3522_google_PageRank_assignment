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

#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include "Connectivity_Matrix.hpp"
#include "Stochastic_Matrix.hpp"
#include "Page_Ranker.hpp"

using namespace std;

#define DEFAULT_FILENAME "connectivity.txt"

void driver() {
    vector<double> * connections = get_connections(( string & ) DEFAULT_FILENAME );
    vector<string> * pages = assemble_pages(*connections);
    Connectivity_Matrix conn_matrix{*connections, *pages};
    Stochastic_Matrix sto_matrix{conn_matrix};
    Matrix * ranks = rank_pages(sto_matrix);



//    cout << *ranks << endl;
    delete connections;
    delete pages;
    delete ranks;
}

void testEmptyConstructor() {
    Matrix m;

    cout << "Col count is " << m.get_col_count() << endl;
    cout << "Row count is " << m.get_row_count() << endl;
}

void testInitialValuesConstructor() {
    const vector<double> NINE_VALUES {1.1, 1.1, 1.1, 1.1, 5.5, 1.1, 1.1, 1.1, 1.1};
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
    const vector<double> EIGHT_VALUES {1.0, 2.1, 3.1, 4.1, 5.5, 6.1, 7.1, 8.1, 9.1};
    try {
        Matrix m(EIGHT_VALUES);
        cout << "testInitialValuesConstructorThrowsException FAIL\n" << endl;
    } catch (invalid_argument& e) {
        cout << "testInitialValuesConstructorThrowsException PASS\n" << endl;
    }
}

int main() {
//    driver();

    testEmptyConstructor();
    testInitialValuesConstructor();
    testInitialValuesConstructorThrowsException();

    return 0;
}


