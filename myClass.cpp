#include "myClass.hpp"
#include <iostream>
#include <new>

Classe::Classe(std::string name, unsigned int size) : nom(name), taille(size) {
    unsigned int i = 0;
    try {
        notes = new double[size]();
    } catch (std::bad_alloc const &e) {
        std::cerr << "Error 1: " << e.what() << "\n";
        try {
            notes = new double[size/2]();
        } catch (std::bad_alloc const &b) {
            std::cerr << "Error 2: " << b.what() << "\n";
        }
    }
}

Classe::Classe() : nom(""), taille(0), notes(nullptr) {}
Classe::~Classe() {
    delete [] notes;    notes = nullptr;
}

Classe* copierClasse(const Classe* maClasse) {
    Classe* newClasse = new Classe();
    if (!newClasse)
        return nullptr;

    newClasse->nom = maClasse->nom;
    newClasse->taille = maClasse->taille;

    if ((newClasse->notes = new double[maClasse->taille]) == nullptr)
        return nullptr;

    return newClasse;
}
void displayClass(const Classe* maClasse) {
    std::cout << "==================";
    std::cout << "\nNom: " << maClasse->nom << "\n";
    std::cout << "taille: " << maClasse->taille << "\n";
    std::cout << "notes: " << maClasse->notes << "\n";
    std::cout << "==================";
}
