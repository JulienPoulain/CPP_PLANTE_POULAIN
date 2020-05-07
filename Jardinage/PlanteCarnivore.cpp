#ifndef PLANTESCARNIVORE_CPP
#define PLANTESCARNIVORE_CPP

#include "PlanteCarnivore.h"

// CONSTRUCTEURS

PlanteCarnivore::PlanteCarnivore() :
    Plante(), _digestion(0) {}

PlanteCarnivore::PlanteCarnivore(std::string nom) :
    Plante(nom), _digestion(0) {}

PlanteCarnivore::~PlanteCarnivore() {}

// METHODES

void PlanteCarnivore::afficher() const {
    std::cout << _nom << " Sante:" << _sante << "/" << _santeMax << " Hydratee:" << _isArrosee;
    if (_digestion > 0) std::cout << "Digère sa mouche";
    else std::cout << "À très faim";
    std::cout << std::endl;
}

void PlanteCarnivore::croitre() {
    // Si la plante est vivante
    if (_sante > 0) {
        // Si la plante a été arrosée elle croît et nourrie.
        if (_isArrosee && (_digestion > 0)) {
            _maturite += _tauxDeCroissance;
            if (_isNourrie) _maturite += 5;
            if (!_isTaillee) _maturite -= 5;
            _sante += 1;
        // Elle n'a pas été arrosée dépérit.
        } else {
            _sante -= 1;
        }
    }
    
    if (_sante > _santeMax) {
        _sante = _santeMax;
    } else if (_sante < 0) {
        _sante = 0;
    }

    if (_maturite > 100) _maturite = 100;

    _valeur = _maturite;

    _digestion -= 1;
    if (_digestion < 0) _digestion = 0;

    _isArrosee = false;
    _isNourrie = false;
    _isTaillee = false;
}

void PlanteCarnivore::mangerViande() {
    _digestion = 7;
}

#endif