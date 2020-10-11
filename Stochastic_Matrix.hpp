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

#ifndef ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP
#define ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP


#include <stdexcept>
#include "Page_Matrix.hpp"
#include "Connectivity_Matrix.hpp"

using namespace std;

class Stochastic_Matrix : public Page_Matrix {
private:
    /**
     * Get the value to assign to every column connection.
     * @param col the column to evaluate
     * @return the value to assign to every column connection
     */
    double get_col_val(int col) const;

    /**
     * Assign value to every connection in column
     * @param col the column to process
     * @param val the value to assign
     */
    void assign_col_val(int col, double val);

    /**
     * Assign the value to every element in column.
     * @param col the column to process
     * @param val the value to assign
     */
    void assign_no_link_col_val(int col, double val);

    void normalize(); //TODO: <Karel> add doc
public:

    /**
     * Construct an instance from the values and pages in the given Connectivity_Matrix.
     *
     * The constructor should perform the following steps:
     *
     * 1 - transform values into importance matrix where the the values are evaluated as such:
     * new_value = old_value / sum(all old_values in column)
     *
     * 2 - transform values into stochastic matrix by assigning the following to any site that
     * is not liked-to by any other page:
     * 1 / number_of_pages
     *
     * The results are the final values in the construction
     *
     * @param connectivity_matrix a Connectivity_Matrix
     */
    explicit Stochastic_Matrix(const Connectivity_Matrix &connectivity_matrix);
};


#endif //ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP
