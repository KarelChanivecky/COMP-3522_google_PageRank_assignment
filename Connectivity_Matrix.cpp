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

#include <cmath>
#include <stdexcept>
#include "Connectivity_Matrix.hpp"

Connectivity_Matrix::Connectivity_Matrix(const vector<double> &connections, const vector<string> &new_pages ) :
Page_Matrix(new_pages) {
    double side_size = sqrt( connections.size());

    if ( floor( side_size) != side_size) {
        throw invalid_argument("Argument must have an integer square root");
    }

    col_count = (int) side_size;
    row_count = (int) side_size;

    for (unsigned int i = 0; i < connections.size(); ++i) {
        double val{connections[i]};
        if (val != 0 && val != 1) {
            throw invalid_argument("All elements in connections must have a value of 0 or 1");
        }
        matrix[i / side_size][i % (int)side_size] = val;
    }
}
