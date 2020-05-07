#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "Plante.h"

// CONSTRUCTEURS

Plante::Plante() :
    _nom("UNKNOWN"),
    _sante(5),
    _santeMax(5),
    _maturite(0),
    _tauxDeCroissance(20),
    _valeur(0),
    _isArrosee(false),
    _isNourrie(false),
    _isTaillee(false)
    {}

Plante::Plante(std::string nom) :
    _nom(nom),
    _sante(5),
    _santeMax(5),
    _maturite(0),
    _tauxDeCroissance(20),
    _valeur(0),
    _isArrosee(false),
    _isNourrie(false),
    _isTaillee(false)
    {}

Plante::~Plante() {}

// METHODES

void Plante::afficher() const {
    std::cout << "Nom:" << _nom << " Sante:" << _sante << "/5 Hydratee:" << _isArrosee << std::endl;
}

void Plante::croitre() {
    // Si la plante est vivante
    if (_sante > 0) {
        // Si la plante a été arrosée elle croît.
        if (_isArrosee) {
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

    _isArrosee = false;
    _isNourrie = false;
    _isTaillee = false;
}

void Plante::boire() {
    if (_isArrosee) {
        _sante -= 1;
    } else {
        _isArrosee = true;
    }
    if (_sante < 0) _sante = 0;
}

void Plante::manger() {
    _isNourrie = true;
}

void Plante::tailler() {
    if (_isTaillee) {
        _isTaillee -= 2;
    } else {
        _isTaillee = true;
    }
    if (_sante < 0) _sante = 0;
}

#endif