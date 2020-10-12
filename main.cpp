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

#include <vector>
#include "Matrix.hpp"
#include "Connectivity_Matrix.hpp"
#include "Stochastic_Matrix.hpp"
#include "Page_Ranker.hpp"

using namespace std;

#define DEFAULT_FILENAME "../connectivity.txt"

void driver() {
    string filename = DEFAULT_FILENAME;
    vector<double> * connections = get_connections( filename );
    vector<string> * pages = assemble_pages( *connections );
    Connectivity_Matrix conn_matrix{ *connections, *pages };
    Stochastic_Matrix sto_matrix{ conn_matrix };
    Matrix * ranks = rank_pages( sto_matrix );
    output( *ranks, sto_matrix.get_pages());
    delete connections;
    delete pages;
    delete ranks;
}

int main() {
    driver();
    return 0;
}


