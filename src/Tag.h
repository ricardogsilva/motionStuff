#ifndef _OF_TAG
#define _OF_TAG

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "Mover.h"
#include "Interaction.h"
using namespace std;

class Mover;
class Interaction;

class Tag
{
    string d_name;
    vector <Mover*> d_particles;
    unordered_map<Tag*, vector<Interaction*>> d_interactions;

    public:

        Tag(string name);
        void addParticle(Mover* particle);
        void addParticleNoReciprocal(Mover* particle);
        void addInteraction(Tag* t, Interaction* i);
        void printParticles();
        vector<Mover*>* particles();
        unordered_map<Tag*, vector<Interaction*>>* interactions();
        string const &name() const;
};
#endif
