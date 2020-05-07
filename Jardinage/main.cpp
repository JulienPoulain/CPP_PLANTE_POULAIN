#include <iostream>

#include "Botaniste.h"
#include "Plante.h"
#include "Fleur.h"
#include "PlanteCarnivore.h"

using namespace std;

int main()
{
    cout << "Hello world" << endl;

    Botaniste *gilbert = new Botaniste("Gilbert");
    Plante *laPlante = new Plante("Plantus");
    Fleur *fleurus = new Fleur("Fleurus");
    PlanteCarnivore *plantusCarnivorus = new PlanteCarnivore("PlantusCarnivorus");

    laPlante->afficher();

    return 0;
}