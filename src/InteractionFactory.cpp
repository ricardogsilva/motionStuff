#include "InteractionFactory.h"

Interaction* InteractionFactory::createInteraction(string name)
{
    Interaction * interaction = NULL;
    if(name.compare("attract") == 0){
        interaction = new AttractInteraction();
    }
    return interaction;
}
