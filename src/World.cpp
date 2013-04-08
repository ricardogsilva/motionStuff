#include "World.h"

void World::init()
{}

void World::addPopulation(MoverSystem population, string name)
{
    d_populations[name] = population;
}

void World::removePopulation(string name)
{
    d_populations.erase(name);
}

void World::applyForce(ofVec2f force)
{
    for(auto i=d_populations.begin(); i != d_populations.end(); i++)
    {
        i->second.applyForce(force);
    }
}

void World::update(float frictionCoeff)
{
    for(auto i=d_populations.begin(); i != d_populations.end(); i++)
    {
        i->second.applyDragForce(frictionCoeff);
        i->second.update();
    }
}

void World::draw()
{
    for(auto i=d_populations.begin(); i != d_populations.end(); i++)
    {
        i->second.draw();
    }
}

unordered_map<string, MoverSystem> * World::populations()
{
    return &d_populations;
}
