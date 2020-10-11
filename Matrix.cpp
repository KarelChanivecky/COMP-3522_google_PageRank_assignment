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

Matrix::Matrix( const vector<double>& initial_values ) {
    double rowSize = sqrt(initial_values.size());

    if (floor(rowSize) != rowSize) {
        throw std::invalid_argument("Vector size must have an integer square root");
    }

    col_count = floor(rowSize);
    row_count = floor(rowSize);

    /*e.g. [5, 7, 10, 20], n = 4
     *
     * ==>  05 07
     *      10 20
     *
     *e.g. [6, 10, 27, 29, 30, 66, 77, 88, 99], n = 9
     *
     * =>   06 10 27
     *      29 30 66
     *      77 88 99
     *
     */

    vector<double> row;

    for (double value : initial_values) {
        if (value < 0) {
            throw std::invalid_argument("Matrix values must be >= 0");
        }

        if (row.size() == rowSize) {
            matrix.push_back(row);
            row.clear();
        }

        row.push_back(value);
    }
}

Matrix::Matrix( const Matrix &matrixToCopy ): col_count(matrixToCopy.get_col_count()), row_count(matrixToCopy.get_row_count()) {
    for (int col = 0; col < matrixToCopy.get_col_count(); col++) {
        for (int row = 0; row < matrixToCopy.get_row_count(); row++) {
            double value = matrixToCopy.get_value(col, row);

            set_value(col, row, value);
        }
    }
}

Matrix::Matrix( const vector<vector<double>> &old_vector ) : col_count(old_vector.size()),
row_count(old_vector.at(0).size()){
    for (const vector<double>& col : old_vector) {
        vector<double> new_col;
        for (double row: col) {
            new_col.emplace_back(row);
        }
        matrix.emplace_back(new_col);
    }
}

Matrix::~Matrix() {
    cout << "Matrix destructor" << endl;
}

void Matrix::set_value( int col, int row, double val ) {
    if (col < Matrix::MINIMUM_VALUE || row < Matrix::MINIMUM_VALUE) {
        throw std::invalid_argument("column and row must be >= 0");
    }

    if (col > get_col_count() || row > get_row_count()) {
        throw std::invalid_argument("column and row must not exceed matrix size");
    }

    matrix.at(row).at(col) = val;
}

double Matrix::get_value( int col, int row ) const {
    if (col < Matrix::MINIMUM_VALUE || row < Matrix::MINIMUM_VALUE) {
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

Matrix &Matrix::matrixIncrement(const Matrix &operand, const bool operationIsAddition) {
    const int amount = operationIsAddition ? 1 : -1;
    for ( int col = 0; col < col_count; ++col ) {
        for ( int row = 0; row < row_count; ++row ) {
            set_value(col, row, get_value(col, row) + amount);
            double currentValue = get_value(col, row);

            if (!operationIsAddition && currentValue < MINIMUM_VALUE) {
                set_value(col, row, Matrix::MINIMUM_VALUE);
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator++() {
    return matrixIncrement(*this, true);
}

Matrix Matrix::operator++( int ) {
    Matrix temp(*this);
    operator++();
    return temp;
}

Matrix &Matrix::operator--() {
    return matrixIncrement(*this, false);
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

Matrix &Matrix::operator+=( const Matrix &rhs ) {
   return matrixIncrementByAMatrix(rhs, true);
}

Matrix &Matrix::operator-=(const Matrix &that ) {
    return matrixIncrementByAMatrix(that, false);
}

Matrix &Matrix::matrixIncrementByAMatrix(const Matrix &operand, const bool operationIsAddition) {
    const int factor = operationIsAddition ? 1 : -1;

    if (!sizes_match(*this, operand)) {
        throw invalid_argument("Cannot perform operation: size mismatch");
    }
    for ( int col = 0; col < col_count; ++col ) {
        for ( int row = 0; row < row_count; ++row ) {
            set_value(col, row, get_value(col, row) + (factor * operand.get_value(col, row)));
            if (get_value(col, row) < MINIMUM_VALUE) {
                set_value(col, row, MINIMUM_VALUE);
            }
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
        throw invalid_argument("Matrix multiplication error! incorrect sizes!");
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
    if (! sizes_match(lhs, rhs)) {
        return false;
    }

    for ( int col = 0; col < lhs.get_col_count(); ++col ) {
        for ( int row = 0; row < lhs.get_row_count(); ++row ) {
            double lhValue = lhs.get_value(col, row);
            double rhValue = rhs.get_value(col, row);

            if (! Matrix::compare(lhValue, rhValue, Matrix::FLOAT_TOLERANCE)) {
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

Matrix operator*( Matrix lhs, const Matrix &rhs ) {
    lhs *= rhs;
    return lhs;
}

bool Matrix::compare(const double a, const double b, const double epsilon){
    return fabs(a - b) <= epsilon;
}

ostream& operator<<(ostream& os, const Matrix& obj) {
    for (int col = 0; col < obj.get_col_count(); col++) {
        for (int row = 0; row < obj.get_row_count(); row++) {
            os << obj.get_value(col, row) << "\t";
        }
        cout << endl;
    }

    return os;
}

