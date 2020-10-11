/**
 * 10/2/2020
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

#ifndef ASSIGNMENT1_V2_PAGE_MATRIX_HPP
#define ASSIGNMENT1_V2_PAGE_MATRIX_HPP

#include <vector>
#include <string>
#include "Matrix.hpp"

using namespace std;

class Page_Matrix : public Matrix {
protected:
    vector<string> pages;
public:
    /**
     * Default constructor
     */
    Page_Matrix() : Matrix() {}

    /**
     * Construct an instance where the values are evaluated depending on the passed pages.
     *
     * The pages will be associated in the order that they appear in the vector passed:
     *
     * vector = [A, B, C]
     * ->
     *   A  B  C
     * A 0  0  0
     * B 0  0  0
     * C 0  0  0
     *
     * @param new_pages the pages to be associated with the matrix
     */
    explicit Page_Matrix(const vector<string> &new_pages);

    /**
     * Construct a copy.
     * @param to_copy
     */
    Page_Matrix(const Page_Matrix &to_copy);

    /**
     * Get the pages associated with the matrix.
     * @return the pages associated with the matrix
     */
    vector<string> get_pages() const { return pages; }
};


#endif //ASSIGNMENT1_V2_PAGE_MATRIX_HPP
