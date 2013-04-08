#include "MoverSystem.h"

void MoverSystem::init(float startX, float startY, int numMovers, ofColor color, int edgeDetection)
{
    d_edgeDetection = edgeDetection;
    d_mover_id = 0;
    d_start_location = ofVec2f(startX, startY);
    for(int i=0; i < numMovers; i++)
    {
        Mover m = Mover();
        //ofColor color(250, 0, 0, 127);
        m.init(d_mover_id, ofRandomWidth(), ofRandomHeight(), 10 + ofRandom(50), color, 20.0, 20.0);
        d_mover_id++;
        d_movers.push_back(m);
    }
}

void MoverSystem::applyForce(ofVec2f force)
{
    for(int i=0; i < d_movers.size(); i++)
    {
        d_movers[i].applyForce(force);
    }
}

void MoverSystem::applyDragForce(float frictionCoeff)
{
    ofVec2f dragForce;
    for(int i=0; i < d_movers.size(); i++)
    {
        dragForce = d_movers[i].drag(frictionCoeff);
        d_movers[i].applyForce(dragForce);
    }
}

void MoverSystem::seek(ofVec2f target)
{
    ofVec2f steerForce;
    for(int i=0; i < d_movers.size(); i++)
    {
        steerForce = d_movers[i].seek(target);
        d_movers[i].applyForce(steerForce);
    }
}


void MoverSystem::arrive(ofVec2f target)
{
    ofVec2f steerForce;
    for(int i=0; i < d_movers.size(); i++)
    {
        steerForce = d_movers[i].arrive(target);
        d_movers[i].applyForce(steerForce);
    }
}

/*
 *
 * Implement the following methods:
 * seekBiggest()
 * seekFemale()
 * Implement a search() method that allows for the definition of different
 * types of methods to subset the targets input, according to distance,
 * visibility, etc... This might be a better way to filter only the big or the
 * females
 */
//void MoverSystem::seekClosest(vector<Mover> targets)
//{
//    for(int i=0; i < d_movers.size(); i++)
//    {
//        ofVec2f steerForce = d_movers[i].seekClosest(targets);
//        d_movers[i].applyForce(steerForce);
//    }
//}

//void MoverSystem::arriveClosest(vector<Mover> targets)
//{
//    for(int i=0; i < d_movers.size(); i++)
//    {
//        ofVec2f steerForce = d_movers[i].arriveClosest(targets);
//        d_movers[i].applyForce(steerForce);
//    }
//}

void MoverSystem::arriveClosestFood(MoverSystem * foods)
{
    //vector<Mover> * movers = &(foods->movers());
    vector<Mover> * movers = foods->movers();
    for(int i=0; i < d_movers.size(); i++)
    {
        d_movers[i].arriveClosestFood(movers);
    }
}

void MoverSystem::update()
{
    //for(int i=0; i < d_movers.size(); i++)
    for(int i=d_movers.size()-1; i >= 0; i--)
    {
        if(d_movers[i].isAlive()){
            d_movers[i].update();
            if(d_edgeDetection == 0)
            {
                d_movers[i].checkEdges();
            } else if(d_edgeDetection == 1)
            {
                d_movers[i].reappear();
            }
        } else
        {
            d_movers.erase(d_movers.begin() + i);
        }
    }
}

void MoverSystem::draw()
{
    for(int i=0; i < d_movers.size(); i++)
    {
        d_movers[i].draw();
    }
}

vector<Mover> * MoverSystem::movers()
{
    return &d_movers;
}
