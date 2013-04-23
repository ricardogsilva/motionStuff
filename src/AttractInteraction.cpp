#include "AttractInteraction.h"

AttractInteraction::AttractInteraction()
{}

void AttractInteraction::interact(Mover* actor, Mover* acted)
{
    acted->arrive(actor->location());
}
