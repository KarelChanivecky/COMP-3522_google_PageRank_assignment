#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "Page.hpp"
#include "Matrix.hpp"
#include "Connectivity_Matrix.hpp"
#include "Stochastic_Matrix.hpp"

using namespace std;

#define DEFAULT_FILENAME "connectivity.txt"

constexpr int INITIAL_PAGE_NAME = 'A';
constexpr int CONNECTED = 1;
/**
 * Read connections from file.
 * @param filename the name of the file to read connections from
 * @return a vector of int representing connections
 */
vector<int> get_connections(string &filename) {
    string line;
    ifstream src{filename};
    vector<int> connections;
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
            connections.push_back(conn);
            iss >> conn;
        }
    }
}

/**
 * Assemble pages.
 * @param connections the connections to assemble pages from
 * @return a vector of Page
 */
vector<Page> assemble_pages(vector<int> &connections) {
    double number_of_pages = sqrt(connections.size());
    if ((number_of_pages - (int) number_of_pages) != 0) {
        throw runtime_error("File is corrupt!");
    }

    vector<Page> pages;

    for ( int i = 0; i < number_of_pages; ++i ) {
        string name{to_string(INITIAL_PAGE_NAME + i)};
        pages.emplace_back(name);
    }
    for ( int conn_index = 0; conn_index < connections.size(); ++conn_index ) {
        if (connections[conn_index] == CONNECTED) {
            pages[conn_index % (int)number_of_pages].add_link(pages[conn_index / (int) number_of_pages]);
        }
    }
}

/**
 * Get a Page_Matrix where the values are the rank of the respective pages
 * @param pages the pages to rank
 * @return a Page_Matrix
 */
Page_Matrix rank_pages(Stochastic_Matrix &sto_matrix) {

}

void driver() {
    vector<int> connections{get_connections(( string & ) DEFAULT_FILENAME )};
    vector<Page> pages{assemble_pages(connections)};
    Connectivity_Matrix conn_matrix{pages};
    Stochastic_Matrix sto_matrix{conn_matrix};
    Page_Matrix ranks{rank_pages(sto_matrix)};
    cout << ranks << endl;
}

int main() {
    return 0;
}
