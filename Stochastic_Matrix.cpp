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

#include "Stochastic_Matrix.hpp"

Stochastic_Matrix::Stochastic_Matrix( const Connectivity_Matrix &connectivity_matrix ) :
        Page_Matrix( connectivity_matrix.get_pages()) {
    vector<vector<double>> to_copy( connectivity_matrix.get_matrix());
    for ( unsigned int i = 0; i < to_copy.size(); ++i ) {
        for ( unsigned int j = 0; j < to_copy.size(); ++j ) {
            matrix[ i ][ j ] = to_copy[ i ][ j ];
        }
    }
    normalize();
}


double Stochastic_Matrix::get_col_val( const unsigned long col ) const {
    double sum = 0;
    for ( unsigned long row = 0; row < row_count; ++row ) {
        sum += matrix[ col ][ row ];
    }
    if ( sum == 0 ) {
        throw std::runtime_error( "zero division" );
    }
    return 1.0 / sum;
}

void Stochastic_Matrix::assign_col_val( const unsigned long col, const double val ) {
    for ( unsigned long row = 0; row < row_count; ++row ) {
        if ( matrix[ col ][ row ] == 1 ) {
            matrix[ col ][ row ] = val;
        }
    }
}

void Stochastic_Matrix::assign_no_link_col_val( const unsigned long col, const double val ) {
    for ( unsigned long row = 0; row < row_count; ++row ) {
        matrix[ col ][ row ] = val;
    }
}

void Stochastic_Matrix::normalize() {
    for ( unsigned long col = 0; col < col_count; ++col ) {
        try {
            double val = get_col_val( col );
            assign_col_val( col, val );
        } catch ( std::runtime_error &e ) {
            assign_no_link_col_val( col, 1.0 / ( double ) row_count );
        }
    }
}
