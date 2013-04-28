#include "AttractInteraction.h"

AttractInteraction::AttractInteraction()
{}

void AttractInteraction::doInteraction(Mover* actor, Mover* acted)
{
    acted->arrive(actor->location());
}
