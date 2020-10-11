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
#include <vector>
#include <sstream>
#include "Matrix.hpp"
#include "Connectivity_Matrix.hpp"
#include "Stochastic_Matrix.hpp"
#include "Page_Ranker.hpp"

using namespace std;

#define DEFAULT_FILENAME "connectivity.txt"

void driver() {
    vector<double> * connections = get_connections(( string & ) DEFAULT_FILENAME );
    vector<string> * pages = assemble_pages(*connections);
    Connectivity_Matrix conn_matrix{*connections, *pages};
    Stochastic_Matrix sto_matrix{conn_matrix};
    Matrix * ranks = rank_pages(sto_matrix); // <--- what's this?
    const int n = connections->size();

    //7. Create teleportation matrix
    Matrix teleportationMatrix = createTeleportationMatrix(n);

    //8. Create transition matrix
    Matrix transitionMatrix = createTransitionMatrix(sto_matrix, teleportationMatrix);

    //9. Create a column matrix rank (size n * 1)
    Matrix rankMatrix = createRankMatrix(n);

    //10. Markov process
    Matrix markovedMatrix = doMarkovProcess(rankMatrix, transitionMatrix);

    //11. And finally.
    output(markovedMatrix, n);

//    cout << *ranks << endl;
    delete connections;
    delete pages;
    delete ranks;
}

int main() {
    driver();
    return 0;
}
