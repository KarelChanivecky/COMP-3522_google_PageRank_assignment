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

#include "Page_Ranker.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <fstream>



constexpr int INITIAL_PAGE_NAME = 'A';

/**
 * Read connections from file.
 * @param filename the name of the file to read connections from
 * @return a vector of int representing connections
 */
vector<double> * get_connections(string &filename) {
    string line;
    ifstream src{filename};
    auto connections = new vector<int>;
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
}

/**
 * Get a Page_Matrix where the values are the rank of the respective pages
 * @param pages the pages to rank
 * @return a Page_Matrix
 */
Page_Matrix * rank_pages(Stochastic_Matrix &sto_matrix) {

}