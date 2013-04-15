#ifndef SPRINGPARTICLE_H
#define SPRINGPARTICLE_H

#include "ofMain.h"
#include "Mover.h"
using namespace std;

class SpringParticle
{
    ofVec2f d_anchor;
    float d_length;
    float d_spring_k = 0.0001;

    public:

    void init(float x, float y, float length);
    void connect(Mover * m);
    void draw();
};

#endif // SPRINGPARTICLE_H
