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

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <fstream>
#include "Page_Ranker.hpp"



constexpr int INITIAL_PAGE_NAME = 'A';

#define RANDOM_WALK_PROB 0.85

// TODO comments
Matrix * create_teleportation_matrix( const int side_size) {
    vector<double> teleportationValues;

    for ( int i = 0; i < side_size * side_size; i++) {
        teleportationValues.push_back( 1.0 / side_size);
    }
    auto * teleportationMatrix = new Matrix(teleportationValues);

    return teleportationMatrix;
}

// TODO comments
void transform_to_transition( Stochastic_Matrix& stochastic_matrix) {
    Matrix * teleportation_matrix = create_teleportation_matrix( stochastic_matrix.get_col_count() );
    stochastic_matrix *= RANDOM_WALK_PROB;
    *teleportation_matrix *= ( 1 - RANDOM_WALK_PROB);
    stochastic_matrix += *teleportation_matrix;
    delete teleportation_matrix;

}

Matrix * create_rank_matrix(const int numberOfRows) {
    auto * rankMatrix = new Matrix(1, numberOfRows);
    for (int i = 0; i < numberOfRows; i++) {
        rankMatrix->set_value(0, i, 1.0);
    }
    return rankMatrix;
}

// TODO comments
Matrix * do_markov_process(Matrix& transition_matrix) {
    Matrix * rank_matrix = create_rank_matrix( transition_matrix.get_row_count());
    Matrix prior_values( *rank_matrix);
    (*rank_matrix) = transition_matrix * (*rank_matrix);
    while ( *rank_matrix != prior_values) {
        prior_values = *rank_matrix;
        (*rank_matrix) = transition_matrix * (*rank_matrix);
    }
    return rank_matrix;
}

// TODO comments
void proportionate_ranks(Matrix &ranks) {
    double sum = 0;
    for (int i = 0; i < ranks.get_row_count(); i++) {
        sum += ranks.get_value(0, i);
    }
    ranks *= (1/sum);
}

// TODO comments
void output( const Matrix& markov_matrix, const int n) {
    double sum_of_ranks = 0;
    for (int i = 0; i < n; i++) {
        sum_of_ranks += markov_matrix.get_value( 0, i);
    }

    for (int i = 0; i < n; i++) {
        cout << ( markov_matrix.get_value( 0, i) / sum_of_ranks ) << endl;
    }
}

/**
 * Read connections from file.
 * @param filename the name of the file to read connections from
 * @return a vector of int representing connections
 */
vector<double> * get_connections(string &filename) {
    string line;
    ifstream src{filename};
    auto connections = new vector<double>;
    if (!src.is_open()) {
        cerr << "could not open file:\n" << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    while (!src.eof()) {
        getline(src, line);
        istringstream iss{line};
        int conn;
        iss >> conn;
        while (!iss.eof()) {
            connections->push_back(conn);
            iss >> conn;
        }
    }
    return connections;
}

/**
 * Assemble pages.
 * @param connections the connections to assemble pages from
 * @return a vector of string
 */
vector<string> * assemble_pages(vector<double> &connections) {
    double number_of_pages = sqrt(connections.size());
    if ((number_of_pages - (int) number_of_pages) != 0) {
        throw runtime_error("File is corrupt!");
    }
    auto * pages = new vector<string>;
    for ( int i = 0; i < number_of_pages; ++i ) {
        string name{to_string(INITIAL_PAGE_NAME + i)};
        pages->emplace_back(name);
    }
    return pages;
}

/**
 * Get a Page_Matrix where the values are the rank of the respective pages
 * @param pages the pages to rank
 * @return a Page_Matrix
 */
Matrix * rank_pages(Stochastic_Matrix &sto_matrix) {
    transform_to_transition( sto_matrix);
    Matrix * ranks = do_markov_process( sto_matrix);
    proportionate_ranks(*ranks);
    return ranks;
}