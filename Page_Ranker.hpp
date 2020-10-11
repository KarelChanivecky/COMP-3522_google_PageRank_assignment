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

#ifndef ASSIGNMENT1_V2_PAGE_RANKER_HPP
#define ASSIGNMENT1_V2_PAGE_RANKER_HPP


#include <string>
#include <vector>
#include "Page_Matrix.hpp"
#include "Stochastic_Matrix.hpp"

#define RANDOM_WALK_PROB 0.85

using namespace std;
/**
 * Read connections from file.
 * @param filename the name of the file to read connections from
 * @return a vector of int representing connections
 */
vector<double> * get_connections(string &filename);

/**
 * Assemble pages.
 * @param connections the connections to assemble pages from
 * @return a vector of string
 */
vector<string> * assemble_pages(vector<double> &connections);

/**
 * Get a Page_Matrix where the values are the rank of the respective pages
 * @param pages the pages to rank
 * @return a Page_Matrix
 */
Matrix *rank_pages(Stochastic_Matrix &sto_matrix);

/**
 * Creates a teleportation matrix.
 *
 * @param side_size int, number of values in a row of the matrix.
 * @return Matrix*
 */
Matrix * create_teleportation_matrix( int side_size);

/**
 * Forms a transition matrix from a stochastic matrix and a teleportation matrix.
 * @param stochastic_matrix Matrix&
 */
void transform_to_transition( Stochastic_Matrix& stochastic_matrix);

/**
 * Creates a rank matrix for the Markov process.
 *
 * @param numberOfRows int, number of rows in the matrix
 * @return Matrix*
 */
Matrix* create_rank_matrix(int numberOfRows);

/**
 * Performes the Markov process on a transition matrix.
 *
 * @param transition_matrix Matrix&, transition matrix
 * @return Matrix*
 */
Matrix* do_markov_process(Matrix& transition_matrix);

/**
 * Scales page rankings so they sum to ~1.
 *
 * @param ranks Matrix&
 */
void proportionate_ranks(Matrix& ranks);

/**
 * Outputs results of Google's page ranking algorithm.
 *
 * @param markov_matrix Matrix&, the markov matrix
 */
void output(Matrix &markov_matrix);
#endif //ASSIGNMENT1_V2_PAGE_RANKER_HPP
