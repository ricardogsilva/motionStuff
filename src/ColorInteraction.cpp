#include "ColorInteraction.h"

ColorInteraction::ColorInteraction()
{}

void ColorInteraction::doInteraction(Mover* actor, Mover* acted)
{
    acted->setColor(ofColor(0, 0, 0));
}
