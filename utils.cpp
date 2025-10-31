#include "utils.hpp"
#include <iostream>
#include <new>
#include <limits>
#include <cstdlib>

double** allocation(unsigned int& line, unsigned int& col) {
    int essaie = 0;
    double** tab2D = nullptr;

    while (essaie < 5 && line > 0 ) {
        try {
            tab2D = new double*[line];
            for (int i = 0; i < line; i++) {
                tab2D[i] = new double[col];
            }
            return tab2D;
        } catch (std::bad_alloc const& e) {
            std::cerr << "Erreur d'allocation...\n";
            std::cerr << e.what() << std::endl;
            std::cout << "nous allons reduire1  4 le nombres de lignes à allouer.\n";
            line -= 4;
            essaie++;
        }
    }
    std::cerr << "Impossible de creer le tableau...MEMOIRE INSSUFISANTE\n";
    exit(EXIT_FAILURE);
}

double* somme_colonne(double** tab2D, const unsigned int line, const unsigned int col) {

    double* result = new double[col]();

    for (unsigned int i = 0; i < col; i++) {
        for (unsigned int j = 0; j < line; j++) {
            result[i] += tab2D[j][i];
        }
    }
    return result;
}
void remplir_tableau(double** tab2D, const unsigned int line, const unsigned int col) {
    for (unsigned int i = 0; i < line; i++) {
        for (unsigned int j = 0; j < col; j++) {
            std::cout << "tab2D[" << i << "][" << j << "] = ";          while (!(std::cin >> tab2D[i][j])) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ">_ ";
            }
        }
    }
}

void delete_tab2D(double*** tab2D, unsigned int line, unsigned int col) {
    for (int i = 0; i < line; i++) {
        delete [] (*tab2D)[i];
    }
    delete [] (*tab2D);
    *tab2D = nullptr;
    std::cout << "tab2D = " << tab2D << std::endl;
}

void display(double* tab, const unsigned int taille) {
    std::cout << "[";
    for (unsigned int i = 0; i < taille; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << "]\n";
}

void display(double** tab2D, const unsigned int line, const unsigned int col) {
    for (unsigned int i = 0; i < line; i++) {
        display(tab2D[i], col);
    }
}
