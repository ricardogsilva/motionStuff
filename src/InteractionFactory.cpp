#include "InteractionFactory.h"

Interaction* InteractionFactory::createInteraction(string name)
{
    Interaction * interaction = NULL;
    if(name.compare("attract") == 0)
    {
        interaction = new AttractInteraction();
    } else if(name.compare("color") == 0)
    {
        interaction = new ColorInteraction();
    }
    return interaction;
}
