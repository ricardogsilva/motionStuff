#ifndef OF_WORLD
#define OF_WORLD

#include <unordered_map>
#include "ofMain.h"
#include "MoverSystem.h"
using namespace std;

class World {

    unordered_map<string, MoverSystem> d_populations;

    public:

        void init();
        void addPopulation(MoverSystem population, string name);
        void removePopulation(string name);
        void applyForce(ofVec2f force);
        void update(float frictionCoeff);
        void draw();

        unordered_map<string, MoverSystem> * populations();
};
#endif
