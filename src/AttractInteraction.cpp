#include "AttractInteraction.h"

AttractInteraction::AttractInteraction()
{}

void AttractInteraction::doInteraction(Mover* actor, Mover* acted)
{
    // this is not really an attraction by the actor, but a reaction by the
    // acted. The acted wants to move towards the actor, which is not the
    // intended result.
    ofVec2f desired = actor->location() - acted->location();
    float dist = desired.length();
    desired.normalize();
    float radius = 100;
    if(dist < radius)
    {
        float magnitude = ofMap(dist, 0, radius, 0, acted->maxSpeed());
        desired *= magnitude;
    } else 
    {
        desired *= acted->maxSpeed();
    }
    ofVec2f steer = desired - acted->velocity();
    steer.limit(acted->maxSteerForce());
    acted->applyForce(steer);
}
