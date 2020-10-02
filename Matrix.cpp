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

#include "Matrix.hpp"

Matrix::Matrix( int cols, int rows ) {

}

Matrix::Matrix( vector<double> initial_values ) {

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
    return *this;
}

Matrix &Matrix::operator++( int ) {
    return <#initializer#>;
}

Matrix &Matrix::operator--() {
    return *this;
}

Matrix &Matrix::operator--( int ) {
    return <#initializer#>;
}

Matrix &Matrix::operator=( const Matrix rhs ) {
    return *this;
}

Matrix &Matrix::operator+=( const Matrix &rhs ) {
    return *this;
}

Matrix &Matrix::operator-=( const Matrix &rhs ) {
    return *this;
}

Matrix &Matrix::operator*=( double constant ) {
    return *this;
}

bool operator==( const Matrix &lhs, const Matrix &rhs ) {
    return false;
}

bool operator!=( const Matrix &lhs, const Matrix &rhs ) {
    return false;
}

Matrix operator+( Matrix lhs, const Matrix &rhs ) {
    return Matrix();
}

Matrix operator-( Matrix lhs, const Matrix &rhs ) {
    return Matrix();
}

Matrix operator*( const Matrix lhs, const Matrix &rhs ) {
    return Matrix();
}
