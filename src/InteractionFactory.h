#ifndef _OF_INTERACTION_FACTORY
#define _OF_INTERACTION_FACTORY

#include <string>
#include "Interaction.h"
#include "AttractInteraction.h"
using namespace std;

class InteractionFactory
{
    public:

        static Interaction* createInteraction(string name);
};

#endif
