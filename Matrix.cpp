/**
 * 10/1/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * BCIT CST COMP-3522
 * Set O Datacomm
 *
 * Assignment 1
 */

#include <cstdlib>
#include <exception>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;

Matrix::Matrix( int cols, int rows ): col_count(cols), row_count(rows) {
    if (cols <= 0 || rows <= 0) {
        throw std::invalid_argument("Values for columns and rows must be > 0");
    }

    for (int i = 0; i < rows; i++) {
        vector<double> row;

        for (int j = 0; j < cols; j++) {
            row.push_back(DEFAULT_VAL);
        }

        matrix.push_back(row);
    }
}

Matrix::Matrix( vector<double> initial_values ) {
    double vectorSize = sqrt(initial_values.size());

    if (floor(vectorSize) != vectorSize) {
        throw std::invalid_argument("Argument must have an integer square root");
    }

    col_count = floor(vectorSize);
    row_count = floor(vectorSize) ;

    for (int i = 0; i < vectorSize; i++) {
        vector<double> row;

        for (int j = 0; j < vectorSize; j++) {
            row.push_back(initial_values.at(i));
        }

        matrix.push_back(row);
    }
}

Matrix::Matrix( const Matrix &other_matrix ) {

}

Matrix::Matrix( vector<vector<double>> old_vector ) {

}

Matrix::~Matrix() {
    cout << "Matrix destructor" << endl;
}

bool Matrix::set_value( int col, int row, double val ) {
    if (col < 0 || row < 0) {
        throw std::invalid_argument("column and row must be >= 0");
    }

    if (col > get_col_count() || row > get_row_count()) {
        throw std::invalid_argument("column and row must not exceed matrix size");
    }

    matrix.at(row).at(col) = val;
}

double Matrix::get_value( int col, int row ) const {
    if (col < 0 || row < 0) {
        throw std::invalid_argument("column and row must be >= 0");
    }

    if (col > get_col_count() || row > get_row_count()) {
        throw std::invalid_argument("column and row must not exceed matrix size");
    }

    return matrix.at(row).at(col);
}

void Matrix::clear() {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            matrix.at(i).at(j) = 0.0;
        }
    }
}

Matrix &Matrix::operator++() {
    vector<vector<double>>::iterator out_ptr;
    for ( out_ptr = matrix.begin(); out_ptr < matrix.end(); out_ptr++ ) {
        vector<double>::iterator in_ptr;
        for (in_ptr = out_ptr->begin(); in_ptr < out_ptr->end(); in_ptr++) {
            *in_ptr++;
        }
    }
    return *this;
}

Matrix Matrix::operator++( int ) {
    Matrix temp(*this);
    operator++();
    return temp;
}

Matrix &Matrix::operator--() {
    for (int i = 0; i < get_col_count(); i++) {
        for (int j = 0; j < get_row_count(); j++) {
            double currentValue = get_value(i, j);

            currentValue == 1.0 ? set_value(i, j, (currentValue - 1)) : set_value(i, j, (currentValue - 0));
        }
    }

    return *this;
}

Matrix Matrix::operator--( int ) {
    const Matrix tmp(*this);
    operator--();

    return tmp;
}

void matrix_swap( Matrix &lhs, Matrix &rhs ) {
    swap(lhs.matrix, rhs.matrix);
    swap(lhs.row_count, rhs.row_count);
    swap(lhs.col_count, rhs.col_count);
}

Matrix &Matrix::operator=( Matrix rhs ) {
    matrix_swap( *this, rhs );
    return *this;
}

Matrix &Matrix::operator+=( const Matrix &rhs ) { // TODO clint
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &that ) {
    if (!sizes_match(*this, that)) {
        throw "Cannot perform subtraction. Sizes do not match!";
    }
    for ( int col = 0; col < col_count; ++col ) {
        for ( int row = 0; row < row_count; ++row ) {
            set_value(col, row, get_value(col, row) - that.get_value(col, row));
        }
    }
    return *this;
}

Matrix &Matrix::operator*=( double constant ) {
    vector<vector<double>>::iterator out_ptr;
    for ( out_ptr = matrix.begin(); out_ptr < matrix.end(); out_ptr++ ) {
        vector<double>::iterator in_ptr;
        for (in_ptr = out_ptr->begin(); in_ptr < out_ptr->end(); in_ptr++) {
            *in_ptr *= constant;
        }
    }
    return *this;
}

Matrix &Matrix::operator*=( const Matrix &that ) {
    if (that.row_count != this->col_count) {
        throw "Matrix multiplication error! incorrect sizes!";
    }
    vector<vector<double>> result;
    int result_col_count = that.col_count;
    int result_row_count = that.row_count;
    for ( int res_row = 0; res_row < result_row_count; res_row++) {
        for ( int res_col = 0; res_col < result_col_count; res_col++) {
            for (int dot_index = 0; dot_index < this->row_count; dot_index++) {
                result[res_col][res_row] += matrix[dot_index][res_row] * that.matrix[res_col][dot_index];
            }
        }
    }
    matrix = result;
    col_count = result_col_count;
    row_count = result_row_count;
    return *this;
}

bool operator==( const Matrix &lhs, const Matrix &rhs ) {
    double threshold = 0.001;

    if (! sizes_match(lhs, rhs)) {
        return false;
    }

    for ( int col = 0; col < lhs.get_col_count(); ++col ) {
        for ( int row = 0; row < lhs.get_row_count(); ++row ) {
            double lhValue = lhs.get_value(col, row);
            double rhValue = rhs.get_value(col, row);

            if (! Matrix::compare(lhValue, rhValue, threshold)) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=( const Matrix &lhs, const Matrix &rhs ) {
    return ! operator==(lhs, rhs);
}

Matrix operator+( Matrix lhs, const Matrix &rhs ) {
    lhs += rhs;
    return lhs;
}

Matrix operator-( Matrix lhs, const Matrix &rhs ) {
    lhs -= rhs;
    return lhs;
}

Matrix operator*( const Matrix lhs, const Matrix &rhs ) { // TODO clint
    return Matrix();
}

bool Matrix::compare(const double a, const double b, const double epsilon){
    return fabs(a - b) <= epsilon;
}

