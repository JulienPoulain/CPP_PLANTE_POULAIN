#ifndef PLANTECARNIVORE_H
#define PLANTECARNIVORE_H

#include "Plante.h"

class PlanteCarnivore : public Plante {
    private:
        int _digestion;

    public:
        PlanteCarnivore();
        PlanteCarnivore(std::string nom);
        virtual ~PlanteCarnivore();

        virtual void afficher() const;
        virtual void croitre();
        void mangerViande();
};

#endif