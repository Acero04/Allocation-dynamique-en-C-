#ifndef __DEF_CLASSE_HPP__
#define __DEF_CLASSE_HPP__

#include <string>
struct Classe {
    std::string nom;
    unsigned int taille;
    double* notes;

    Classe(std::string name, unsigned int size);
    Classe();

    ~Classe();

};


Classe* copierClasse(const Classe* maClasse);
void displayClass(const Classe* maClasse);
#endif
