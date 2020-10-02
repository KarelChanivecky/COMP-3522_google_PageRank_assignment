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
#ifndef ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP
#define ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP


#include "Page_Matrix.hpp"
#include "Connectivity_Matrix.hpp"

using namespace std;

class Stochastic_Matrix : public Page_Matrix {
private:
    // TODO Stochastic_Matrix.hpp a bunch of private methods that do all the calculations
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


    /**
     * Gets the rankings of the pages.
     *
     * @return a Matrix with 1 column where the value in each index is associated
     * with the respective Page in the pages vector
     */
    Matrix get_rankings() const;
};


#endif //ASSIGNMENT1_V2_STOCHASTIC_MATRIX_HPP
