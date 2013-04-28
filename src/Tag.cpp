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

void Tag::addInteraction(Tag* t, Interaction* i)
{
    d_interactions[t].push_back(i);
}

void Tag::printParticles()
{
    for(auto it=d_particles.begin(); it != d_particles.end(); it++)
    {
        cout << "particle: " << (*it)->id() << "\n";
    }
    cout << "---\n";
}

vector<Mover*>* Tag::particles()
{
    return &d_particles;
}

unordered_map<Tag*, vector<Interaction*>>* Tag::interactions()
{
    return &d_interactions;
}

string const &Tag::name() const
{
    return d_name;
}
