#include "utils.hpp"
#include <iostream>


int main() {
    unsigned int line = 3, col = 4;    //col = ++line
    double** tab2D = allocation(line, col);

    remplir_tableau(tab2D, line, col);

    double* final = somme_colonne(tab2D, line, col);

    display(tab2D, line, col);
    std::cout << "\n\n";
    display(final, col);


    delete [] final;    final = nullptr;
    delete_tab2D(&tab2D, line, col);

    return 0;
}

