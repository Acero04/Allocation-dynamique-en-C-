#include "myClass.hpp"
#include <iostream>


int main() {

    Classe* maClasse = new Classe("Terminale C", 100);
    Classe* newClasse = copierClasse(maClasse);

    displayClass(maClasse);
    displayClass(newClasse);

    delete maClasse;    maClasse = nullptr;
    delete newClasse;   newClasse = nullptr;

    return 0;
}

