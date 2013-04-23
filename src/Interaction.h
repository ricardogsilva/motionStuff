#ifndef _OF_INTERACTION
#define _OF_INTERACTION

#include "ofMain.h"
#include "Mover.h"
using namespace std;

class Mover;

class Interaction
{

    public:

        Interaction();
        virtual void interact(Mover* actor, Mover* acted);
};
#endif
