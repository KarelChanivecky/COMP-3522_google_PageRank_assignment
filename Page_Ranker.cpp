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

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include "Page_Ranker.hpp"

constexpr char INITIAL_PAGE_NAME = 'A';
constexpr unsigned long RANK_MATRIX_COL_COUNT = 1;
constexpr unsigned long RANK_MATRIX_COL_INDEX = 0;
constexpr int OUTPUT_PRECISION = 2;
constexpr int OUTPUT_WIDTH = 5;
constexpr int TO_PERCENT_COEFF = 100;

/**
 * Creates a teleportation matrix.
 *
 * @param side_size int, number of values in a row of the matrix.
 * @return Matrix*
 */
Matrix * create_teleportation_matrix( const unsigned long side_size ) {
    vector<double> teleportationValues;

    for ( unsigned long i = 0; i < side_size * side_size; i++ ) {
        teleportationValues.push_back( 1.0 / ( double ) side_size );
    }
    auto * teleportationMatrix = new Matrix( teleportationValues );

    return teleportationMatrix;
}

/**
 * Forms a transition matrix from a stochastic matrix and a teleportation matrix.
 * @param stochastic_matrix Matrix&
 */
void transform_to_transition( Stochastic_Matrix &stochastic_matrix ) {
    Matrix * teleportation_matrix = create_teleportation_matrix( stochastic_matrix.get_col_count());
    stochastic_matrix *= RANDOM_WALK_PROB;
    *teleportation_matrix *= ( 1 - RANDOM_WALK_PROB );
    stochastic_matrix += *teleportation_matrix;
    delete teleportation_matrix;
}

/**
 * Creates a rank matrix for the Markov process.
 *
 * @param numberOfRows int, number of rows in the matrix
 * @return Matrix*
 */
Matrix * create_rank_matrix( const unsigned long numberOfRows ) {
    auto * rankMatrix = new Matrix( RANK_MATRIX_COL_COUNT, numberOfRows );
    for ( unsigned long i = 0; i < numberOfRows; i++ ) {
        rankMatrix->set_value( RANK_MATRIX_COL_INDEX, i, 1.0 );
    }
    return rankMatrix;
}

/**
 * Performs the Markov process on a transition matrix.
 *
 * @param transition_matrix Matrix&, transition matrix
 * @return Matrix*
 */
Matrix * do_markov_process( Matrix &transition_matrix ) {
    Matrix * rank_matrix = create_rank_matrix( transition_matrix.get_row_count());
    Matrix prior_values( *rank_matrix );
    ( *rank_matrix ) = transition_matrix * ( *rank_matrix );
    while ( *rank_matrix != prior_values ) {
        prior_values = *rank_matrix;
        ( *rank_matrix ) = transition_matrix * ( *rank_matrix );
    }
    return rank_matrix;
}

/**
 * Scales page rankings so they sum to ~1.
 *
 * @param ranks Matrix&
 */
void proportionate_ranks( Matrix &ranks ) {
    double sum = 0;
    for ( unsigned long i = 0; i < ranks.get_row_count(); i++ ) {
        sum += ranks.get_value( RANK_MATRIX_COL_INDEX, i );
    }
    ranks *= ( 1 / sum );
}

void output( Matrix markov_matrix, const vector<string> &page_names ) {
    markov_matrix *= TO_PERCENT_COEFF;
    for ( unsigned long i = 0; i < markov_matrix.get_row_count(); i++ ) {
        double value = markov_matrix.get_value( RANK_MATRIX_COL_INDEX, i );
        string pageName = page_names[ i ];
        cout << "Page " << pageName << ": " << setw( OUTPUT_WIDTH )
             << fixed << setprecision( OUTPUT_PRECISION ) << value << "%" << endl;
    }
}

vector<double> * get_connections( string &filename ) {
    string line;
    ifstream src{ filename };
    auto connections = new vector<double>;
    if ( !src.is_open()) {
        cerr << "could not open file:\n" << strerror(errno) << endl;
        exit( EXIT_FAILURE );
    }
    while ( !src.eof()) {
        getline( src, line );
        istringstream iss{ line };
        int conn;
        iss >> conn;
        while ( !iss.eof()) {
            connections->push_back( conn );
            iss >> conn;
        }
    }
    return connections;
}

vector<string> * assemble_pages( vector<double> &connections ) {
    double number_of_pages = sqrt( connections.size());
    if (( number_of_pages - ( int ) number_of_pages ) != 0 ) {
        throw runtime_error( "File is corrupt!" );
    }
    auto * pages = new vector<string>;
    for ( char i = 0; i < number_of_pages; ++i ) {
        string name;
        name.push_back( INITIAL_PAGE_NAME + i );
        pages->emplace_back( name );
    }
    return pages;
}

Matrix * rank_pages( Stochastic_Matrix &sto_matrix ) {
    transform_to_transition( sto_matrix );
    Matrix * ranks = do_markov_process( sto_matrix );
    proportionate_ranks( *ranks );
    return ranks;
}