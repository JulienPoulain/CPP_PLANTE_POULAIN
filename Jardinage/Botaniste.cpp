#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "Botaniste.h"

// CONSTRUCTEURS

Botaniste::Botaniste() :
    _nom("UNKNOWN"),
    _plantes(),
    _argent(10),
    _engrais(5)
    {}

Botaniste::Botaniste(std::string nom) :
    _nom(nom),
    _plantes(),
    _argent(10),
    _engrais(5)
    {}

Botaniste::~Botaniste() {}

// METHODES

void Botaniste::dormir() {}

void Botaniste::acheter() {}

void Botaniste::vendre() {}

void Botaniste::inspecter(Plante *plante) const {
    plante->afficher();
}

void Botaniste::nourrir(Plante *plante) {
    plante->manger();
}

void Botaniste::arroser(Plante *plante) {
    plante->boire();
}

void Botaniste::tailler(Plante *plante) {
    plante->tailler();
}

void Botaniste::mouche(PlanteCarnivore *planteCarnivore) {
    planteCarnivore->mangerViande();
}

#endif