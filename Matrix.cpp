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

#include <cmath>
#include "Matrix.hpp"

Matrix::Matrix( int cols, int rows ): col_count(cols), row_count(rows) {
    if (cols <= 0 || rows <= 0) {
        throw ("Values for columns and rows must be > 0");
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
        throw "Argument passed must have an integer square root\n";
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

}

double Matrix::get_value( int col, int row ) const {
    return 0;
}

void Matrix::clear() {

}

int Matrix::get_col_count() const {
    return 0;
}

int Matrix::get_row_count() const {
    return 0;
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

Matrix &Matrix::operator--() { // TODO clint
    return *this;
}

Matrix &Matrix::operator--( int ) { // TODO clint
    return <#initializer#>;
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

bool operator==( const Matrix &lhs, const Matrix &rhs ) { // TODO clint
    return false;
}

bool operator!=( const Matrix &lhs, const Matrix &rhs ) { // TODO clint
    return false;
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
