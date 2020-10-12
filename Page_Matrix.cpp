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

#include "Page_Matrix.hpp"


Page_Matrix::Page_Matrix( const Page_Matrix &to_copy ) : Matrix( to_copy.pages.size(), to_copy.pages.size()) {
    for ( const auto &page : to_copy.pages ) {
        pages.push_back( page );
    }
}

Page_Matrix::Page_Matrix( const vector<string> &new_pages ) : Matrix( new_pages.size(), new_pages.size()) {
    for ( const auto &page : new_pages ) {
        pages.push_back( page );
    }
}
