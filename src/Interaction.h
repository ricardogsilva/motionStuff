#ifndef _OF_INTERACTION
#define _OF_INTERACTION

#include "ofMain.h"
#include "Mover.h"

class Mover;

class Interaction
{
    Interaction();
    virtual void interact(Mover* actor, Mover* acted);
};
#endif
