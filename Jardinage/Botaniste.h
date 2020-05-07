#ifndef BOTANISTE_H
#define BOTANISTE_H

#include <iostream>
#include <string>
#include <vector>

#include "Plante.h"

class Botaniste {
    private:
        std::string _nom;
        std::vector<Plante> _plantes;
        int _argent;
        int _engrais;

    public:
        Botaniste();
        Botaniste(std::string nom);
        ~Botaniste();

        void dormir();
        void acheter();
        void vendre();

        void inspecter(Plante *plante) const;
        void nourrir(Plante *plante);
        void arroser(Plante *plante);
        void tailler(Plante *plante);
};

#endif