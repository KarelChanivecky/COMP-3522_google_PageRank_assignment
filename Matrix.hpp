/**
 * 9/25/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * BCIT CST
 * Set O Datacomm
 * COMP - 3522
 *
 * Assignment 1
 */

#ifndef CODE_MATRIX_HPP
#define CODE_MATRIX_HPP

#include <vector>

using namespace std;

class Matrix {
private:
    static constexpr double DEFAULT_VAL{ 0.0 };
    static constexpr int DEFAULT_SIZE{ 1 };
    static constexpr double FLOAT_TOLERANCE{ 1.0 };

    int col_count{};
    int row_count{};
    vector<vector<double>> matrix;
public:

    /**
     * Default constructor.
     *
     * Initializes col_count and row_count to 0. Matrix to new vector
     */
    Matrix() : col_count( DEFAULT_SIZE ), row_count( DEFAULT_SIZE ) {
        matrix.at(0).push_back(DEFAULT_VAL);
    }

    /**
     * Construct an instance with equal number of rows and columns
     * @param square_size an int, the size of the sides
     * TODO @throws exception if arg is <= 0
     */
    Matrix(const int square_size) : col_count(square_size), row_count(square_size) {};

    /**
     * Construct an instance with the passed size
     * @param cols the number of columns
     * @param rows the number of rows
     * TODO @throws exception if any arg is <= 0
     */
    Matrix( int cols, int rows );

    /**
     * Construct an instance where sides are sized to the square root of the size of the passed vector.
     * @param initial_values a vector<double> the initial values to populate
     * TODO @throws exception if size of arg does not have an integer square root
     * TODO ask jeff how the heck do you init this
     */
    Matrix(vector<double>  initial_values);

    /**
     * Construct an instance by copying a given matrix.
     * @param other_matrix a Matrix
     */
    Matrix( const Matrix &other_matrix );

    /**
     * Construct an instance by copying the contents of a given 2d vector of double.
     * @param old_vector
     */
    Matrix( vector<vector<double>> old_vector );

    /**
     * Destroy instance.
     */
    ~Matrix();

    /**
     * Set the given value at the given column and row.
     * @param col an int <= col_count
     * @param row an int <= row_count
     * @param val a double
     * TODO @throws exception if row or col is <= 0
     * @return true if successful, else false
     */
    bool set_value( int col, int row, double val ) {};

    /**
     * Get the value at the given column and row
     * @param col an int <= col_count
     * @param row an int <= row_count
     * TODO @throws exception if any arg is <= 0
     * @return the indicated value
     */
    double get_value( int col, int row ) const;



    /**
     * Set all of the values in the matrix to DEFAULT_VALUE
     */
    void clear();


    /**
     * Get the number of columns.
     * @return the number of columns
     */
    int get_col_count() const;

    /**
     * Get the number of rows.
     * @return the number of rows
     */
    int get_row_count() const;

    /**
     * Evaluate if the given matrices are equal.
     * @param lhs a Matrix
     * @param rhs a Matrix
     * @return true if equal, else false
     */
    friend bool operator==(const Matrix &lhs, const Matrix &rhs );

    /**
     * Evaluate if the given matrices are not equal.
     * @param lhs a Matrix
     * @param rhs a Matrix
     * @return true if not equal, else false
     */
    friend bool operator!=(const Matrix &lhs, const Matrix &rhs );

    /**
     * Increment all values by 1.
     * @return the matrix before incrementing
     */
    Matrix& operator++();

    /**
     * Increment all values by 1.
     * @return the matrix after incrementing
     */
    Matrix& operator++(int);

    /**
     * Decrement all values by 1.
     * @return the matrix before Decrementing
     */
    Matrix& operator--();

    /**
     * Decrement all values by 1.
     * @return the matrix before Decrementing
     */
    Matrix& operator--(int);

    /**
     * Create a copy of the given matrix and return it.
     * @param rhs the matrix to copy
     * @return a copy of the given matrix
     */
    Matrix& operator=(const Matrix rhs);

    /**
     * Increment values by performing matrix addition.
     * @param rhs a Matrix, the matrix to add
     * TODO @throws exception if the given matrix is not the same size as this
     * @return this matrix after the addition
     */
    Matrix& operator+=(const Matrix& rhs);

    /**
     * Perform matrix addition without incrementing the values.
     * @param rhs the matrix to add
     * @param lhs this matrix
     * TODO @throws exception if the given matrix is not the same size as this
     * @return the result of the matrix addition
     */
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);

    /**
     * Increment values by performing matrix subtraction.
     * @param rhs a Matrix, the matrix to subtract
     * TODO @throws exception if the given matrix is not the same size as this
     * @return this matrix after the subtraction
     */
    Matrix& operator-=(const Matrix& rhs);

    /**
     * Perform matrix subtraction without decrementing the values.
     * @param rhs the matrix to subtract
     * @param lhs this matrix
     * TODO @throws exception if the given matrix is not the same size as this
     * @return the result of the matrix subtraction
     */
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);

    /**
     * Multiply by constant.
     * @param constant a double
     * TODO @throws exception if the given matrix does not have the same number of rows as this has columns
     * @return true if successful, else false
     */
    Matrix &operator*=( double constant );

    /**
    * Perform matrix multiplication.
    * @param rhs a Matrix
    * TODO @throws exception if the given matrix does not have the same number of rows as this has columns
    * @return true if successful, else false
    */
    friend Matrix &operator*(const Matrix lhs, const Matrix &rhs );
};


#endif //CODE_MATRIX_HPP
