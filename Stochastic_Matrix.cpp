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

#include "Stochastic_Matrix.hpp"

Stochastic_Matrix::Stochastic_Matrix( const Connectivity_Matrix &connectivity_matrix )  :
Page_Matrix(connectivity_matrix.get_pages()){
    vector<vector<double>> to_copy(connectivity_matrix.get_matrix());
    for ( int i = 0; i < to_copy.size(); ++i ) {
        for ( int j = 0; j < to_copy.size(); ++j ) {
            matrix[i][j] = to_copy[i][j];
        }
    }
    normalize();
}


double Stochastic_Matrix::get_col_val( const int col ) const {
    double sum = 0;
    for ( int row = 0; row < row_count; ++row ) {
        sum += matrix[col][row];
    }
    if (sum == 0) {
        throw std::runtime_error("zero division");
    }
    return 1.0 / sum;
}

void Stochastic_Matrix::assign_col_val(const int col, const double val) {
    for ( int row = 0; row < row_count; ++row ) {
        if (matrix[col][row] == 1) {
            matrix[col][row] = val;
        }
    }
}

void Stochastic_Matrix::assign_no_link_col_val( const int col, const double val ) {
    for ( int row = 0; row < row_count; ++row ) {
        matrix[col][row] = val;
    }
}

void Stochastic_Matrix::normalize() {
    for ( int col = 0; col < col_count; ++col ) {
        try {
            double val = get_col_val(col);
            assign_col_val(col, val);
        } catch ( std::runtime_error &e) {
            assign_no_link_col_val(col, 1.0 / row_count);
        }
    }
}
