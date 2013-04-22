#include "Dog.h"

void Dog::init(float x, float y, float m, float lifespan, float energy_reserve)
{
    Mover::init(x, y, m, ofColor(220, 164, 101), lifespan, energy_reserve);
}

void Dog::draw()
{
    ofSetColor(color());
    ofFill();
    ofPushMatrix();
    ofTranslate(ofPoint(location().x, location().y));
    ofRotate(ofRadToDeg(rotation_angle()));
    ofCircle(0, 0, width()/2);
    ofCircle(width()/2 * cos(ofDegToRad(30)), width()/2 * sin(ofDegToRad(30)), width()/5);
    ofCircle(width()/2 * cos(ofDegToRad(330)), width()/2 * sin(ofDegToRad(330)), width()/5);
    //ofPoint p1 = ofPoint(width()/2 * cos(ofDegToRad(160)), width()/2 * sin(ofDegToRad(120)));
    //ofPoint p2 = ofPoint(width()/2 * cos(ofDegToRad(200)), width()/2 * sin(ofDegToRad(240)));
    //ofPoint p3 = ofPoint(width()/2 * cos(ofDegToRad(0)), width()/2 * sin(ofDegToRad(0)));
    //ofTriangle(p1, p2, p3);
    ofPopMatrix();
}
