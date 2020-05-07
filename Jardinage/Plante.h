#ifndef PLANTE_H
#define PLANTE_H

#include <iostream>
#include <string>

class Plante {
    protected:
        std::string _nom;
        int _sante;
        int _santeMax;
        int _maturite;
        int _tauxDeCroissance;
        int _valeur;
        bool _isArrosee;
        bool _isNourrie;
        bool _isTaillee;

    public:
        Plante();
        Plante(std::string nom);
        virtual ~Plante();

        virtual void afficher() const;
        virtual void croitre();
        void boire();
        void manger();
        void tailler();
};

#endif