#include "World.h"

void World::init(float frictionCoeff)
{
    d_frictionCoeff = frictionCoeff;
}

void World::addParticle(Mover* particle)
{
    d_particles.push_back(particle);
}

void World::addTag(Tag* tag)
{
    d_tags.push_back(tag);
}

Tag* World::getTag(string tagName)
{
    Tag* result = NULL;
    for(auto it=d_tags.begin(); it != d_tags.end(); it++)
    {
        string thisName = (*it)->name();
        if(thisName.compare(tagName) == 0)
        {
            result = (*it);
        }
    }
    return result;
}

void World::applyForce(ofVec2f force)
{}

void World::update()
{
    for(auto it_t=d_tags.begin(); it_t != d_tags.end(); it_t++){
        (*it_t)->update();
    }
    for(auto it_p=d_particles.begin(); it_p != d_particles.end(); it_p++){
        (*it_p)->update();
    }
}

void World::draw()
{
    for(auto it=d_particles.begin(); it != d_particles.end(); it++){
        (*it)->draw();
    }
}

void World::printTags()
{
    for(auto it=d_tags.begin(); it!=d_tags.end(); it++){
        cout << "tag: " << (*it)->name() << "\n";
        (*it)->printParticles();
    }
    cout << "-----\n";
}

vector<Tag*> World::tags()
{
    return d_tags;
}
