#include "Interaction.h"

Interaction::Interaction()
{}

void Interaction::init(string actorCondition, string actedCondition,
                       string distanceCondition, bool interactWithClosest)
{
    d_actorCondition = actorCondition;
    d_actedCondition = actedCondition;
    d_distanceCondition = distanceCondition;
    d_closestOnly = interactWithClosest;
}

void Interaction::interact(Mover* actor, Mover* acted)
{
    bool actorOK = evaluateActorCondition(actor);
    bool actedOK = evaluateActedCondition(acted);
    bool distanceOK = evaluateDistanceCondition(acted);
    if(actorOK && actedOK && distanceOK)
    {
        doInteraction(actor, acted);
    }
}

void Interaction::doInteraction(Mover* actor, Mover* acted)
{};

bool Interaction::evaluateActorCondition(Mover* actor)
{
    bool result = true;
    return result;
}

bool Interaction::evaluateActedCondition(Mover* acted)
{
    bool result = true;
    return result;
}

bool Interaction::evaluateDistanceCondition(Mover* acted)
{
    bool result = true;
    return result;
}
