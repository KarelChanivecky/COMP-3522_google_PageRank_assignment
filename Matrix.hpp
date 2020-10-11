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

#ifndef CODE_MATRIX_HPP
#define CODE_MATRIX_HPP

#include <stdexcept>
#include <vector>

using namespace std;

static constexpr double DEFAULT_VAL{ 0.0 };

class Matrix {
private:
    /*
     * Compares two doubles against a threshold.
     */
    static bool compare(double a, double b, double epsilon = FLOAT_TOLERANCE);

    /*
     * Increments every value in a Matrix by 1 or -1.
     */
    Matrix& matrixIncrement(const Matrix &operand, bool operationIsAddition);

    /*
     * Performs an addition or subtraction operation between this matrix and another.
     */
    Matrix& matrixIncrementByAMatrix(const Matrix &operand, bool operationIsAddition);
protected:
    static constexpr int DEFAULT_SIZE{ 1 };
    static constexpr double FLOAT_TOLERANCE{ 0.001f };
    static constexpr double MINIMUM_VALUE {0.0};

    int col_count;
    int row_count;
    vector<vector<double>> matrix;
    friend void matrix_swap( Matrix &lhs, Matrix &rhs); // outer are cols, inner rows
public:

    /**
     * Default constructor.
     *
     * Initializes col_count and row_count to 0. Matrix to new vector
     */
    Matrix() : col_count(DEFAULT_SIZE), row_count(DEFAULT_SIZE) {
        vector<double> v;
        v.push_back(DEFAULT_VAL);
        matrix.push_back(v);
    }

    /**
     * Construct an instance with equal number of rows and columns
     * @param square_size an int, the size of the sides
     */
    explicit Matrix(const int square_size) : col_count(square_size), row_count(square_size) {
        if (square_size <= 0) {
            throw std::invalid_argument("Values for columns and rows must be > 0");
        }
    };

    /**
     * Construct an instance with the passed size
     * @param cols the number of columns
     * @param rows the number of rows
     */
    Matrix( int cols, int rows );

    /**
     * Construct an instance where sides are sized to the square root of the size of the passed vector.
     *
     * The values are then assigned as such:
     *
     * [0, 0, 0, 1, 1, 1, 2, 2, 2]
     *  ->
     * 0  0  0
     * 1  1  1
     * 2  2  2
     *
     * @param initial_values a vector<double> the initial values to populate
     * @throws exception if size of arg does not have an integer square root
     */
    explicit Matrix(const vector<double>&  initial_values);

    /**
     * Construct an instance by copying a given matrix.
     * @param other_matrix a Matrix
     */
    Matrix( const Matrix &other_matrix );

    /**
     * Construct an instance by copying the contents of a given 2d vector of double.
     * @param old_vector
     */
    explicit Matrix( vector<vector<double>> old_vector );

    /**
     * Destroy instance.
     */
    ~Matrix();

    /**
     * Set the given value at the given column and row.
     * @param col an int <= col_count
     * @param row an int <= row_count
     * @param val a double
     * @throws exception if row or col is <= 0
     * @return true if successful, else false
     */
    bool set_value( int col, int row, double val );

    /**
     * Get the value at the given column and row
     * @param col an int <= col_count
     * @param row an int <= row_count
     * @throws exception if any arg is <= 0
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
    int get_col_count () const {return col_count;};

    /**
     * Get the number of rows.
     * @return the number of rows
     */
    int get_row_count() const {return row_count;};

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
    Matrix operator++(int);

    /**
     * Decrement all values by 1.
     * @return the matrix before Decrementing
     */
    Matrix& operator--();

    /**
     * Decrement all values by 1.
     * @return the matrix before Decrementing
     */
    Matrix operator--(int);

    /**
     * Create a copy of the given matrix and return it.
     * @param rhs the matrix to copy
     * @return a copy of the given matrix
     */
    Matrix& operator=(const Matrix rhs);

    /**
     * Increment values by performing matrix addition.
     * @param rhs a Matrix, the matrix to add
     * @throws exception if the given matrix is not the same size as this
     * @return this matrix after the addition
     */
    Matrix& operator+=(const Matrix& rhs);

    /**
     * Perform matrix addition without incrementing the values.
     * @param rhs the matrix to add
     * @param lhs this matrix
     * @throws exception if the given matrix is not the same size as this
     * @return the result of the matrix addition
     */
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);

    /**
     * Increment values by performing matrix subtraction.
     * @param rhs a Matrix, the matrix to subtract
     * @throws exception if the given matrix is not the same size as this
     * @return this matrix after the subtraction
     */
    Matrix& operator-=(const Matrix& rhs);

    /**
     * Perform matrix subtraction without decrementing the values.
     * @param rhs the matrix to subtract
     * @param lhs this matrix
     * @throws exception if the given matrix is not the same size as this
     * @return the result of the matrix subtraction
     */
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);

    /**
     * Multiply by constant.
     * @param constant a double
     * @throws exception if the given matrix does not have the same number of rows as this has columns
     * @return true if successful, else false
     */
    Matrix &operator*=( double constant );

    /**
     * Multiply by another matrix by placing it to the left.
     * @param that another matrix that has the same number of rows as this has columns
     * @throws exception if the requirement for that is not met
     * @return the value of this after the multiplication
     */
    Matrix &operator*=(const Matrix &that);

    /**
    * Perform matrix multiplication.
    * @param rhs a Matrix
    * @throws exception if the given matrix does not have the same number of rows as this has columns
    * @return true if successful, else false
    */
    friend Matrix operator*(Matrix lhs, const Matrix &rhs );

    /**
     * Evaluate if two matrices have the same size
     * @param lhs a Matrix
     * @param rhs a Matrix
     * @return true if both have the same number of rows and the same number of columns
     */
    friend bool sizes_match(const Matrix & lhs, const Matrix &rhs) {
        return lhs.col_count == rhs.col_count && lhs.row_count == rhs.row_count;
    }
};


#endif //CODE_MATRIX_HPP
