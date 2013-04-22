#ifndef OF_WORLD
#define OF_WORLD

#include <vector>
#include <iostream>
#include "ofMain.h"
#include "Mover.h"
#include "Tag.h"
using namespace std;

class World {

    float d_frictionCoeff;
    vector <Mover*> d_particles;
    vector <Tag*> d_tags;

    public:

        void init(float frictionCoeff);
        void addParticle(Mover* particle);
        void addTag(Tag* tag);
        void applyForce(ofVec2f force);
        void update();
        void draw();
        void printTags();
        Tag* getTag(string tagName);

        vector <Tag*> tags();
};
#endif
