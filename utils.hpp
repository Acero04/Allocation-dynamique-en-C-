#ifndef __UTILS_HPP__
#define __UTILS_HPP__



double** allocation(unsigned int& line, unsigned int& col);

double* somme_colonne(double** tab2D, const unsigned int line, const unsigned int col);

void remplir_tableau(double** tab2D, const unsigned int line, const unsigned int col);

void delete_tab2D(double*** tab2D, const unsigned int line, const unsigned int col);

void display(double* tab, const unsigned int taille);
void display(double** tab2D, const unsigned int line, const unsigned int col);


#endif
