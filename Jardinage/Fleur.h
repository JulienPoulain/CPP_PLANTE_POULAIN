#ifndef FLEUR_H
#define FLEUR_H

#include "Plante.h"

class Fleur : public Plante {
    private:
        bool _isEnFleur;
        bool _isFanee;

    public:
        Fleur();
        Fleur(std::string nom);
        virtual ~Fleur();

        virtual void afficher() const;
        virtual void croitre();
};

#endif