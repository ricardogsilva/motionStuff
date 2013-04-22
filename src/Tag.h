#ifndef _OF_TAG
#define _OF_TAG

#include <vector>
#include <string>
#include <iostream>
#include "Mover.h"
#include "Interaction.h"
using namespace std;

class Mover;
class Interaction;

class Tag
{
    string d_name;
    vector <Mover*> d_particles;
    vector <Interaction*> d_interactions;

    public:

        Tag(string name);
        void addParticle(Mover* particle);
        void addParticleNoReciprocal(Mover* particle);
        void addInteraction(Interaction* i);
        void printParticles();
        string const &name() const;
};
#endif
