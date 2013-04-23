#include "Tag.h"

Tag::Tag(string name)
{
    d_name = name;
}

void Tag::addParticle(Mover* particle)
{
    d_particles.push_back(particle);
    particle->addTagNoReciprocal(this);
}

void Tag::addParticleNoReciprocal(Mover* particle)
{
    d_particles.push_back(particle);
}

void Tag::addInteraction(Interaction* i, Tag* t)
{
    d_interactions[i].push_back(t);
}

void Tag::update()
{
}

void Tag::actUpon(Tag* otherTag)
{
    for(auto it_p=d_particles.begin(); it_p != d_particles.end(); it_p++)
    {
        Mover* actor = (*it_p);
        for(auto it_i=d_interactions.begin(); it_i!=d_interactions.end(); it_i++)
        {
            Interaction* interaction = (*it_i);
            otherTag->interact(actor, interaction);
        }
    }
}

void Tag::interact(Mover* actor, Interaction* interaction)
{
    for(auto it_p=d_particles.begin(); it_p!=d_particles.end(); it_p++)
    {
        interaction->interact(actor, (*it_p));
    }
}

void Tag::printParticles()
{
    for(auto it=d_particles.begin(); it != d_particles.end(); it++)
    {
        cout << "particle: " << (*it)->id() << "\n";
    }
    cout << "---\n";
}

string const &Tag::name() const
{
    return d_name;
}
