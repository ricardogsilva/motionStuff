#include "testApp.h"

void testApp::setup()
{
    ofSetFrameRate(30);
    ofEnableSmoothing();
    ofBackground(255, 255, 255);
    frictionCoeff = 0.001;

    MoverSystem reds;
    MoverSystem blacks;
    reds.init(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 2, ofColor(255, 0, 0, 100), 0);
    blacks.init(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 10, ofColor(0, 0, 0, 100), 0);
    d_world.addPopulation(reds, "reds");
    d_world.addPopulation(blacks, "blacks");
}

void testApp::update()
{
    //ofVec2f force = ofVec2f(0.02, 0);
    //d_world.applyForce(force);
//    reds.arriveClosestFood(&blacks);
//    reds.applyDragForce(frictionCoeff);
//    blacks.applyDragForce(frictionCoeff);
//    reds.update();
//    blacks.update();
    unordered_map<string, MoverSystem> * pops = d_world.populations();
    MoverSystem * reds = &((*pops)["reds"]);
    MoverSystem * blacks = &((*pops)["blacks"]);
    reds->arriveClosestFood(blacks);
    Mover * the_red = &((*reds->movers())[0]);
    printf("red rotation: %5.2f\t", the_red->rotation_angle());
    printf("age: %5.2f\t", the_red->age());
    printf("lifespan: %5.2f\t", the_red->lifespan());
    printf("mass: %5.2f\t", the_red->mass());
    printf("isAlive: %i\n", the_red->isAlive());
    //printf("reds: %i\n", reds->movers()->size());
    d_world.update(frictionCoeff);
}

void testApp::draw()
{
    d_world.draw();
}

void testApp::keyPressed(int key)
{}

//void testApp::setup(){
//    ofSetFrameRate(30);
//    ofBackground(255, 255, 255);
//    frictionCoeff = 0.001;
//    enableDownForce = false;
//    enableUpForce = false;
//    enableLeftForce = false;
//    enableRightForce = false;
//    enableSeek = false;
//    enableEscape = false;
//    int numMovers = 200;
//    for(int i = 0; i < numMovers; i++)
//    {
//        Mover m = Mover();
//        //ofColor color(ofRandom(256), ofRandom(256), ofRandom(256), 10);
//        ofColor color(250, 0, 0, 127);
//        m.init(i, ofRandomWidth(), ofRandomHeight(), 10 + ofRandom(50), color);
//        d_i++;
//        d_movers.push_back(m);
//    }
//    int numAttractors = 10;
//    for(int i = 0; i < numAttractors; i++)
//    {
//        Mover m = Mover();
//        //ofColor color(ofRandom(256), ofRandom(256), ofRandom(256), 10);
//        ofColor color(0, 0, 0, 127);
//        m.init(i, ofRandomWidth(), ofRandomHeight(), 10 + ofRandom(50), color);
//        d_i++;
//        d_attractors.push_back(m);
//    }
//}
//
//void testApp::update(){
//    ofVec2f downForce = ofVec2f(0, 0.02);
//    ofVec2f upForce = ofVec2f(0, -0.02);
//    ofVec2f leftForce = ofVec2f(-0.02, 0);
//    ofVec2f rightForce = ofVec2f(0.02, 0);
//    ofVec2f mousePos = ofVec2f(mouseX, mouseY);
//    for(int i = 0; i < d_attractors.size(); i++)
//    {
//        d_attractors[i].applyForce(ofVec2f(0.02, 0));
//        ofVec2f escapeForce = d_attractors[i].escapeClosest(d_movers);
//        d_attractors[i].applyForce(escapeForce);
//        ofVec2f separateAttractorForce = d_attractors[i].separate(d_attractors);
//        d_attractors[i].applyForce(separateAttractorForce);
//        ofVec2f separateMoverForce = d_attractors[i].separate(d_movers);
//        d_attractors[i].applyForce(separateMoverForce);
//        ofVec2f drag = d_attractors[i].drag(frictionCoeff);
//        d_attractors[i].applyForce(drag);
//        d_attractors[i].update();
//        //d_attractors[i].checkEdges();
//        d_attractors[i].reappear();
//
//    }
//    for(int i = 0; i < d_movers.size(); i++)
//    {
//        if(enableDownForce)
//        {
//            d_movers[i].applyForce(downForce);
//        }
//        if(enableUpForce)
//        {
//            d_movers[i].applyForce(upForce);
//        }
//        if(enableLeftForce)
//        {
//            d_movers[i].applyForce(leftForce);
//        }
//        if(enableRightForce)
//        {
//            d_movers[i].applyForce(rightForce);
//        }
//        if(enableSeek)
//        {
//            //ofVec2f steerForce = d_movers[i].seek(mousePos);
//            ofVec2f steerForce = d_movers[i].seekClosest(d_attractors);
//            d_movers[i].applyForce(steerForce);
//        }
//        if(enableEscape)
//        {
//            ofVec2f steerForce = d_movers[i].escape(mousePos);
//            d_movers[i].applyForce(steerForce);
//        }
//        ofVec2f separateForce = d_movers[i].separate(d_movers);
//        d_movers[i].applyForce(separateForce);
//        ofVec2f separateAttractorForce = d_movers[i].separate(d_attractors);
//        d_movers[i].applyForce(separateAttractorForce);
//        ofVec2f drag = d_movers[i].drag(frictionCoeff);
//        d_movers[i].applyForce(drag);
//        d_movers[i].update();
//        //d_movers[i].checkEdges();
//        d_movers[i].reappear();
//    }
//}
//
//void testApp::draw(){
//    for(int i = 0; i < d_movers.size(); i++)
//    {
//        d_movers[i].draw();
//    }
//    for(int i = 0; i < d_attractors.size(); i++)
//    {
//        d_attractors[i].draw();
//    }
//}
//
//void testApp::keyPressed(int key){
//    if(key==119) // w key
//    {
//        enableUpForce = !enableUpForce;
//    } else if(key==115) // s key
//    {
//        enableDownForce = !enableDownForce;
//    } else if(key==97) // a key
//    {
//        enableLeftForce = !enableLeftForce;
//    } else if(key==100) // d key
//    {
//        enableRightForce = !enableRightForce;
//    } else if(key==102) // f key
//    {
//        enableSeek = true;
//        enableEscape = false;
//    } else if(key==103) // g key
//    {
//        enableEscape = true;
//        enableSeek = false;
//    } else if(key==104) // h key
//    {
//        enableEscape = false;
//        enableSeek = false;
//    }
//}

void testApp::keyReleased(int key){

}

void testApp::mouseMoved(int x, int y ){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){
    //Mover m = Mover();
    ////ofColor color(ofRandom(256), ofRandom(256), ofRandom(256), 10);
    //ofColor color(250, 0, 0, 127);
    //d_i++;
    //m.init(d_i, ofRandomWidth(), ofRandomHeight(), 10 + ofRandom(50), color);
    //d_movers.push_back(m);
}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}
