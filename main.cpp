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
