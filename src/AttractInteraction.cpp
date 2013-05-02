#include "AttractInteraction.h"

AttractInteraction::AttractInteraction()
{}

void AttractInteraction::doInteraction(Mover* actor, Mover* acted)
{
    ofVec2f force = actor->location() - acted->location();
    float distance = ofClamp(force.length(), 5, 25);
    force.normalize();
    float strenght = (d_G * actor->mass() * acted->mass()) / (distance * distance);
    force *= strenght;
    acted->applyForce(force);
}
