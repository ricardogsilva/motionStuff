#ifndef _OF_ATTRACTINTERACTION
#define _OF_ATTRACTINTERACTION

#include "Interaction.h"
using namespace std;

class AttractInteraction : public Interaction
{
    float d_G = 1;

    public:

        AttractInteraction();
        virtual void doInteraction(Mover* actor, Mover* acted);
};

#endif
