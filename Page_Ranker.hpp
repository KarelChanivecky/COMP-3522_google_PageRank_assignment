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
vector<double> * get_connections( string &filename );

/**
 * Assemble pages.
 * @param connections the connections to assemble pages from
 * @return a vector of string
 */
vector<string> * assemble_pages( vector<double> &connections );

/**
 * Get a Page_Matrix where the values are the rank of the respective pages
 * @param pages the pages to rank
 * @return a Page_Matrix
 */
Matrix * rank_pages( Stochastic_Matrix &sto_matrix );

/**
 * Outputs results of Google's page ranking algorithm.
 *
 * @param markov_matrix Matrix&, the markov matrix
 * @param the page names corresponding to the ranks
 */
void output( Matrix markov_matrix, const vector<string> &page_names );

#endif //ASSIGNMENT1_V2_PAGE_RANKER_HPP
