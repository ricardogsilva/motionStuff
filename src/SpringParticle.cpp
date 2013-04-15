#include "SpringParticle.h"

void SpringParticle::init(float x, float y, float length)
{
    d_anchor = ofVec2f(x, y);
    d_length = length;
}

void SpringParticle::connect(Mover * m)
{
    ofVec2f force = m->location() - d_anchor;
    float stretch = force.length() - d_length;
    force.normalize();
    force *= (-1 * d_spring_k * stretch);
    m->applyForce(force);
}

void SpringParticle::draw()
{
    ofSetColor(ofColor(0, 0, 0));
    ofFill();
    ofCircle(d_anchor.x, d_anchor.y, 3);
}
