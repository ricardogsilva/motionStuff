#ifndef _OF_MOVER_SYSTEM
#define _OF_MOVER_SYSTEM

#include <vector>
#include "ofMain.h"
#include "src/Mover.h"
using namespace std;

class MoverSystem {

    int d_mover_id;
    int d_edgeDetection;
    ofVec2f d_start_location;
    vector<Mover> d_movers;

    public:

        void init(float startX, float startY, int numMovers, ofColor color, int edgeDetection);
        void applyForce(ofVec2f force);
        void applyDragForce(float frictionCoeff);
        void seek(ofVec2f target);
        void arrive(ofVec2f target);
        //void seekClosest(vector<Mover> targets);
        //void arriveClosest(vector<Mover> targets);
        void arriveClosestFood(MoverSystem * foods);
        void update();
        void draw();

        //int const &id() const;
        //ofVec2f const &startLocation() const;
        vector<Mover> * movers();
};

#endif
