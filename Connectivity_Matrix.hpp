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

#ifndef ASSIGNMENT1_V2_CONNECTIVITY_MATRIX_HPP
#define ASSIGNMENT1_V2_CONNECTIVITY_MATRIX_HPP

#include <vector>
#include "Page.hpp"
#include "Page_Matrix.hpp"

using namespace std;

class Connectivity_Matrix : public Page_Matrix {
    // TODO create association algorithm
public:
    /**
     * Construct an instance with the passed pages.
     *
     * The constructor will take the page vector and evaluate the connections between all of the passed pages
     * such that in the scenario:
     *
     * A ->[B, C], B -> [A], C ->[]
     *
     * where -> [] is the vector of pages that are linked-to from the page, it produces:
     *
     *   A  B  C
     * A 0  1  0
     * B 1  0  0
     * C 1  0  0
     *
     * @param pages The pages to be associated with rows and columns of the matrix
     */
    Connectivity_Matrix(vector<Page> &pages);

    /**
     * Get the pages associated with rows and columns of the matrix.
     * @return the pages associated with rows and columns of the matrix.
     */
    vector<Page> get_pages() const { return pages; }
};


#endif //ASSIGNMENT1_V2_CONNECTIVITY_MATRIX_HPP
