#ifndef FLEUR_CPP
#define FLEUR_CPP

#include "Fleur.h"

// CONSTRUCTEURS

Fleur::Fleur() :
    Plante(), _isEnFleur(false), _isFanee(false) {
        _tauxDeCroissance = 10;
    }

Fleur::Fleur(std::string nom) :
    Plante(nom), _isEnFleur(false), _isFanee(false) {
        _tauxDeCroissance = 10;
    }

Fleur::~Fleur() {}

// METHODES

void Fleur::afficher() const {
    std::cout << _nom << " Sante:" << _sante << "/" << _santeMax << " Hydratee:" << _isArrosee;
    if (_isEnFleur) std::cout << "En fleur";
    else if (_isFanee) std::cout << "Fanée";
    std::cout << std::endl;
}

void Fleur::croitre() {
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

    if (_maturite >= 100) {
        _maturite = 100;
        // Si la fleur n'a pas encore éclot.
        if (!_isEnFleur && !_isFanee) {
            _isEnFleur = true;
            _valeur = _maturite * 2;
        // Si la fleur avait éclot elle se fane.
        } else if (_isEnFleur) {
            _isEnFleur = false;
            _isFanee = true;
            _valeur = _maturite/10;
        }
    }

    // Si la fleur avait éclot elle se fane.
    if (_isEnFleur) {
        _isEnFleur = false;
        _isFanee = true;
        _valeur = _maturite/10;
    }

    _valeur = _maturite;

    _isArrosee = false;
    _isNourrie = false;
    _isTaillee = false;
}

#endif