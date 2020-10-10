/**
 * 10/2/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
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

Connectivity_Matrix::Connectivity_Matrix(const vector<double> &connections, const vector<string> &pages ) {
    double side_size = sqrt( connections.size());

    if ( floor( side_size) != side_size) {
        throw invalid_argument("Argument must have an integer square root");
    }

    col_count = (int) side_size;
    row_count = (int) side_size;

    for (int i = 0; i < connections.size(); ++i) {
        double val = connections.at(i);
        if (val != 0 && val != 1) {
            throw invalid_argument("All elements in connections must have a value of 0 or 1");
        }
        if (i % (int)side_size == 0) {
                matrix.emplace_back(vector<double>());
        }
        matrix[i / (int)side_size].emplace_back(val);
    }
}
