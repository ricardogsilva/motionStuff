#ifndef _OF_MOVER
#define _OF_MOVER

#include <cmath>
#include "ofMain.h"
#include "Tag.h"
using namespace std;

class Tag;

class Mover {

    static int d_id_counter;
    int d_base_width = 30;
    int d_base_height = 30;
    float d_mass_to_energy_ratio = 2.0 / 5.0;
    float d_energy_to_mass_ratio = 0.5;
    float d_eat_ratio = 4;
    //float d_mass_decay_ratio = 0.1;
    float d_mass_decay_ratio = 0;
    //float d_energy_consumption = 0.1;
    float d_energy_consumption = 0;
    float d_birth_date;
    float d_lifespan;
    float d_age;
    float d_energy_reserve;
    int d_id;
    float d_rotation_angle;
    float d_mass;
    float d_width;
    float d_height;
    float d_max_speed;
    float d_max_steer_force;
    float d_friction_coeff;
    vector <Tag*> d_tags;
    ofColor d_color;
    ofVec2f d_location;
    ofVec2f d_velocity;
    ofVec2f d_acceleration;

    Mover * findClosest(vector<Mover> * targets);
    void updateMovement();

    public:

        void init(float x, float y, float m, ofColor color, float lifespan, float energy_reserve);
        void applyForce(ofVec2f force);
        void addTag(Tag* t);
        void addTagNoReciprocal(Tag* t);
        void arriveFood(Mover * food);
        void arriveClosestFood(vector<Mover> * foods);
        void eat(Mover * food);
        void wander();

        void consumeEnergy();
        void seek(ofVec2f target);

        void drag(float frictionCoeff);
        ofVec2f arrive(ofVec2f target);
        ofVec2f escape(ofVec2f target);
        //ofVec2f seekClosest(vector<Mover> * targets);
        //ofVec2f arriveClosest(vector<Mover> * targets);
        //ofVec2f escapeClosest(vector<Mover> * targets);
        //ofVec2f separate(vector<Mover> movers);
        bool isAlive();
        void checkEdges();
        void reappear();
        void update();
        void draw();

        void setMass(float newMass);
        void setColor(ofColor newColor);

        int const &id() const;
        float const &mass() const;
        float const &width() const;
        float const &height() const;
        float const &age() const;
        float const &lifespan() const;
        float const &friction_coeff() const;
        float const &rotation_angle() const;
        ofColor const &color() const;
        ofVec2f const &location() const;
        ofVec2f const &velocity() const;
        ofVec2f const &acceleration() const;
};

#endif
