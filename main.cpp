#include <iostream>
#include <vector>
#include <sstream>
#include "Matrix.hpp"
#include "Connectivity_Matrix.hpp"
#include "Stochastic_Matrix.hpp"
#include "Page_Ranker.hpp"

using namespace std;

#define DEFAULT_FILENAME "connectivity.txt"
#define RANDOM_WALK_PROB 0.85

Matrix createTeleportationMatrix(const int n) {
    vector<double> teleportationValues;

    for (int i = 0; i < n; i++) {
        teleportationValues.push_back((double) 1 / n);
    }
    Matrix teleportationMatrix(teleportationValues);

    return teleportationMatrix;
}

Matrix createTransitionMatrix(Matrix& stochasticMatrix, Matrix& teleportationMatrix) {
    stochasticMatrix *= RANDOM_WALK_PROB;
    teleportationMatrix *= (1 - RANDOM_WALK_PROB);

    return stochasticMatrix + teleportationMatrix;
}

Matrix createRankMatrix(const int numberOfRows) {
    Matrix rankMatrix(1, numberOfRows);
    for (int i = 0; i < numberOfRows; i++) {
        rankMatrix.set_value(1, i, 1.0);
    }

    return rankMatrix;
}

Matrix& doMarkovProcess(Matrix& rankMatrix, Matrix& transitionMatrix) {
    Matrix priorValues(rankMatrix);

    rankMatrix *= transitionMatrix;
    while (rankMatrix != priorValues) {
        priorValues = rankMatrix; // Todo: Will this make an alias or a copy?
        rankMatrix *= transitionMatrix;
    }

    return rankMatrix;
}

void output(const Matrix& markovedMatrix, const int n) {
    double sumOfRanks = 0;
    for (int i = 0; i < n; i++) {
        sumOfRanks += markovedMatrix.get_value(1, i);
    }

    for (int i = 0; i < n; i++) {
        cout << ( markovedMatrix.get_value(1, i) / sumOfRanks ) << endl;
    }
}

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
