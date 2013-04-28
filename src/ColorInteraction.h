#ifndef _OF_COLORINTERACTION
#define _OF_COLORINTERACTION

#include "ofMain.h"
#include "Interaction.h"
using namespace std;

class ColorInteraction : public Interaction
{

    public:

        ColorInteraction();
        virtual void doInteraction(Mover* actor, Mover* acted);
        //virtual void undoInteraction(Mover* actor, Mover* acted);
};

#endif
