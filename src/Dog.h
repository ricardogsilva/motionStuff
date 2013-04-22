#ifndef DOG_H
#define DOG_H

#include "Mover.h"


class Dog : public Mover
{
    public:

        void init(float x, float y, float m, float lifespan, float energy_reserve);
        void draw();
};

#endif // DOG_H
