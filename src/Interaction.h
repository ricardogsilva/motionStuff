#ifndef _OF_INTERACTION
#define _OF_INTERACTION

#include <string>
#include "ofMain.h"
#include "Mover.h"
using namespace std;

class Mover;

class Interaction
{
    string d_actorCondition;
    string d_actedCondition;
    string d_distanceCondition;
    bool d_closestOnly;

    public:

        Interaction();
        virtual void init(string actorCondition, string actedCondition, 
                          string distanceCondition, bool interactWithClosest);
        virtual void interact(Mover* actor, Mover* acted);
        virtual bool evaluateActorCondition(Mover* actor);
        virtual bool evaluateActedCondition(Mover* acted);
        virtual bool evaluateDistanceCondition(Mover* acted);
        virtual void doInteraction(Mover* actor, Mover* acted);
};
#endif
