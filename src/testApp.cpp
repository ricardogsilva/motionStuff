#include "testApp.h"
#include "Mover.h"
#include "Tag.h"

void testApp::setup()
{
    ofSetFrameRate(30);
    ofEnableSmoothing();
    ofBackground(255, 255, 255);
    frictionCoeff = 0.001;

    d_world.init(frictionCoeff);

    Mover* p = new Mover();
    p->init(ofRandomWidth(), ofRandomHeight(), 5, ofColor(0, 255, 0), 30, 20);
    //Mover* p2 = new Mover();
    //p2->init(ofRandomWidth(), ofRandomHeight(), 5, ofColor(0, 255, 0), 30, 20);

    d_world.addParticle(p);
    //d_world.addParticle(p2);

    Tag* bailarinos = new Tag(string("bailarinos"));
    Tag* outra = new Tag(string("outra"));

    d_world.addTag(bailarinos);
    d_world.addTag(outra);

    p->addTag(bailarinos);
    //p2->addTag(bailarinos);

    Interaction* attraction = d_interaction_factory.createInteraction(string("attract"));
    attraction->init(string(""), string(""), string(""), false);
    bailarinos->addInteraction(outra, attraction);

    Interaction* colorInteraction = d_interaction_factory.createInteraction(string("color"));
    colorInteraction->init(string(""), string(""), string(""), false);
    bailarinos->addInteraction(outra, colorInteraction);
}

void testApp::update()
{
    d_world.update();
    d_world.printTags();
}

void testApp::draw()
{
    d_world.draw();
}

void testApp::keyPressed(int key)
{
    if(key==111){ // key 'o'
        Mover* p = new Mover();
        p->init(ofRandomWidth(), ofRandomHeight(), 5, ofColor(0, 200, 200), 30, 20);
        d_world.addParticle(p);
        Tag* t = d_world.getTag("outra");
        t->addParticle(p);
    }
}

void testApp::keyReleased(int key){

}

void testApp::mouseMoved(int x, int y ){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}
