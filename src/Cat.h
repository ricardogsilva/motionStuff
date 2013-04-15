#ifndef CAT_H
#define CAT_H

#include "Mover.h"


class Cat : public Mover
{
    public:
        void init(int id, float x, float y, float m, float lifespan, float energy_reserve);
        void draw();
};

#endif // CAT_H
